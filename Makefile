# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toandrad <toandrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 11:12:33 by toandrad          #+#    #+#              #
#    Updated: 2025/10/10 11:25:52 by toandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================ #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
BLUE		= \033[0;34m
RED			= \033[0;31m
RESET		= \033[0m

SRCDIR = src
OBJSDIR = objects
LIBFT_DIR = libft

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(addprefix $(OBJSDIR)/, $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJSDIR)/, $(CLIENT_SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a

# ================================== RULES ================================== #

all:  $(SERVER) $(CLIENT)

$(LIBFT):
	@echo "$(YELLOW)🛠️  Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✅ libft built successfully.$(RESET)"

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@echo "$(YELLOW)🛠️  Compiling $(SERVER)...$(RESET)"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
	@echo "$(GREEN)✅ Executable created: $(BLUE)$(SERVER)$(RESET)"

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "$(YELLOW)🛠️  Compiling $(CLIENT)...$(RESET)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
	@echo "$(GREEN)✅ Executable created: $(BLUE)$(CLIENT)$(RESET)"

$(OBJSDIR)/%.o: $(SRCDIR)/%.c | $(OBJSDIR)
	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -Iinc -I$(LIBFT_DIR) -c $< -o $@

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

clean:
	@rm -rf $(OBJSDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo "$(RED)🗑️  All generated files deleted.$(RESET)"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "$(RED)🗑️  All generated files deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re