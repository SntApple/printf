NAME			= libftprintf.a

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

SOURCES			= ft_printf.c ft_itoa.c parse.c print_char.c \
				print_num.c print_str.c type.c utilities.c

OBJECTS			= $(SOURCES:.c=.o)

OBJECTS_BONUS	= $(SOURCES_BONUS:.c=.o)

HEADER			= ft_printf.h

$(NAME):		$(OBJECTS)
				ar rc $(NAME) $(OBJECTS)

all:			$(NAME)

%.o:%.c			$(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

.PHONY:			all clean fclean re bonus

clean:
				rm -f $(OBJECTS)

fclean:			clean
				-rm -f $(NAME)

re:				fclean all
