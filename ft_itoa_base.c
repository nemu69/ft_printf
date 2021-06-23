/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 15:41:28 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 16:52:17 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_base(long int nbr, int *based, int len, char *base)
{
	int			i;
	int			size;
	char		*str;

	i = 0;
	size = ft_base_len(nbr, base);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (len - size)
	{
		str[i++] = '0';
		len--;
	}
	size--;
	while (size >= 0)
	{
		str[i] = base[based[size]];
		size--;
		i++;
	}
	free(based);
	return (str);
}

char	*ft_itoa_base(long int nbr, char *base, int preci)
{
	int			intbase;
	long int	nb;
	int			i;
	int			*based;
	int			len;

	if (preci == 0 && nbr == 0)
		return (ft_strdup("\0"));
	if (nbr < 0)
		return (ft_itoa_base(nbr - 4294967296, base, preci));
	i = 0;
	nb = nbr;
	intbase = ft_strlen(base);
	if (!(based = ft_calloc(ft_base_len(nbr, base), sizeof(int))))
		return (0);
	preci > ft_base_len(nbr, base) ? (len = preci) :
		(len = ft_base_len(nbr, base));
	while (nb >= intbase)
	{
		based[i++] = nb % intbase;
		nb /= intbase;
	}
	based[i] = nb % intbase;
	return (ft_print_base(nbr, based, len, base));
}
