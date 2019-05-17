/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:12:36 by tmaze             #+#    #+#             */
/*   Updated: 2019/04/26 10:36:51 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>

# define FT_RESET				"\x1b[0m"
# define FT_BOLD				"\x1b[1m"
# define FT_CLEAR				"\x1b[2J"

# define FT_COLOR_BLACK			"\x1b[30m"
# define FT_COLOR_RED			"\x1b[31m"
# define FT_COLOR_GREEN			"\x1b[32m"
# define FT_COLOR_YELLOW		"\x1b[33m"
# define FT_COLOR_BLUE			"\x1b[34m"
# define FT_COLOR_MAGENTA		"\x1b[35m"
# define FT_COLOR_CYAN			"\x1b[36m"
# define FT_COLOR_WHITE			"\x1b[37m"

# define FT_COLOR_BG_BLACK		"\x1b[40m"
# define FT_COLOR_BG_RED		"\x1b[41m"
# define FT_COLOR_BG_GREEN		"\x1b[42m"
# define FT_COLOR_BG_YELLOW		"\x1b[43m"
# define FT_COLOR_BG_BLUE		"\x1b[44m"
# define FT_COLOR_BG_MAGENTA	"\x1b[45m"
# define FT_COLOR_BG_CYAN		"\x1b[46m"
# define FT_COLOR_BG_WHITE		"\x1b[47m"

# define FT_INT_MAX				2147483647
# define FT_INT_MIN				-2147483648

/*
** définition type t_list
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** definition macro BUFF_SIZE
*/

# define BUFF_SIZE 30

/*
** definition type t_file
*/

typedef struct		s_file
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
}					t_file;

enum				e_size
{
	h,
	hh,
	l,
	ll,
	j,
	z,
	L
};

enum				e_type
{
	p,
	d,
	i,
	D,
	o,
	O,
	u,
	x,
	X,
	U,
	s,
	S,
	c,
	C,
	percent,
	f
};

typedef struct		s_conv
{
	int				fl_minus;
	int				fl_plus;
	int				fl_zero;
	int				fl_hashtag;
	int				fl_space;
	int				fl_witdth;
	int				fl_prec;
	enum e_size		fl_size;
	enum e_type		fl_type;
	char			*str;
	int				str_size;
}					t_conv;

/*
** Print functions
*/

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);

/*
** ft_printf tools
*/

void				init_struct_conv(t_conv *field);
void				ft_align_str_zero(char *str, t_conv *field);
void				ft_align_str(char *str, t_conv *field);
void				set_malloc_sizes(uintmax_t nb, t_conv *field);
void				set_malloc_sizeu(uintmax_t nb, t_conv *field);
void				set_malloc_sizeo(uintmax_t nb, t_conv *field);
void				set_malloc_sizeu(uintmax_t nb, t_conv *field);
int					set_malloc_sizef(long double nb, char *nbrstr
									, t_conv *field);
void				init_handler_tab(char *(*f[14])(t_conv *, va_list));
int					ft_wstrlen(const wint_t *str);
uint64_t			dmod(long double nb, long double mod);

/*
** Check Flags
*/

void				check_flags(const char **str, t_conv *field);
void				check_width(const char **str, t_conv *field, va_list ap);
ssize_t				check_precision(const char **str, t_conv *field
									, va_list ap);
void				check_size(const char **str, t_conv *field);
ssize_t				check_type_one(const char **str, t_conv *field);
ssize_t				check_type_two(const char **str, t_conv *field);
ssize_t				check_fields(const char **str, va_list ap, t_conv *field);

/*
** Handle type i and d
*/

char				*handler_int(uintmax_t nb, t_conv *field);
char				*select_int_handler(t_conv *field, va_list ap);
char				*handle_output_i_d(t_conv *field, va_list ap);

/*
** Handle type u
*/

char				*select_uns_int_handler(t_conv *field, va_list ap);
char				*handle_output_u(t_conv *field, va_list ap);
char				*handler_uns(uintmax_t nb, t_conv *field);

