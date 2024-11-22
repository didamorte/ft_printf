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

void	ft_putnbr_fd_pf(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
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
}
