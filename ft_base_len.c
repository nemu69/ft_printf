/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_base_len.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 23:08:19 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:50:42 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_base_len(long int n, char *base)
{
	int i;
	int intbase;

	if (n < 0)
		return (ft_base_len(n + 4294967296, base));
	i = 0;
	intbase = 0;
	while (base[intbase] != '\0')
		intbase++;
	while (n >= intbase)
	{
		i++;
		n /= intbase;
	}
	i++;
	return (i);
}
