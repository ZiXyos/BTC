NAME	= linked_list

CC	= gcc

RM	= rm -f

SRCS	=	./add_node.c	\
			./linked_list.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -std=gnu11 -Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) lib/libmy.a

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re