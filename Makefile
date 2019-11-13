##
## PERSONAL PROJECT, 2019
## 2_pow_computer
## File description:
## Makefile
##

SRC	=	src/help_free.c		\
		src/writing.c		\
		src/reading.c		\
		src/computing.c		\
		src/detectors.c		\
		src/setup.c		\
		src/main_2_pow.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	2_pow_computer

OUTPUTTXT	=	calculations_2pow.txt

.PHONY: clean fclean re 2_pow_computer

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'
	@rm -rf $(OUTPUTTXT)
	@echo Cleaned \'$(OUTPUTTXT)\'

re: fclean all
