with open("file.txt", "a") as f:
    mainName1 = "Завдання"
    for i in range(1, 9+1):
        f.write(f"[[{mainName1} №{i}|{i} {mainName1}]]\n🟥 НЕ Виконано (завдання) НЕ-оцінено 0/9 \n")

