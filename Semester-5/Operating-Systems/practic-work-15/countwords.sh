#!/bin/bash

FILENAME=$1

readfile() {
    if [ ! -f "$FILENAME" ]; then
        echo "Помилка: Файл '$FILENAME' не знайдено."
        exit 1
    fi

    local total_words=0
    local line_num=1

    echo "--- Початок обробки файлу ---"

    while IFS= read -r line || [ -n "$line" ]; do
        # Рахуємо слова в поточному рядку
        line_words=$(echo "$line" | wc -w)
        echo "Рядок $line_num: $line_words слів"
        total_words=$((total_words + line_words))
        ((line_num++))
    done < "$FILENAME"

    echo "---------------------------------"
    echo "ЗАГАЛЬНИЙ ПІДСУМОК: $total_words слів."
}

if [ -z "$FILENAME" ]; then
    echo "Використання: ./countwords.sh назва_файлу"
    exit 1
fi

readfile