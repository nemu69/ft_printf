/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_print.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 07:17:58 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 06:36:18 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_lst(t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		if (lst->convert == 'c')
			count += lst->width;
		else
			count += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (count);
}

int		ft_count_lstn(t_list *lst, t_list *arret)
{
	int count;

	count = 0;
	while (lst != arret)
	{
		count += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (count);
}

void	ft_flagc(t_list *lst)
{
	int i;

	i = 0;
	while (i < lst->width)
		ft_putchar_fd(lst->content[i++], 1);
}

void	ft_flagn(t_list *lst, t_list *premier)
{
	int		*nbr;

	nbr = (int *)lst->flagn;
	nbr[0] = ft_count_lstn(premier, lst);
}

int		ft_printf_print(t_list *lst)
{
	t_list	*premier;
	int		count;

	premier = lst;
	lst = premier;
	while (lst)
	{
		if (lst->flag == ' ')
			ft_flagsp(lst);
		if (lst->convert == 'n')
			ft_flagn(lst, premier);
		if (lst->convert == 'c')
			ft_flagc(lst);
		else
			ft_putstr_fd(lst->content, 1);
		lst = lst->next;
	}
	count = ft_count_lst(premier);
	ft_lstclear(&premier, free);
	return (count);
}
