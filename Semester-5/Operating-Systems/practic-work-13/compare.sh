#!/bin/bash

if [ "$1" -eq "$2" ]; then
    echo "Числа рівні"
elif [ "$1" -gt "$2" ]; then
    echo "$1 більше"
else
    echo "$2 більше"
fi