#!/bin/bash

echo -n "Введіть число: "
read num

if [ "$num" -gt 100 ]; then
    echo "Число велике"
else
    echo "Число невелике"
fi