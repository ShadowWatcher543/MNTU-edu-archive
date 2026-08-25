#!/bin/bash

if [ ! -f "$1" ]; then
    echo "Файл не існує"
elif [ -s "$1" ]; then
    echo "Файл існує і містить дані"
else
    echo "Файл існує, але порожній"
fi