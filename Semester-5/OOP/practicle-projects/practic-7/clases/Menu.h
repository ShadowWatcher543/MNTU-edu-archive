//
// Created by yan on 09.05.26.
//

#ifndef PRACTIC_7_MENU_H
#define PRACTIC_7_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Object.h"
#include "Sphere.h"
#include "Pyramid.h"
#include "TriangularPyramid.h"
#include "QuadrangularPyramid.h"

namespace Program {

    inline unsigned long long get_random_seed() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    class Menu {
    private:
        inline static std::mt19937_64 generator = std::mt19937_64(get_random_seed());
        std::vector<Object*>* objectsList;

        static double randomDouble(double min, double max);
        static double randomDouble();
        static void clearConsole();
        void showAnswer(std::string* currentMenuMessage);
        static void clearInputBuffer();
        static double getDoubleInput(const std::string& prompt);
        static int getIntInput(const std::string& prompt);
        static void drawInputForm(const std::string& title, const std::vector<std::string>& fields, const std::vector<std::string>& values, int activeIndex);

        std::vector<double> fillInputForm(const std::string& title, const std::vector<std::string>& fields);

        std::vector<int> performSearch(bool& isCancelled);

        std::string massCreateMenu();
        std::string createPyramidSubMenu(std::string message);
        std::string createObjectMenu();

        std::string displayObjectsMenu();
        std::string modifyObjectMenu();
        std::string deleteObjectMenu();

    public:
        Menu();
        ~Menu();

        void generateTestPresets();
        void displayMainMenu();
    };

} // Program

#endif //PRACTIC_7_MENU_H