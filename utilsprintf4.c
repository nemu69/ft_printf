/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilsprintf4.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 16:55:07 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 16:50:35 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_malloc_str(t_list *lst, char *str)
{
	int space;
	int len;

	len = ft_strlen(str);
	lst->width < len ? (space = len) :
		(space = lst->width);
	return (space - len);
}

int		count_malloc_char(t_list *lst)
{
	int space;
	int len;

	len = 1;
	lst->width < 1 ? (space = 1) :
		(space = lst->width);
	return (space - len);
}

int		count_malloc_ptr(t_list *lst, int strl)
{
	int space;

	lst->width < strl ? (space = strl) :
		(space = lst->width);
	return (space - strl);
}

char	*ft_space_zero(char space, int mallo, int conint, t_list *lst)
{
	int		i;
	char	*constr;

	if (space == '0' && mallo == 0 && conint < 0)
		return (ft_strdup("-"));
	if (!(constr = ft_calloc(mallo + 1, 1)))
		return (0);
	i = 0;
	if (space == '0' && conint < 0)
		lst->width++;
	if (conint < 0)
		lst->width--;
	while (count_malloc_int(lst, conint))
	{
		constr[i++] = space;
		lst->width--;
	}
	if (space == '0' && conint < 0)
		constr[0] = '-';
	return (constr);
}

int		ft_flag_pourc(t_list *lst)
{
	int		mallo;
	char	*constr;
	char	*join;
	int		i;

	i = 0;
	mallo = lst->width;
	if (!(constr = ft_calloc(mallo + 1, 1)))
		return (0);
	while (i < mallo - 1)
		constr[i++] = ' ';
	if (!(join = ft_strdup("%")))
		return (0);
	lst->minus ? (lst->content = ft_strjoin(join, constr)) :
		(lst->content = ft_strjoin(constr, join));
	free(constr);
	free(join);
	return (1);
}
