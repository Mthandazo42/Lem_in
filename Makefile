#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 16:51:02 by tmaze             #+#    #+#              #
#    Updated: 2019/05/09 18:39:33 by tmaze            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	lem-in

#	Make options
MAKEFLAGS	+=	--no-print-directory

#	Output
UNAME	:=	$(shell uname)
ifeq ($(UNAME), Darwin)
ECHO	=	@echo
endif

ifeq ($(UNAME), Linux)
ECHO	=	@echo -e
endif

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

#	Folders
LIBDIR	=	libft
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	includes libft/includes

#	Source files
SRC	=		lm_parser.c 			\
			lm_mem_utils.c 			\
			lm_check_errors.c		\
			lm_data_utils.c			\
			lm_initdata.c			\
			lm_mem_utils.c			\
			lm_graph_utils.c		\
			lm_parser_error_check.c	\
			lm_utils_parser.c		\
			lm_utils_algo.c			\
			bfs.c 					\
			lst_ind.c				\
			edmonds_karp.c 			\
			push_ants.c				\
			push_ants_utils.c		\
			score_utils.c			\
			print_map.c				\
			lem_in.c


OBJ		=	$(SRC:.c=.o)

LIB		=	ft
LIBFILE	=	libft.a

#	Prefixes
OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP		=	$(foreach dir, $(INCDIR), -I$(dir))
OBJT		=	$(OBJDIR)/test.o

#	Default Rule
DRULE	=	all

#	Main rules
default	:
		@$(ECHO) -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
		@make $(DRULE)
		@$(ECHO) -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all		:	$(NAME)

#	Compilation rules

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c includes/lem_in.h
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) -c -o $@ $< $(INCP)

$(LIBDIR)/$(LIBFILE)	:
		@$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Librairy Compilation <===$(DEF)"
		$(MAKE) -C $(LIBDIR) all

$(NAME)	:	$(OBJP) $(LIBDIR)/$(LIBFILE)
		@$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		$(CC) $(FLAGS) -o $@ $^ $(INCP) -L$(LIBDIR) -l$(LIB)

test	:	$(OBJP) $(OBJT) $(LIBDIR)/$(LIBFILE)
		@$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		$(CC) $(FLAGS) -o $@ $^ $(INCP) -L$(LIBDIR) -l$(LIB)

#	Cleaner rules
clean	:
		@$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Object Files <===$(DEF)"
		@$(RM) -rf $(OBJDIR)
		@$(MAKE) -C $(LIBDIR) clean

fclean	:	clean
		@$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Binary File <===$(DEF)"
		@$(RM) -f $(NAME) $(NAME2)
		@$(RM) -rf *.dSYM
		@$(MAKE) -C $(LIBDIR) fclean

re		:	fclean default

#	Phony
.PHONY	=	default all re clean fclean
#	Color
DEF		=	\033[0m
BLA		=	\033[30m
BLI		=	\033[5m
BLU		=	\033[34m
CYA		=	\033[36m
GRA		=	\033[1m
GRE		=	\033[32m
PUR		=	\033[35m
RED		=	\033[31m
SOU		=	\033[4m
WHI		=	\033[37m
YEL		=	\033[33m
