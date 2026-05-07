#!/bin/bash

# Запит числа
echo -n "Введіть число: "
read number

# Перевірка типу вводу
if ! [[ "$number" =~ ^[0-9]+$ ]]; then
    echo "Помилка: будь ласка, введіть ціле позитивне число."
    exit 1
fi

echo "Зворотний відлік:"

while [ "$number" -gt 0 ]
do
    echo "$number"

    ((number--))

    sleep 1
done

echo "Старт!"