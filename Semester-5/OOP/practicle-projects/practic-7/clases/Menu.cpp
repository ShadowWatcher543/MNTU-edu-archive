#include "Menu.h"

namespace Program {

    double Menu::randomDouble(double min, double max) {
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(generator);
    }

    double Menu::randomDouble() {
        std::uniform_real_distribution<double> distribution(0.0, 10.0);
        return distribution(generator);
    }

    void Menu::clearConsole() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void Menu::showAnswer(std::string* currentMenuMessage) {
        if (!currentMenuMessage->empty()) {
            std::cout << *currentMenuMessage << "\n\n";
            currentMenuMessage->clear();
        }
    }

    void Menu::clearInputBuffer() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double Menu::getDoubleInput(const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cout << "Некоректний ввід. Будь ласка, введіть число.\n";
                std::cin.clear();
                clearInputBuffer();
            } else {
                clearInputBuffer();
                return value;
            }
        }
    }

    int Menu::getIntInput(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cout << "Некоректний ввід. Будь ласка, введіть ціле число.\n";
                std::cin.clear();
                clearInputBuffer();
            } else {
                clearInputBuffer();
                return value;
            }
        }
    }

    void Menu::drawInputForm(const std::string& title, const std::vector<std::string>& fields, const std::vector<std::string>& values, int activeIndex) {
        clearConsole();
        std::cout << "=== " << title << " ===\n\n";
        for (size_t i = 0; i < fields.size(); ++i) {
            if (i < activeIndex) {
                std::cout << " [v] " << fields[i] << ": " << values[i] << "\n";
            } else if (i == activeIndex) {
                std::cout << " [X] " << fields[i] << ": [?] <--\n";
            } else {
                std::cout << " [ ] " << fields[i] << ": ...\n";
            }
        }
        std::cout << "\n";
    }

    std::vector<double> Menu::fillInputForm(const std::string& title, const std::vector<std::string>& fields) {
        std::vector<std::string> values(fields.size(), "");
        std::vector<double> results(fields.size(), 0.0);
        for (size_t i = 0; i < fields.size(); ++i) {
            drawInputForm(title, fields, values, i);
            results[i] = getDoubleInput("Введіть " + fields[i] + ": ");
            values[i] = std::to_string(results[i]);
        }
        return results;
    }

    // --- ОНОВЛЕНЕ: Пошук виводить меню, шукає об'єкти та повертає список їх ID ---
    std::vector<int> Menu::performSearch(bool& isCancelled) {
        std::vector<int> foundIds;
        isCancelled = false;

        std::cout << "1. Всі об'єкти\n";
        std::cout << "2. Пошук за ID\n";
        std::cout << "3. Фільтр за типом\n";
        std::cout << "4. Фільтр за координатами\n";
        std::cout << "q. Назад\n";
        std::cout << "Ваш вибір: ";

        char filterChoice;
        std::cin >> filterChoice;
        clearInputBuffer();

        clearConsole();

        if (filterChoice == 'q') {
            isCancelled = true;
            return foundIds;
        }

        if (filterChoice < '1' || filterChoice > '4') {
            std::cout << "[!] Некоректний вибір.\n";
            isCancelled = true;
            return foundIds;
        }

        if (objectsList->empty()) {
            std::cout << "[!] Список об'єктів порожній.\n";
            return foundIds;
        }

        switch (filterChoice) {
            case '1': { // Всі об'єкти
                std::cout << "[!] Всі об'єкти:\n\n";
                for (Object* item : *objectsList) {
                    item->showInfo();
                    foundIds.push_back(item->getId());
                }
                break;
            }
            case '2': { // За ID
                int searchId = getIntInput("Введіть ID об'єкта для пошуку: ");
                for (Object* item : *objectsList) {
                    if (item->getId() == searchId) {
                        std::cout << "[!] Знайдено:\n" << item->getInfo() << "\n";
                        foundIds.push_back(item->getId());
                        break;
                    }
                }
                break;
            }
            case '3': { // За типом (Підменю)
                clearConsole();
                std::cout << "--- Фільтр за типом ---\n";
                std::cout << "1. Базові об'єкти\n2. Сфери\n3. Звичайні Піраміди\n4. Трикутні Піраміди\n5. Чотирикутні Піраміди\nВаш вибір: ";
                char tChoice; std::cin >> tChoice; clearInputBuffer();

                for (Object* item : *objectsList) {
                    bool match = false;
                    if (tChoice == '1' && typeid(*item) == typeid(Object)) match = true;
                    else if (tChoice == '2' && dynamic_cast<Sphere*>(item)) match = true;
                    else if (tChoice == '3' && typeid(*item) == typeid(Pyramid)) match = true;
                    else if (tChoice == '4' && dynamic_cast<TriangularPyramid*>(item)) match = true;
                    else if (tChoice == '5' && dynamic_cast<QuadrangularPyramid*>(item)) match = true;

                    if (match) {
                        item->showInfo();
                        foundIds.push_back(item->getId());
                    }
                }
                break;
            }
            case '4': { // За координатами (Підменю + форма)
                std::vector<std::string> f = {"Мінімальне значення X/Y/Z", "Максимальне значення X/Y/Z"};
                std::vector<double> v = fillInputForm("Фільтр за діапазоном координат", f);
                double minV = v[0], maxV = v[1];

                for (Object* item : *objectsList) {
                    if (item->getX() >= minV && item->getX() <= maxV &&
                        item->getY() >= minV && item->getY() <= maxV &&
                        item->getZ() >= minV && item->getZ() <= maxV) {
                        item->showInfo();
                        foundIds.push_back(item->getId());
                    }
                }
                break;
            }
        }

        if (foundIds.empty()) {
            std::cout << "[!] За вашим запитом нічого не знайдено.\n";
        } else {
            std::cout << "Знайдено об'єктів: " << foundIds.size() << "\n";
        }

        return foundIds;
    }

    // --- ОНОВЛЕНЕ: Підменю для масового створення ---
    std::string Menu::massCreateMenu() {
        clearConsole();
        std::cout << "--- Масове створення об'єктів (Генератор) ---\n";
        std::cout << "1. Базові об'єкти\n";
        std::cout << "2. Сфери\n";
        std::cout << "3. Звичайні піраміди\n";
        std::cout << "4. Трикутні піраміди\n";
        std::cout << "5. Чотирикутні піраміди\n";
        std::cout << "q. Назад\n";
        std::cout << "Ваш вибір: ";
        char typeChoice; std::cin >> typeChoice; clearInputBuffer();

        if (typeChoice == 'q') return "[!] Масове створення скасовано.";
        if (typeChoice < '1' || typeChoice > '5') return "[!] Некоректний вибір типу.";

        // Окреме підменю для кількості
        clearConsole();
        std::cout << "--- Кількість об'єктів ---\n";
        int count = getIntInput("Скільки об'єктів створити? (>0): ");
        if (count <= 0) return "[!] Кількість має бути більшою за 0.";

        // Окреме підменю для способу генерації
        clearConsole();
        std::cout << "--- Спосіб генерації характеристик ---\n";
        std::cout << "1. Однакові для всіх (ручний ввід параметрів)\n";
        std::cout << "2. Випадкові в стандартному діапазоні (0.0 - 10.0)\n";
        std::cout << "3. Випадкові в кастомному діапазоні (ввід меж)\n";
        std::cout << "q. Назад\n";
        std::cout << "Ваш вибір: ";
        char genChoice; std::cin >> genChoice; clearInputBuffer();

        if (genChoice == 'q') return "[!] Масове створення скасовано.";
        if (genChoice < '1' || genChoice > '3') return "[!] Некоректний спосіб генерації.";

        std::vector<std::string> baseFields = {"Координата X", "Координата Y", "Координата Z"};
        std::vector<std::string> customFields = {"Min X", "Max X", "Min Y", "Max Y", "Min Z", "Max Z"};

        if (typeChoice == '2') {
            baseFields.push_back("Радіус");
            customFields.insert(customFields.end(), {"Min Радіус", "Max Радіус"});
        }
        else if (typeChoice == '3') {
            baseFields.push_back("Висота");
            customFields.insert(customFields.end(), {"Min Висота", "Max Висота"});
        }
        else if (typeChoice == '4') {
            baseFields.insert(baseFields.end(), {"Висота", "Площа основи"});
            customFields.insert(customFields.end(), {"Min Висота", "Max Висота", "Min Площа", "Max Площа"});
        }
        else if (typeChoice == '5') {
            baseFields.insert(baseFields.end(), {"Висота", "Довжина", "Ширина"});
            customFields.insert(customFields.end(), {"Min Висота", "Max Висота", "Min Довжина", "Max Довжина", "Min Ширина", "Max Ширина"});
        }

        std::vector<double> vals;
        if (genChoice == '1') vals = fillInputForm("Ручний ввід однакових параметрів", baseFields);
        else if (genChoice == '3') vals = fillInputForm("Кастомний діапазон генерації", customFields);

        for (int i = 0; i < count; ++i) {
            double x, y, z, p1=0, p2=0, p3=0;

            if (genChoice == '1') {
                x=vals[0]; y=vals[1]; z=vals[2];
                if(vals.size()>3) p1=vals[3]; if(vals.size()>4) p2=vals[4]; if(vals.size()>5) p3=vals[5];
            }
            else if (genChoice == '2') {
                x=randomDouble(); y=randomDouble(); z=randomDouble();
                p1=randomDouble(); p2=randomDouble(); p3=randomDouble();
            }
            else if (genChoice == '3') {
                x=randomDouble(vals[0], vals[1]); y=randomDouble(vals[2], vals[3]); z=randomDouble(vals[4], vals[5]);
                if(vals.size()>6) p1=randomDouble(vals[6], vals[7]);
                if(vals.size()>8) p2=randomDouble(vals[8], vals[9]);
                if(vals.size()>10) p3=randomDouble(vals[10], vals[11]);
            }

            Object::Point3D pt{x, y, z};
            if (typeChoice == '1') objectsList->push_back(new Object(pt));
            else if (typeChoice == '2') objectsList->push_back(new Sphere(pt, p1));
            else if (typeChoice == '3') objectsList->push_back(new Pyramid(pt, p1));
            else if (typeChoice == '4') objectsList->push_back(new TriangularPyramid(pt, p1, p2));
            else if (typeChoice == '5') objectsList->push_back(new QuadrangularPyramid(pt, p1, p2, p3));
        }

        return "[!] Успішно згенеровано " + std::to_string(count) + " об'єктів.";
    }

    std::string Menu::createPyramidSubMenu() {

        std::string message = "[!] Ви обрали 2. Створення піраміди.";
        clearConsole();
        showAnswer(&message);

        std::cout << "\n--- Створити Піраміду ---\n";
        std::cout << "1. Звичайна Піраміда\n";
        std::cout << "2. Трикутна Піраміда\n";
        std::cout << "3. Чотирикутна Піраміда\n";
        std::cout << "q. Назад\n";
        std::cout << "Ваш вибір: ";
        char pyramidChoice; std::cin >> pyramidChoice; clearInputBuffer();

        if (pyramidChoice == 'q') return "[!] Створення піраміди скасовано.";

        std::vector<std::string> fields;
        std::vector<double> vals;

        switch (pyramidChoice) {
            case '1': {
                fields = {"Координата X", "Координата Y", "Координата Z", "Висота"};
                vals = fillInputForm("Заповнення: Звичайна Піраміда", fields);
                objectsList->push_back(new Pyramid({vals[0], vals[1], vals[2]}, vals[3]));
                return "[!] Звичайну піраміду створено.";
            }
            case '2': {
                fields = {"Координата X", "Координата Y", "Координата Z", "Висота", "Площа основи"};
                vals = fillInputForm("Заповнення: Трикутна Піраміда", fields);
                objectsList->push_back(new TriangularPyramid({vals[0], vals[1], vals[2]}, vals[3], vals[4]));
                return "[!] Трикутну піраміду створено.";
            }
            case '3': {
                fields = {"Координата X", "Координата Y", "Координата Z", "Висота", "Довжина основи", "Ширина основи"};
                vals = fillInputForm("Заповнення: Чотирикутна Піраміда", fields);
                objectsList->push_back(new QuadrangularPyramid({vals[0], vals[1], vals[2]}, vals[3], vals[4], vals[5]));
                return "[!] Чотирикутну піраміду створено.";
            }
            default:
                return "[!] Некоректний вибір. Спробуйте ще раз.";
        }
    }

    std::string Menu::createObjectMenu() {
        std::string message = "[!] Ви обрали 1. Створення об'єкта.";
        clearConsole();
        showAnswer(&message);


        std::cout << "\n--- Створити об'єкт ---\n";
        std::cout << "1. Об'єкт (базовий)\n";
        std::cout << "2. Піраміда (відкрити підменю)\n";
        std::cout << "3. Сфера\n";
        std::cout << "4. Масове створення (Генератор)\n";
        std::cout << "q. Назад\n";
        std::cout << "Ваш вибір: ";
        char choice; std::cin >> choice; clearInputBuffer();

        switch (choice) {
            case '1': {
                std::vector<std::string> fields = {"Координата X", "Координата Y", "Координата Z"};
                std::vector<double> vals = fillInputForm("Заповнення: Базовий об'єкт", fields);
                Object::Point3D cords{vals[0], vals[1], vals[2]};
                objectsList->push_back(new Object(cords));
                return "[!] Базовий об'єкт створено.";
            }
            case '2': return createPyramidSubMenu();
            case '3': {
                std::vector<std::string> fields = {"Координата X", "Координата Y", "Координата Z", "Радіус"};
                std::vector<double> vals = fillInputForm("Заповнення: Сфера", fields);
                objectsList->push_back(new Sphere({vals[0], vals[1], vals[2]}, vals[3]));
                return "[!] Сферу створено.";
            }
            case '4': return massCreateMenu();
            case 'q': return "[!] Повернення до головного меню.";
            default:  return "[!] Некоректний вибір. Спробуйте ще раз.";
        }
    }

    // --- ОНОВЛЕНЕ: Виведення (використовує масив ID) ---
    std::string Menu::displayObjectsMenu() {
        if (objectsList->empty()) return "[!] Список об'єктів порожній.";

        std::string message = "[!] Ви обрали 2. Перегляд об'єктів.";
        clearConsole();
        showAnswer(&message);

        std::cout << "\n--- Перегляд об'єктів (Оберіть фільтр для пошуку) ---\n";

        bool isCancelled;
        std::vector<int> foundIds = performSearch(isCancelled);

        if (isCancelled) return "[!] Перегляд скасовано.";
        if (foundIds.empty()) return "[!] Немає об'єктів для перегляду.";

        message = "[!] Знайдені об'єкти:";
        clearConsole();
        showAnswer(&message);

        for (Object* item : *objectsList)
            for (int id : foundIds)
            if (item->getId() == id)
                item->showInfo();

        std::cout << "\nНатисніть Enter для повернення в головне меню...";
        std::cin.get();
        return "[!] Перегляд об'єктів завершено.";
    }

    // --- ОНОВЛЕНЕ: Редагування об'єктів (використовує масив ID) ---
    std::string Menu::modifyObjectMenu() {
        if (objectsList->empty()) return "[!] Список об'єктів порожній.";

        std::string message = "[!] Ви обрали 3. Режим редагування.";
        clearConsole();
        showAnswer(&message);

        std::cout << "\n--- Меню редагування (Оберіть фільтр для пошуку) ---\n";

        bool isCancelled;
        std::vector<int> foundIds = performSearch(isCancelled);

        if (isCancelled) return "[!] Редагування скасовано.";

        if (foundIds.empty()) {
            std::cout << "\nНатисніть Enter для повернення в головне меню...";
            std::cin.get();
            return "[!] Немає об'єктів для редагування.";
        }

        std::string actionResult;
        for (int i = 0; i < foundIds.size(); i++) {
            int targetId = foundIds[i];
            bool isWork;
            do {
                isWork = false;
                // Пошук об'єкта в загальному списку за обраним ID зі знайдених
                Object* targetObject = nullptr;
                for (int id : foundIds) {
                    if (id == targetId) {
                        for (Object* item : *objectsList) {
                            if (item->getId() == targetId) {
                                targetObject = item;
                                break;
                            }
                        }
                        break;
                    }
                }

                if (!targetObject) {
                    actionResult = "[!] Помилка: Об'єкт з таким ID не знайдено серед результатів.";
                    continue;
                }

                clearConsole();
                showAnswer(&actionResult);
                std::cout << "[!] Відкрито редактор об'єкта ID " << targetId << "\n";
                targetObject->showInfo();

                std::cout << "Що змінити?\n";
                std::cout << "1. Координату X\n2. Координату Y\n3. Координату Z\n";

                Sphere* s = dynamic_cast<Sphere*>(targetObject);
                Pyramid* p = dynamic_cast<Pyramid*>(targetObject);
                TriangularPyramid* tp = dynamic_cast<TriangularPyramid*>(targetObject);
                QuadrangularPyramid* qp = dynamic_cast<QuadrangularPyramid*>(targetObject);

                if (s) std::cout << "4. Радіус (Сфера)\n";
                if (p) std::cout << "5. Висоту\n";
                if (tp) std::cout << "6. Площу основи\n";
                if (qp) { std::cout << "7. Довжину\n8. Ширину\n"; }

                std::cout << "w. Наступний елемент\n";
                std::cout << "q. Назад до меню\nВаш вибір: ";
                char editChoice; std::cin >> editChoice; clearInputBuffer();


                switch (editChoice) {
                    case '1': targetObject->setX(getDoubleInput("Нове значення X: ")); actionResult = "X змінено."; break;
                    case '2': targetObject->setY(getDoubleInput("Нове значення Y: ")); actionResult = "Y змінено."; break;
                    case '3': targetObject->setZ(getDoubleInput("Нове значення Z: ")); actionResult = "Z змінено."; break;
                    case '4': if(s) { s->setRadius(getDoubleInput("Новий радіус: ")); actionResult = "Радіус змінено."; } break;
                    case '5': if(p) { p->setHight(getDoubleInput("Нова висота: ")); actionResult = "Висоту змінено."; } break;
                    case '6': if(tp) { tp->setAreaOfBase(getDoubleInput("Нова площа: ")); actionResult = "Площу змінено."; } break;
                    case '7': if(qp) { qp->setLength(getDoubleInput("Нова довжина: ")); actionResult = "Довжину змінено."; } break;
                    case '8': if(qp) { qp->setWidth(getDoubleInput("Нова ширина: ")); actionResult = "Ширину змінено."; } break;
                    case 'w': actionResult = "[!] Наступний елемент."; break;
                    case 'q': return "[!] Редагування скасовано.";
                    default:
                        actionResult = "[!] Некоректний вибір.";
                        isWork = true;
                }
            } while (isWork);
        }
        return "[!] Успішно";
    }

    // --- ОНОВЛЕНЕ: Видалення об'єктів (використовує масив ID) ---
    std::string Menu::deleteObjectMenu() {
        if (objectsList->empty()) return "[!] Список об'єктів порожній.";

        std::string message = "[!] Ви обрали 4. Режим видалення.";
        clearConsole();
        showAnswer(&message);

        std::cout << "\n--- Меню видалення (Оберіть фільтр для пошуку) ---\n";

        bool isCancelled;
        std::vector<int> foundIds = performSearch(isCancelled);

        if (isCancelled) return "[!] Видалення скасовано.";

        if (foundIds.empty()) {
            std::cout << "\nНатисніть Enter для повернення в головне меню...";
            std::cin.get();
            return "[!] Немає об'єктів для видалення.";
        }

        std::cout << "Підтвердіть видалення y/N" << std::endl;
        std::cout << "Ваш вибір: ";

        char choise;
        std::cin >> choise;
        clearInputBuffer();

        if ( choise != 'y' && choise != 'Y')
            return "[!] Видалення скасовано.";

        std::vector<int> isDeleted;

        while (foundIds != isDeleted) {
            bool haveDeleted = false;
            for (int i = 0; i < objectsList->size(); i++) {
                for (int id : foundIds)
                    if (id == (*objectsList)[i]->getId()) {
                        delete (*objectsList)[i];
                        std::vector<Object*>::iterator iterator = objectsList->begin() + i;
                        objectsList->erase(iterator);

                        isDeleted.push_back(id);
                        haveDeleted = true;
                        break;
                    }
                if (haveDeleted) break;
            }
        }


        if (!isDeleted.empty()) {
            message = "[!] Об'єкти з ID ";
            for (int id : isDeleted)
                message += std::to_string(id) + ", ";
            message += "успішно видалено.";
            return message;
        } else {
            return "[!] Помилка при видаленні об'єктів.";
        }

    }

    Menu::Menu() {
        objectsList = new std::vector<Object*>();
    }

    Menu::~Menu() {
        for (Object* item : *objectsList)
            delete item;
        delete objectsList;
    }

    void Menu::generateTestPresets() {
        objectsList->push_back(new Object(Object::Point3D{12.0, 13.0, 14.0}));
        objectsList->push_back(new Pyramid({1.0, 1.0, 1.0}, 1.0));
        objectsList->push_back(new TriangularPyramid({54.0, 12.0, 87.0}, -54.0, 1.0));
        objectsList->push_back(new QuadrangularPyramid({-5.0, 0.0, -12.0}, 5.0, 4.0, 1.0));
        objectsList->push_back(new Sphere({-3.0, 0.0, 12.0}, 5.0));
    }

    void Menu::displayMainMenu() {
        char choice;
        std::string message = "[!] Програма готова до роботи.";

        do {
            clearConsole();
            if (!message.empty()) {
                std::cout <<  message << "\n\n";
                 message.clear();
            }

            std::cout << "========= ГОЛОВНЕ МЕНЮ =========\n";
            std::cout << "1. Створити об'єкти (одиночні/генератор)\n";
            std::cout << "2. Переглянути список об'єктів\n";
            std::cout << "3. Редагувати існуючий об'єкт\n";
            std::cout << "4. Видалити об'єкт\n";
            std::cout << "5. Додати тестові дані\n";
            std::cout << "q. Вийти з програми\n";
            std::cout << "================================\n";
            std::cout << "Ваш вибір: ";
            std::cin >> choice;
            clearInputBuffer();

            switch (choice) {
                case '1':  message = createObjectMenu(); break;
                case '2':  message = displayObjectsMenu(); break;
                case '3':  message = modifyObjectMenu(); break;
                case '4':  message = deleteObjectMenu(); break;
                case '5': generateTestPresets();  message = "[!] Ви обрали 5. Тестові дані додано."; break;
                case 'q': std::cout << "Завершення роботи...\n"; break;
                default:  message = "[!] Некоректний вибір. Спробуйте ще раз."; break;
            }
        } while (choice != 'q');
    }

} // Program