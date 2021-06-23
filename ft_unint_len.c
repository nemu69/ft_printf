/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unint_len.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 18:48:08 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 06:42:38 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_unint_len(long long int value)
{
	int l;

	l = 1;
	if (value < 0)
		return (ft_unint_len(4294967296 + value));
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l);
}
