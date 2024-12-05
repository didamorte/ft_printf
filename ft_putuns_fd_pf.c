/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:49:54 by diogribe          #+#    #+#             */
/*   Updated: 2024/12/05 16:14:50 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns_fd_pf(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if ((int)nb < 0)
	{
		write(fd, "4294967295", 10);
		return (10);
	}
	if (nb > 9)
	{
		count += ft_putuns_fd_pf(nb / 10, fd);
		count += ft_putchar_fd_pf((nb % 10 + '0'), fd);
	}
	else
	{
		count += ft_putchar_fd_pf((nb + '0'), fd);
	}
	return (count);
}
