# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:04:52 by chonorat          #+#    #+#              #
#    Updated: 2023/11/09 15:04:52 by chonorat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLOR
_GREEN = \033[92m
_YELLOW = \033[33m
_RED = \033[31m

#POLICE
_END = \033[0m
_BOLD = \033[1m

NAME = philo
CFLAGS = -Wall -Wextra -Werror -IIncludes
RM = @rm -rf
CC = @cc
DIR = @mkdir -p
PRINT = @echo
NORM = @norminette | awk '$$NF!="OK!" {print "$(_RED)" $$0 "\033[0;0m"}'
HEADER = Includes/philo.h
FILES = philo\
		Init/init_data\
		Init/get_time\
		Execution/eat_handler\
		Execution/start_philo\
		Execution/monitoring\
		Execution/join_philo\
		Parsing/get_arg\
		Print/show_error\
		Print/print_action\
		Utils/ft_atoi\
		Utils/ft_putstr_fd\
		Utils/ft_usleep\
		Utils/monitoring_utils\
		Free/free_data
SRCS = $(addsuffix .c, $(addprefix Sources/, $(FILES)))
OBJS = $(addsuffix .o, $(addprefix Objects/, $(FILES)))

$(NAME): $(OBJS)
	$(PRINT) "\n${_BOLD}Waiting for norminette...${_END}"
	$(NORM)
	$(PRINT) "${_BOLD}Norminette done.${_END}"
	$(PRINT) "\n${_YELLOW}Making $(NAME)...${_END}"
	$(CC) $(OBJS) -o $(NAME)
	$(PRINT) "${_BOLD}${_GREEN}$(NAME) done.\a${_END}"

Objects/%.o: Sources/%.c Makefile $(HEADER)
	$(DIR) Objects Objects/Utils Objects/Parsing Objects/Init
	$(DIR) Objects/Free Objects/Print Objects/Execution
	$(PRINT) "Compiling ${_BOLD}$<$(_END)..."
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(CLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) .OS
	$(RM) $(OBJS)
	$(PRINT) "${_BOLD}${_GREEN}Objects cleaned.\a${_END}"

fclean:
	$(FCLEAN_LIBFT)
	$(PRINT) "\n${_BOLD}Cleaning Objects...${_END}"
	$(RM) $(OBJS)
	$(PRINT) "${_RED}Deleting $(NAME)...${_END}"
	$(RM) $(NAME)
	$(PRINT) "${_RED}Deleting Objects directory...${_END}"
	$(RM) Objects
	$(RM) .OS
	$(PRINT) "${_GREEN}Objects cleaned.${_END}"
	$(PRINT) "${_GREEN}Objects directory deleted.${_END}"
	$(PRINT) "${_GREEN}$(NAME) deleted.\a\n${_END}"

re: fclean all

norminette:
	$(PRINT) "\n${_BOLD}Waiting for norminette...${_END}"
	$(NORM)
	$(PRINT) "${_BOLD}Norminette done.${_END}"

.PHONY: all clean fclean re
