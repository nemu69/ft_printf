/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 21:15:26 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 06:36:03 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int					ft_printf(const char *str, ...) __attribute__
((format(printf,1,2)));
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(char *str);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long int n, int preci);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(long int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_base(int nbr, char *base);
void				ft_uputnbr_fd(long int n, int fd);

typedef	struct		s_list
{
	int				zero;
	int				minus;
	char			flag;
	int				error;
	void			*flagn;
	int				width;
	int				preci;
	char			convert;
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *));

int					ft_int_len(long int n);
int					ft_base_len(long int n, char *base);
char				*ft_itoa_base(long int nbr, char *base, int preci);
int					ft_unint_len(long int value);
int					ft_printf_print(t_list *lst);
char				*ft_chartostr(char c);
int					ft_count_lst(t_list *lst);
char				*ft_utoa(long long int n, int preci);
int					ft_pourcent(t_list *lst, char *str, int i, va_list va);
int					ft_create_content(t_list *lst, va_list va);
int					count_malloc_int(t_list *lst, int conint);
int					count_unsi(t_list *lst, char c, unsigned int conint);
int					ft_strcmp(char *s1, char *s2);
int					ft_flag_int(t_list *lst, long int conint);
int					ft_flag_hex(t_list *lst, int i, unsigned int conint);
int					ft_flag_u(t_list *lst, va_list va, int i);
int					count_malloc_ptr(t_list *lst, int strl);
int					count_malloc_char(t_list *lst);
int					count_malloc_str(t_list *lst, char *str);
char				*ft_space_zero(char space, int mallo,
		int conint, t_list *lst);
int					ft_flag_pourc(t_list *lst);
void				ft_flagsp(t_list *lst);
#endif
