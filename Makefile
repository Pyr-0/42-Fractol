
NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit -O3

LINK = -Imlx -Lmlx -lmlx -Llibft -lft
SRC_PATH= src/
SRC = fractol2.c helpers.c key_hooks.c main.c mlx_inits.c fractal_math.c color.c input_check.c
OBJ_PATH = obj/
OBJ := $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
RM = rm -f
AR = ar crs
LIBFT_LIB = libft.a
LIBFT_PATH = libft/
LIBFT_COMB = $(LIBFT_PATH)$(LIBFT_LIB)
LIBFT_OBJS = ${LIBFT_PATH}*.o
LIBFTMAKE = $(MAKE) -silentx -C ${LIBFT_PATH}
MLX_COMB = mlx/libmlx.a
all: $(NAME)

$(LIBFT_COMB):
	@${LIBFTMAKE}
	@echo "$(LILA)           $(NAME) is Ready!$(NC)"
	@echo "$(LILA)          ---------------------$(NC)"
	@echo "$(LILA)             Libft is Ready!$(NC) $(NC)"
	@echo "$(LILA)            -----------------$(NC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -Imlx -Ilibft -c $< -o $@
#	$(CC) -I/usr/include -Imlx -O3 -c $< -o $@
$(NAME): $(MLX_COMB) $(OBJ) $(LIBFT_COMB)
	@printf $(YELLOW)"*--------object files created!---------*\n\n"$(RESET)
	${CC} ${FLAGS} ${HEADERS_FOLDER} ${OBJ} $(LINK) -o ${NAME}
	@printf $(LIGHTGREEN)"*--------executable created!-----------*\n\n"$(RESET)

$(MLX_COMB):
	@printf $(LIGHTBLUE)"*--------checking mlx...---------------*\n\n"$(RESET)
	@make -silent -C ./mlx 

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C mlx clean
	
fclean: 	clean
	${RM} ${NAME}
	@echo "$(RED)            FULL CLEAN COMPLETED!$(NC)"
	@echo "$(RED)      ------------------------------$(NC)"
	
re: fclean all
	make -silent -C ./mlx

.PHONY: all clean fclean re

#text modifiers #
RED = "\e[31m"

GREEN = "\e[32m"

YELLOW = "\e[33m"

BLUE = "\e[34m"

MAGENTA = "\e[35m"

CYAN = "\e[36m"

LIGHTGRAY = "\e[37m"

DARKGRAY = "\e[90m"

LIGHTRED = "\e[91m"

LIGHTGREEN = "\e[92m"

LIGHTYELLOW = "\e[93m"

LIGHTBLUE = "\e[94m"

LIGHTMAGENTA = "\e[95m"

LIGHTCYAN = "\e[96m"

RED_BG = "\e[41m"

GREEN_BG = "\e[42m"

YELLOW_BG = "\e[43m"

BLUE_BG = "\e[44m"

MAGENTA_BG = "\e[45m"

CYAN_BG = "\e[46m"

LIGHTGRAY_BG = "\e[47m"

DARKGRAY_BG = "\e[100m"

LIGHTRED_BG = "\e[101m"

LIGHTGREEN_BG = "\e[102m"

LIGHTYELLOW_BG = "\e[103m"

LIGHTBLUE_BG = "\e[104m"

LIGHTMAGENTA_BG = "\e[105m"

LIGHTCYAN_BG = "\e[106m"

BOLD = "\e[1m"

ITALIC = "\e[3m"

UNDERLINED = "\e[4m"

RESET = "\e[0m"
