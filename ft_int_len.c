/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int_len.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 22:42:36 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:56:38 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_int_nega_len(long long int value)
{
	int l;

	l = 0;
	if (value > -1)
		return (0);
	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}

int			ft_int_len(long long int value)
{
	int l;

	l = 1;
	if (value < 0)
		l = 0;
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l == 0 ? ft_int_nega_len(value) : l);
}
