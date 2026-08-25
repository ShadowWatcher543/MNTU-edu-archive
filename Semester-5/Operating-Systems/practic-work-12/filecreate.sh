#!/bin/bash
echo -n "Введіть назву файлу: "
read filename
touch "$filename"
echo "Файл '$filename' успішно створено."