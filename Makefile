NAME_EXEC = pipex
NAME_EXEC_BONUS = pipex_bonus
CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

SRC_FILES = src/pipex.c src/utils.c

SRC_BONUS_FILES = src_bonus/pipex_bonus.c src_bonus/utils_bonus.c

OBJ_SRC = $(patsubst %.c,%.o,$(SRC_FILES))
OBJ_SRC_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS_FILES))

$(NAME_EXEC): $(OBJ_SRC)
	make -sC libft/
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT) -o $(NAME_EXEC) -I libft/

$(NAME_EXEC_BONUS): $(OBJ_SRC_BONUS)
	make -sC libft/
	$(CC) $(CFLAGS) $(OBJ_SRC_BONUS) $(LIBFT) -o $(NAME_EXEC_BONUS) -I libft/
	
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I libft

all : $(NAME_EXEC)

bonus : $(NAME_EXEC_BONUS)

clean :
	echo "wait ..."
	rm -rf $(OBJ_SRC)
	rm -rf $(OBJ_SRC_BONUS)
	echo "les fichiers .o sont maintenant supprimers ."
fclean :
	echo "wait ..."
	rm -rf $(OBJ_SRC)
	rm -rf $(OBJ_SRC_BONUS)
	rm -rf $(NAME_EXEC)
	rm -rf $(NAME_EXEC_BONUS)
	make fclean -sC libft/
	echo "les fichiers .o et les executables sont maintenant supprimers ."

re : fclean all

.PHONY : all clean fclean re