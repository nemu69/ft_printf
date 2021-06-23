/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilsprintf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/01 07:04:53 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 15:14:42 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' ||
			c == 'X' || c == '%' || c == 'n')
		return (1);
	return (0);
}

int		ft_is_flag(char c, t_list *lst)
{
	if (!lst->flag || lst->flag == c)
	{
		if (c == ' ' || c == '+' || c == '#')
		{
			lst->flag = c;
			return (1);
		}
	}
	if (c == '0' && !lst->minus)
	{
		lst->zero = 1;
		return (1);
	}
	if (c == '-')
	{
		lst->minus = 1;
		lst->zero = 0;
		return (1);
	}
	if (!ft_is_conv(c) && c != '*' && c != '.' && !ft_isdigit(c))
		lst->error = 1;
	return (0);
}

int		ft_pourcent(t_list *lst, char *str, int i, va_list va)
{
	while (ft_is_flag(str[i], lst))
		i++;
	if (lst->error)
		return (0);
	str[i] == '*' ? (lst->width = va_arg(va, int)) :
		(lst->width = ft_atoi(str + i));
	if (str[i] == '*' && lst->width < 0)
	{
		lst->minus = 1;
		lst->zero = 0;
		lst->width *= -1;
	}
	str[i] == '*' ? i++ : i;
	while ((!ft_is_conv(str[i]) && str[i] != '.') || ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		str[i + 1] == '*' ? (lst->preci = va_arg(va, int))
			: (lst->preci = ft_atoi(str + i + 1));
	while (str[i] && !ft_is_conv(str[i]))
		i++;
	if (ft_is_conv(str[i]))
		lst->convert = str[i];
	else
		return (0);
	return (i + 1);
}

int		count_unsi(t_list *lst, char c, unsigned int conint)
{
	int	len;
	int space;

	if (lst->preci == 0 && conint == 0)
		return (lst->width);
	c == 'u' ? (len = ft_unint_len(conint)) :
		(len = ft_base_len(conint, "0123456789ABCDEF"));
	lst->preci > len ? (space = lst->preci) :
		(space = len);
	if (lst->preci == 0 && lst->width == 0 && conint == 0)
		lst->error = 2;
	return (space < lst->width ? lst->width - space : 0);
}

int		count_malloc_int(t_list *lst, int conint)
{
	int space;
	int flagspace;
	int len;

	if (lst->preci == 0 && conint == 0)
		return (lst->width);
	len = ft_int_len(conint);
	if (lst->flag == ' ' && conint > -1)
		flagspace = 1;
	if (lst->flag == '+' && conint > -1)
		flagspace = 1;
	len < lst->preci ? (space = lst->preci) :
		(space = len);
	if (lst->preci == 0 && lst->width == 0 && conint == 0)
		lst->error = 2;
	return (space < lst->width ? lst->width - space : 0);
}
