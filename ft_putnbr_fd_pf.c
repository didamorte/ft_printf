/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:10:08 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/27 18:53:03 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_pf(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar_fd_pf('-', fd);
	}
	if (nb > 9)
	{
		count += ft_putnbr_fd_pf(nb / 10, fd);
		count += ft_putchar_fd_pf((nb % 10 + '0'), fd);
	}
	else
	{
		count += ft_putchar_fd_pf((nb + '0'), fd);
	}
	return (count);
}
