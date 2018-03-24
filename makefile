NAME = fdf

SRC = srcs/main.c \
			srcs/reader.c \
			srcs/drawer.c \
			srcs/functions.c

OBJ = main.o \
			reader.o \
			drawer.o \
			functions.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
		@make -C ./libft/
		@gcc -c $(FLAGS) $(SRC)
		@echo "\033[31m[COMPILATION]\033[0m"
		@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) $(MLX)
		@echo "\033[36m[FDF CREATED]\033[0m"
		@mkdir objs
		@mv main.o objs
		@mv reader.o objs
		@mv drawer.o objs
		@mv functions.o objs

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[32m[CLEANING LIBFT OBJECTS]\033[0m"
	@rm -rf objs
	@echo "\033[32m[CLEANING FDF OBJECTS]\033[0m"

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re : fclean all
