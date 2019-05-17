#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/07 12:47:06 by tmaze             #+#    #+#              #
#    Updated: 2019/05/09 18:39:42 by tmaze            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CCFLAGS = -Wall -Werror -Wextra
CCSTD =

NAME = libft.a

SRCS =	ft_memalloc.c	\
		ft_memdel.c 	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_isnumeric.c      \
		ft_tolower.c		\
		ft_isupper.c		\
		ft_islower.c		\
		ft_iswhitespace.c	\
		ft_issign.c			\
		\
		ft_strnew.c 			\
		ft_strdel.c 			\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c 			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_strlen.c				\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_str_is_alpha.c		\
		ft_str_is_lowercase.c	\
		ft_str_is_numeric.c		\
		ft_str_is_printable.c	\
		ft_str_is_uppercase.c	\
		ft_strcapitalize.c		\
		ft_strlcpy.c			\
		ft_strlowcase.c			\
		ft_strupcase.c			\
		ft_strndup.c			\
		ft_strnchr.c			\
		ft_strrnchr.c			\
		ft_strsplitwhitespace.c	\
		ft_hasdigit.c			\
		ft_del_words_tables.c	\
		\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putstrpad.c			\
		ft_putnbrpad.c			\
		ft_putstrn.c 			\
		ft_print_words_tables.c	\
		ft_putendl2.c			\
		ft_putendl_fd2.c		\
		\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lstaddend.c	\
		ft_lstsize.c	\
		ft_lstgetat.c	\
		ft_lstgetlast.c	\
		ft_lstsort.c	\
		ft_lstaddsort.c	\
		\
		ft_abs.c	\
		ft_atoi.c	\
		ft_atois.c	\
		ft_itoa.c	\
		ft_nbrlen.c	\
		ft_round.c	\
		\
		ft_printf.c						\
		ft_printf_check_fields.c		\
		ft_printf_check_type.c			\
		ft_printf_tools.c				\
		ft_printf_tools_char.c			\
		ft_printf_tools_float.c			\
		ft_printf_tools_hexa.c			\
		ft_printf_tools_int.c			\
		ft_printf_tools_lenght.c 		\
		ft_printf_tools_malloc_size.c 	\
		ft_printf_tools_oct.c			\
		ft_printf_tools_prec_size.c		\
		ft_printf_tools_str.c			\
		ft_printf_tools_unsigned_int.c	\
		ft_printf_tools_wchar_t.c		\
		ft_printf_tools_wstr.c			\
		\
		get_next_line.c	\
		ft_getline.c	\
		\
		ft_sort_params.c	\
		ft_realpath.c

SRCDIR	= srcs
OBJDIR	= objs
OBJS	= $(SRCS:.c=.o)
OBJP	= $(addprefix $(OBJDIR)/, $(OBJS))
INCLS = -Iincludes

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJP)
	ar rcs $(NAME) $(OBJP)

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/libft.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CCFLAGS) $(CCSTD) $(INCLS) -c $< -o $@

clean:
	rm -f $(OBJP)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)	

re: fclean all
