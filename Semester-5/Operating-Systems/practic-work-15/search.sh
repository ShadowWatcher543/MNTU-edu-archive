#!/bin/bash

WORD=$1
FILE=$2

search_word() {
    if [ ! -f "$FILE" ]; then
        echo "Помилка: Файл '$FILE' не знайдено."
        exit 1
    fi

    echo "--- Результати пошуку слова '$WORD' у файлі '$FILE' ---"
    
    grep -n "$WORD" "$FILE"

    # Перевіряємо статус виходу grep (0 - знайдено, 1 - не знайдено)
    if [ $? -ne 0 ]; then
        echo "Слово не знайдено."
    fi
}

if [ -z "$WORD" ] || [ -z "$FILE" ]; then
    echo "Використання: ./search.sh [слово] [файл]"
    exit 1
fi

search_word