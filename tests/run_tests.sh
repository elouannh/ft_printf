make -C ../ all
cc -Wall -Wextra -Werror main.c ../libftprintf.a
./a.out
