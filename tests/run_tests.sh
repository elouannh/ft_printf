make -C ../ all
cc -Wall -Wextra -Werror main.c ../libftprintf.a

echo "\n\n\n\n"

./a.out
