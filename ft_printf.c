/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:25:46 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:52:32 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_notpercent(t_list *lst, char *str, int i)
{
	size_t temp;

	temp = i;
	while (str[i] && str[i] != '%')
		i++;
	lst->content = ft_substr(str, temp, i - temp);
	return (i);
}

int		ft_if_percent(t_list *lst, char *str, int i, va_list va)
{
	if (!(i = ft_pourcent(lst, str, i + 1, va)) ||
			!(ft_create_content(lst, va)))
		return (0);
	return (i);
}

int		ft_printf_suite(t_list *lst, va_list va, char *str)
{
	size_t i;

	i = 0;
	while (lst)
	{
		if (str[i] == '%')
		{
			if (!(i = ft_if_percent(lst, str, i, va)))
				return (0);
		}
		else
			i = ft_notpercent(lst, str, i);
		if (str[i])
			if (!(lst->next = ft_lstnew(0)))
				return (0);
		lst = lst->next;
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list va;
	t_list	*lst;
	t_list	*premier;

	lst = ft_lstnew(0);
	premier = lst;
	va_start(va, str);
	if (!ft_printf_suite(lst, va, (char *)str))
	{
		ft_lstclear(&premier, free);
		va_end(va);
		return (-1);
	}
	va_end(va);
	return (ft_printf_print(premier));
}
