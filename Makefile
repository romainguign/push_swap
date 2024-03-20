NAME			= push_swap

LIBFT			= libft/libft.a

CC				= cc

FLAGS 			= -Wall -Wextra -Werror -g

INCLUDE			= -I libft/includes -I includes

LIB				= -L libft -lft

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[3;92m
YELLOW = \033[0;93m
BLUE = \033[3;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


##############################  SOURCES  #####################################

SRC_DIR			= sources

OBJ_DIR			= object

SRC_FILES		= push_swap.c parsing.c tmp.c utils.c utils_2.c swap_moves.c push_moves.c \
				  rotate.c reverse_rotate.c three_element_cases.c sort_b.c sort_a.c \
				  exec_sorting.c calc_coast.c find_quartile.c
### rm tmp.c

OBJ             = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

##############################  RULES  #######################################

all: $(NAME) ascii

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INCLUDE) -o $(NAME) 
	@cp $(NAME) ./push_swap_visualizer/build/bin

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR) $(OBJ_BONUS_DIR):
	@mkdir -p $@

$(LIBFT):
	@make --quiet -C libft 

ascii:
	@echo "${MAGENTA}"
	@echo "\t\t    ____             __       _____                   "
	@echo "\t\t   / __ \__  _______/ /_     / ___/      ______ _____ "
	@echo "\t\t  / /_/ / / / / ___/ __ \    \__ \ | /| / / __ \`/ __ \\"
	@echo "\t\t / ____/ /_/ (__  ) / / /   ___/ / |/ |/ / /_/ / /_/ /"
	@echo "\t\t/_/    \__,_/____/_/ /_/   /____/|__/|__/\__,_/ .___/ "
	@echo "\t\t                                             /_/      ${DEF_COLOR}\n"

clean:
	@make --quiet clean -C libft
	@rm -rf $(OBJ_DIR)
	@echo "${GRAY}Push_Swap object files cleaned! ${DEF_COLOR}"

fclean: clean
	@make --quiet fclean -C libft
	@rm -f $(NAME)
	@echo "${YELLOW}Push_Swap executable files cleaned! ${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re