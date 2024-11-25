#Nomes#
NAME = libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar 
ARFLAGS	= -rc
RM		= rm -rf

SRCS	= ft_strlen_pf.c \
		ft_putchar_fd_pf.c \
		ft_putendl_fd_pf.c \
		ft_putnbr_fd_pf.c \
		ft_putstr_fd_pf.c \
		ft_printf.c \
		ft_lowhex_pf.c \
		ft_uphex_pf.c \

#transformacao#
OBJ = $(SRCS:.c=.o)

#Regras#
all: $(NAME)

clean: 
		$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean 
		$(RM) $(NAME)

re: fclean all

#Compilacao#
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#Anti-Confusao#
.PHONY: all clean fclean re