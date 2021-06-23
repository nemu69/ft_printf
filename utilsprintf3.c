/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilsprintf3.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 15:25:06 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 06:55:52 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_u(t_list *lst, va_list va, int i)
{
	long	conint;
	char	*constr;
	char	*join;
	char	space;

	conint = va_arg(va, unsigned int);
	if (!(constr = ft_calloc(count_unsi(lst, lst->convert, conint)
					+ 1, sizeof(char))))
		return (0);
	lst->zero && lst->preci == -1 ? (space = '0') :
		(space = ' ');
	if (lst->zero && lst->preci == -1)
		space = '0';
	while (count_unsi(lst, lst->convert, conint))
	{
		lst->width--;
		constr[i++] = space;
	}
	join = ft_utoa(conint, lst->preci);
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(join);
	free(constr);
	return (1);
}

char	*ft_strjoin_hex(t_list *lst)
{
	char *join;

	if (!(join = ft_strdup(lst->content)))
		return (0);
	free(lst->content);
	lst->convert == 'x' ? (lst->content = ft_strjoin("0x", join)) :
		(lst->content = ft_strjoin("0X", join));
	free(join);
	return (0);
}

int		ft_flag_hex(t_list *lst, int i, unsigned int conint)
{
	char	*constr;
	char	*join;
	char	space;

	if (!(constr = ft_calloc(count_unsi(lst, lst->convert, conint) + 1, 1)))
		return (0);
	lst->zero && lst->preci == -1 ? (space = '0') :
		(space = ' ');
	if (lst->flag == '#')
		lst->width -= 2;
	while (count_unsi(lst, lst->convert, conint))
	{
		lst->width--;
		constr[i++] = space;
	}
	lst->convert == 'x' ? (join =
			ft_itoa_base(conint, "0123456789abcdef", lst->preci)) :
		(join = ft_itoa_base(conint, "0123456789ABCDEF", lst->preci));
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	if (lst->flag == '#' && conint != 0)
		ft_strjoin_hex(lst);
	free(join);
	free(constr);
	return (1);
}

int		ft_flag_int(t_list *lst, long int conint)
{
	char	*constr;
	char	*join;
	char	space;

	space = (lst->zero && lst->preci == -1) ? '0' : ' ';
	if ((lst->flag == ' ') || (lst->flag == '+' && conint > -1))
		lst->width--;
	if (!(constr = ft_space_zero(space,
					count_malloc_int(lst, conint), conint, lst)))
		return (0);
	if (space == '0' && conint < 0)
		conint *= -1;
	join = ft_itoa(conint, lst->preci);
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(join);
	free(constr);
	return (1);
}
