/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uputnbr_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 03:34:19 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:58:26 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void			ft_uputnbr_fd(long int n, int fd)
{
	unsigned int div;
	unsigned int mod;

	if (n < 0)
		ft_uputnbr_fd(n - 4294967296, fd);
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}
