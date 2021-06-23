/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:22:28 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 06:45:29 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_who_big(long long int n, int preci)
{
	int len;

	len = ft_int_len(n);
	return (len > preci ? len : preci);
}

static char		*readstr(char *str, int preci, long long int n, long int i)
{
	int len;
	int nega;

	str[0] == '-' ? (nega = 1) :
		(nega = 0);
	len = ft_int_len(n);
	while (preci > len++)
		str[nega++] = '0';
	while (i >= 1)
	{
		str[nega++] = n / i + '0';
		n %= i;
		i /= 10;
	}
	return (str);
}

char			*ft_itoa(long int n, int preci)
{
	long int	i;
	char		*str;
	int			nega;

	nega = 0;
	i = 1;
	if (n == 0 && preci == 0)
		return (ft_strdup(""));
	if (n < 0)
	{
		nega++;
		n *= -1;
	}
	while (i * 10 <= n)
		i *= 10;
	if (!(str = ft_calloc(sizeof(char), (ft_who_big(n, preci) + nega + 1))))
		return (NULL);
	if (nega == 1)
		str[0] = '-';
	return (readstr(str, preci, n, i));
}
