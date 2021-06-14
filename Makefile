NAME = philo
LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
SRCS_DIR = ./srcs

SRCS =	\
	./srcs/main.c	\
	./srcs/utils.c  \
	./srcs/init_philo.c  \
	./srcs/running_philo.c \
	./srcs/basic_action.c \
	./srcs/clean_up_philo.c
	

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRCS)

re : clean
	make

clean :
	@rm -rf $(NAME)

test :
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(SRCS)
	@./a.out
	@rm a.out

.PHONY : test
