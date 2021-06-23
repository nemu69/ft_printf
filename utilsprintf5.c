/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilsprintf5.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 06:35:27 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 06:56:02 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagsp(t_list *lst)
{
	char *join;

	join = ft_strjoin(" ", lst->content);
	free(lst->content);
	lst->content = ft_strdup(join);
	free(join);
}