/*
** Handle type x and X
*/

char				*handler_hexa(uintmax_t nb, t_conv *field);
char				*select_hexa_handler(t_conv *field, va_list ap);
char				*handle_output_hexa(t_conv *field, va_list ap);
void				ft_align_hex_zero(char *str, t_conv *field);
void				ft_align_hex(char *str, t_conv *field);
int					set_precision_sizex(uintmax_t nb, t_conv *field);
void				set_malloc_sizeh(uintmax_t nb, t_conv *field);

/*
** Handle type o
*/

char				*handler_oct(uintmax_t nb, t_conv *field);
char				*select_oct_handler(t_conv *field, va_list ap);
char				*handle_output_oct(t_conv *field, va_list ap);
void				ft_align_oct_zero(char *str, t_conv *field);
void				ft_align_oct(char *str, t_conv *field);
int					set_precision_sizeo(uintmax_t nb, t_conv *field);

/*
** Handle type c
*/

char				*handle_output_char(t_conv *field, va_list ap);

/*
** Handle type C
*/

unsigned int		ft_bin_size(unsigned int nb);
void				ft_align_wchar(char *str, t_conv *field);
char				*handler_2oct_char(wint_t c, t_conv *field);
char				*handler_3oct_char(wint_t c, t_conv *field);
char				*handler_4oct_char(wint_t c, t_conv *field);
char				*handle_output_wchar(t_conv *field, va_list ap);

/*
** Handle type s
*/

char				*handle_output_str(t_conv *field, va_list ap);
void				ft_align_wstr(char *str, t_conv *field);
int					set_precision_sizes(uintmax_t nb, t_conv *field);

/*
** Handle type S
*/

char				*handle_output_wstr(t_conv *field, va_list ap);
int					set_prec_size_wstr(const wint_t *str, t_conv *field);

/*
** Handle type f
*/

char				*handle_output_float(t_conv *field, va_list ap);

/*
** fonctions obligatoires
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src,\
								size_t n);
void				*ft_memccpy(void *dest, const void *src,\
								int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src,\
								size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isnumeric(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** fonctions supplémentaires
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** fonctions bonus
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** fonctions additionneles
*/

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_strlowcase(char *s);
char				*ft_strupcase(char *s);
char				*ft_strcapitalize(char *str);
size_t				ft_strlcpy(char	*dst, const char *src,\
								size_t size);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstgetat(t_list *lst, size_t ind);
t_list				*ft_lstgetlast(t_list *lst);
void				ft_sort_params(int ac, char **av);
void				ft_print_words_tables(char **tab);
t_list				*ft_lstaddend(t_list **alst, t_list *new);
char				*ft_strndup(const char *s1, size_t n);
unsigned int		ft_abs(int nb);
char				*ft_strnchr(const char *s, int c, int n);
char				*ft_strrnchr(const char *s, int c, int n);

int					get_next_line(const int fd, char **line);

void				ft_del_words_tables(char ***word_table);
void				ft_putstrn(char	const *s, size_t nb);
size_t				ft_nbrlen(int nb);
void				ft_putstrpad(char *str, size_t size, char pad, char align);
void				ft_putnbrpad(int nbr, size_t size, char pad, char align);

void				ft_lstsort(t_list **lst, int (*f)(void *c1, void *c2),
								int rev);
void				ft_lstaddsort(t_list **lst, t_list *new,
								int (*f)(void *c1, void *c2), int rev);

int					ft_round(float x, float ind);

char				*ft_realpath(char *r_path, char **a_path);
int					ft_issign(char c);
int					ft_iswhitespace(char c);
int					ft_hasdigit(char *s);
char				**ft_strsplitwhitespace(char *s);
int					ft_atois(const char *str, int *nb);
int					ft_getline(char **line);
int					ft_putendl2(char const *s);
int					ft_putendl_fd2(char const *s, int fd);

#endif
