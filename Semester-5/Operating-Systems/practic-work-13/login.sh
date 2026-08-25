#!/bin/bash

echo -n "Введіть ім'я користувача: "
read user

if [ "$user" == "admin" ]; then
    echo "Адміністратор увійшов"
elif [ "$user" == "guest" ]; then
    echo "Гість увійшов"
else
    echo "Невідомий користувач"
fi