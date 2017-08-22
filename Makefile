# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emandret <emandret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 12:34:12 by emandret          #+#    #+#              #
#    Updated: 2017/08/22 05:14:11 by emandret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
SRC = builtins.c cd.c echo.c env.c exit.c gnl.c main.c setenv.c utils.c \
unsetenv.c

OBJDIR = obj
OBJ = $(SRC:.c=.o)

LIB = libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(LIB) $(OBJDIR) $(NAME)

$(LIB):
	@make -C libft

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@$(CC) $(CFLAGS) $(addprefix $(SRCDIR)/, $(SRC)) -o $(NAME) -L libft -l ftprintf
	@tput setaf 77 ; echo [DONE]

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo compiled $<

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: re fclean clean all
