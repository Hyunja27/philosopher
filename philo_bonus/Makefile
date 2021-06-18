NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
SRCS_DIR = ./srcs

SRCS =	\
	./srcs/main_bonus.c	\
	./srcs/utils_bonus.c  \
	./srcs/init_philo_bonus.c  \
	./srcs/running_philo_bonus.c \
	./srcs/basic_action_bonus.c \
	./srcs/clean_up_philo_bonus.c

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
