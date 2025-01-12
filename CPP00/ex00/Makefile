NAME		:= megaphone

# Répertoires
SRCS_DIR	:= .
OBJS_DIR	:= obj

# Compilation
CC			:= c++
CFLAGS		:= -std=c++98 -Wall -Wextra -Werror
IFLAGS		:= -I .

# Sources
SRCS		:= megaphone.cpp
SRCS		:= $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS		:= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# Commandes
RM			:= rm -rf
DIR_UP		= mkdir -p $(@D)

# Couleurs et emojis
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
RESET		:= \033[0m

SUCCESS_EMOJI	:= ✅
CLEAN_EMOJI		:= 🗑️
BUILD_EMOJI		:= 🛠️

################################################################################

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(BUILD_EMOJI)  Compilation en cours...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(SUCCESS_EMOJI) Compilation terminée !$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(DIR_UP)
	@echo "$(YELLOW)$(BUILD_EMOJI)  Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)$(CLEAN_EMOJI)  Objets supprimés !$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(CLEAN_EMOJI)  Executable supprimé !$(RESET)"

re: fclean all

.PHONY: all clean fclean re
