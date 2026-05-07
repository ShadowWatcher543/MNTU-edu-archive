#!/bin/bash

TARGET_DIR=$1

backup() {
    echo "Починаю архівацію каталогу '$TARGET_DIR'..."
    # Створюємо архів. Прапор -c (create), -z (gzip), -f (file)
    tar -czf backup.tar.gz "$TARGET_DIR"
    
    if [ $? -eq 0 ]; then
        echo "Резервну копію створено успішно: backup.tar.gz"
    else
        echo "Помилка під час створення архіву."
    fi
}

check_dir() {
    # Перевірка, чи це директорія (-d)
    if [ -d "$TARGET_DIR" ]; then
        echo "Каталог '$TARGET_DIR' знайдено."
        backup
    else
        echo "Помилка: Каталог '$TARGET_DIR' не існує або це не папка."
        exit 1
    fi
}

# Перевірка, чи передано аргумент
if [ -z "$TARGET_DIR" ]; then
    echo "Використання: ./backupdir.sh назва_каталогу"
    exit 1
fi

check_dir