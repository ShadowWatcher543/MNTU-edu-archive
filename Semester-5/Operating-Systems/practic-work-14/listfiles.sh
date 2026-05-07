#!/bin/bash

echo "--- Пошук текстових файлів у поточному каталозі ---"

for file in *.txt
do
    # Перевірка, якщо жодного файлу .txt не знайдено
    if [ -e "$file" ]; then
        echo "Знайдено файл: $file"
    else
        echo "Файлів з розширенням .txt не знайдено."
    fi
done