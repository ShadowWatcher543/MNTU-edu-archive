#!/bin/bash

# Функція для генерації імені файлу в новому форматі
get_filename() {
    echo "log_$(date +%d-%m-%Y).txt"
}

# Створює файл, якщо його ще немає
save_log() {
    local logfile=$(get_filename)
    if [ ! -f "$logfile" ]; then
        touch "$logfile"
        echo "Створено новий файл логу: $logfile"
    fi
}

# Записує повідомлення з часовою міткою
write_log() {
    local message=$1
    local logfile=$(get_filename)
    # Формат запису: [14:30:05] Повідомлення
    echo "[$(date +%H:%M:%S)] $message" >> "$logfile"
}

# Відображає лог
show_log() {
    local logfile=$(get_filename)
    echo "--- Вміст логу ($logfile) ---"
    if [ -f "$logfile" ]; then
        cat "$logfile"
    else
        echo "Файл логу ще не створено."
    fi
    echo "----------------------------"
}

# Виконання скрипта
save_log

write_log "Запис 1: Скрипт успішно ініціалізовано."
write_log "Запис 2: Формат дати змінено на DD-MM-YYYY."
write_log "Запис 3: Тестування завершено."

show_log
