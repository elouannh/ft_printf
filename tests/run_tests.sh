#!/bin/bash

norminette ../
make -C ../ fclean
make -C ../ all
cc main.c ../libftprintf.a

echo ""
echo ""
echo ""

./a.out $1
