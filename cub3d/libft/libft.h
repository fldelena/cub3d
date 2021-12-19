/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:42:53 by frdescam          #+#    #+#             */
/*   Updated: 2021/04/29 20:43:01 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_endline(char *fullstr);
void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *str);
int				ft_strnstr(const char *str1, const char *str2, size_t size);
char			*ft_strchr(const char *str, int ch);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
int				ft_trim(char *str);
char			*ft_rtrim(char *s);
int				ft_simbcount(char *arr, char c);
int				ft_isdigit(int ch);
char			*ft_strtrim(char *s1, char *set);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
void			ft_lstclear(t_list **lst, void (*del)(void *));

#endif
