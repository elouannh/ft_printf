#!/bin/bash

norminette ../
make -C ../ fclean
make -C ../ all
cc -Wall -Wextra -Werror main.c ../libftprintf.a

echo ""
echo ""
echo ""

./a.out $1
