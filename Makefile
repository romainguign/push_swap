NAME			= push_swap

NAME_BONUS		= checker

LIBFT			= libft/libft.a

CC				= cc

FLAGS 			= -Wall -Wextra -Werror -g

INCLUDE			= -I libft/includes -I includes

LIB				= -L libft -lft

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
LIGHTRED='\033[1;31m'
GREEN = \033[3;92m
YELLOW = \033[0;93m
BLUE = \033[3;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


##############################  SOURCES  #####################################

SRC_DIR			= sources

SRC_BONUS_DIR	= sources_bonus

OBJ_DIR			= object

OBJ_BONUS_DIR	= object_bonus

SRC_FILES		= push_swap.c parsing.c utils.c utils_2.c swap_moves.c push_moves.c \
				  rotate.c reverse_rotate.c three_element_cases.c sort_b.c sort_a.c \
				  exec_sorting.c calc_coast.c find_quartile.c 

SRC_BONUS_FILES	= checker_bonus.c parsing_bonus.c utils_bonus.c swap_moves_bonus.c \
				  push_moves_bonus.c rotate_bonus.c reverse_rotate_bonus.c

OBJ             = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

OBJ_BONUS       = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_FILES:.c=.o))

##############################  RULES  #######################################

all: $(NAME) ascii

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INCLUDE) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(NAME_BONUS) ascii_bonus
	
$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(INCLUDE) -o $(NAME_BONUS) 

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
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

ascii_bonus:
	@echo "\t\t ${MAGENTA}"
	@echo "\t\t   ________              __            "
	@echo "\t\t  / ____/ /_  ___  _____/ /_____  _____"
	@echo "\t\t / /   / __ \/ _ \/ ___/ //_/ _ \/ ___/"
	@echo "\t\t/ /___/ / / /  __/ /__/ ,< /  __/ /    "
	@echo "\t\t\____/_/ /_/\___/\___/_/|_|\___/_/     "
	@echo "\t\t                                     ${DEF_COLOR}\n "


clean:
	@make --quiet clean -C libft
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@echo "${GRAY}Push_Swap object files cleaned! ${DEF_COLOR}"

fclean: clean
	@make --quiet fclean -C libft
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "${YELLOW}Push_Swap executable files cleaned! ${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re