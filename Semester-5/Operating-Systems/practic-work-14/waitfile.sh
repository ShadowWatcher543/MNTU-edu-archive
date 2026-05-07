#!/bin/bash

echo "Очікування появи файлу 'result.txt'"

# Цикл until працює, поки умова [ -f result.txt ] хибна
until [ -f "result.txt" ]
do
    # Виводимо крапку без переходу на новий рядок для візуалізації очікування
    echo -n "."
    # Затримка на 1 секунду
    sleep 1
done

echo -e "\nФaйл знайдено!"