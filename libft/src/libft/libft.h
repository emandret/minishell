/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:37:31 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 08:35:42 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define ABS(x) (x > 0 ? x : -x)
# define END(s) (s + ft_strlen(s))

/*
** Boolean implementation
*/
typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** Memory functions
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** String functions
*/
char				*ft_chrncpy(char *dest, char c, int n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *big, const char *little,
	size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Characters classifications functions
*/
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isblanks(int c);

/*
** Bonus part
*/
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_sqrt(int n);
char				*ft_strjoin_free(const char *s1, const char *s2);
char				*ft_itoa_base(int n, unsigned int base);
char				*ft_getenv(char **env, char *key);
char				*ft_getpath(char *path, char *file);
char				**ft_tabdup(char **tab);
char				*ft_strrep(char *src, char *in, char *to);
int					ft_strcount(const char *s, const char *in);
char				**ft_split_whitespaces(const char *s);
int					ft_tabsize(char **tab);

/*
** Added for ft_printf (libft improved)
*/
char				*ft_strtolower(char *s);
char				*ft_strtoupper(char *s);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(const wchar_t *s);
char				*ft_ltoa_base(intmax_t n, unsigned int base);
char				*ft_ultoa_base(uintmax_t n, unsigned int base);
int					ft_strfchr(const char *s, int c);

/*
** Linked list definition
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Linked lists functions
*/
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
