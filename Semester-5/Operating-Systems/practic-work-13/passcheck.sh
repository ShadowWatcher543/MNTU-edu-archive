#!/bin/bash

# Хеш пароля "1234", згенерований за допомогою SHA-256
# echo -n "1234" | sha256sum
CORRECT_HASH="03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4"

echo -n "Введіть пароль: "
# -s приховує введення символів
#read -s password
read password
echo ""

# Хешуємо введений користувачем пароль
USER_INPUT_HASH=$(echo -n "$password" | sha256sum | awk '{print $1}')

if [ "$USER_INPUT_HASH" == "$CORRECT_HASH" ]; then
    echo "Доступ дозволено"
else
    echo "Неправильний пароль"
fi
