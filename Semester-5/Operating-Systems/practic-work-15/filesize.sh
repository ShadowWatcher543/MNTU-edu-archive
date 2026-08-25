#!/bin/bash

# Отримання назви файлу з першого аргументу
FILENAME=$1

# Функція перевірки існування файлу
check_file() {
    if [ ! -f "$FILENAME" ]; then
        echo "Помилка: Файл '$FILENAME' не знайдено."
        exit 1
    fi
}

# Функція виводу розміру
size() {
    echo -n "Розмір файлу: "
    du -h "$FILENAME" | cut -f1
}

# Спочатку перевіряємо, чи взагалі передано аргумент
if [ -z "$FILENAME" ]; then
    echo "Використання: ./filesize.sh назва_файлу"
    exit 1
fi

check_file
size