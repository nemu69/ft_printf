/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/31 23:05:49 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:58:01 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_who_big2(long long int n, int preci)
{
	int len;

	len = ft_unint_len(n);
	return (len > preci ? len : preci);
}

static char		*readstr2(char *str, int preci, long long int n, long int i)
{
	int len;
	int nega;

	nega = 0;
	len = ft_unint_len(n);
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

char			*ft_utoa(long long int n, int preci)
{
	long long int	i;
	int				len;
	char			*str;

	len = 0;
	i = 1;
	if (n == 0 && preci == 0)
		return (ft_strdup(""));
	if (n < 0)
		return (ft_utoa(n + 4294967296, preci));
	while (i * 10 <= n)
	{
		i *= 10;
		len++;
	}
	if (!(str = ft_calloc(sizeof(char), (ft_who_big2(n, preci) + 1))))
		return (NULL);
	return (readstr2(str, preci, n, i));
}
