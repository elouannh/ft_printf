NAME			:=	libftprintf.a

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
AR				:=	ar
ARFLAGS 		:=	rcs
RM				:=	rm -rf

SRC				:=	ft_printf ft_print_nbrbase ft_print_str ft_print_nbr
SRCS 			:=	$(addsuffix .c, $(SRC))

OBJ_DIR			:=	obj
OBJS			:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		:=	./libft
LIBFT			:=	$(LIBFT_PATH)/libft.a

HDRS			:=	ft_printf.h
MFILE			:=	Makefile

$(OBJ_DIR)/%.o:		%.c $(MFILE) $(HDRS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft
