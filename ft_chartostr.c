/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_chartostr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 22:36:28 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:56:14 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chartostr(char c)
{
	char	*str;

	if (!(str = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	str[0] = c;
	return (str);
}
