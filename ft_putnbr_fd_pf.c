/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:10:08 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/20 19:56:48 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_numcount(int nb)
{
	int	c;

	c = 0;
	if (nb <= 0)
		c++;
	while (nb)
	{
		nb /= 10;
		c++;
	}
	return (c);
}

int	ft_putnbr_fd_pf(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd_pf('-', fd);
	}
	if (nb > 9)
	{
		ft_putnbr_fd_pf(nb / 10, fd);
		ft_putchar_fd_pf((nb % 10 + '0'), fd);
	}
	else
	{
		ft_putchar_fd_pf((nb + '0'), fd);
	}
	count = ft_numcount(nb);
	return (count);
}
