NAME		= philo_two

SRCS		= ./srcs/main.c \
		  ./srcs/utils.c \

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDES	= -I./includes

all:
	@$(MAKE) $(NAME) -j4

%.o:    %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo philo_two compiled!

clean:
	@$(RM) $(OBJS)
	@echo clean .o files

fclean: clean
	@$(RM) $(NAME)
	@echo philo_two removed!

re:	fclean $(NAME)
