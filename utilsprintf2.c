/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilsprintf2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 07:07:23 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 16:52:27 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_str(t_list *lst, va_list va, int i)
{
	char	*join;
	char	*constr;

	if (!(join = ft_substr(va_arg(va, char *), 0, (size_t)lst->preci)))
	{
		free(join);
		join = ft_substr("(null)", 0, (size_t)lst->preci);
	}
	lst->error = -1;
	if (lst->preci == -1)
		lst->error = count_malloc_str(lst, join);
	if (!(constr =
				ft_calloc(count_malloc_str(lst, join) + 1, 1)))
		return (0);
	while (count_malloc_str(lst, join))
	{
		lst->width--;
		constr[i++] = ' ';
	}
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(join);
	free(constr);
	return (1);
}

int		ft_flag_c(t_list *lst, va_list va, int i)
{
	char	*join;
	char	*constr;
	int		j;

	j = 0;
	if (!(constr =
				ft_calloc(count_malloc_char(lst) + 1, 1)))
		return (0);
	if (i == 0)
		j++;
	while (count_malloc_char(lst))
	{
		lst->width--;
		j++;
		constr[i++] = ' ';
	}
	join = ft_chartostr(va_arg(va, int));
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(constr);
	free(join);
	lst->width = j;
	return (1);
}

int		ft_flag_p(t_list *lst, va_list va, int i)
{
	char	*join;
	char	*constr;

	lst->content = ft_itoa_base((long)va_arg(va, char *),
			"0123456789abcdef", lst->preci);
	join = ft_strjoin("0x", lst->content);
	free(lst->content);
	if (!(constr =
				ft_calloc(count_malloc_ptr(lst, ft_strlen(join)) + 1, 1)))
		return (0);
	while (count_malloc_ptr(lst, ft_strlen(join)))
	{
		lst->width--;
		constr[i++] = ' ';
	}
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(join);
	free(constr);
	return (1);
}

void	ft_flag_n(t_list *lst, va_list va)
{
	lst->flagn = va_arg(va, int *);
	lst->content = ft_strdup("\0");
}

int		ft_create_content(t_list *lst, va_list va)
{
	if (lst->convert == 'u')
		return (ft_flag_u(lst, va, 0));
	if (lst->convert == 'x' || lst->convert == 'X')
		return (ft_flag_hex(lst, 0, va_arg(va, unsigned int)));
	if (lst->convert == 'i' || lst->convert == 'd')
		return (ft_flag_int(lst, va_arg(va, int)));
	if (lst->convert == 's')
		return (ft_flag_str(lst, va, 0));
	if (lst->convert == 'c')
		return (ft_flag_c(lst, va, 0));
	if (lst->convert == 'p')
		return (ft_flag_p(lst, va, 0));
	if (lst->convert == '%')
		return (ft_flag_pourc(lst));
	if (lst->convert == 'n')
		ft_flag_n(lst, va);
	return (1);
}
