/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:05:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/27 19:04:48 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexcount(int nb)
{
	int	c;

	c = 1;
	while (nb / 16)
	{
		nb /= 16;
		c++;
	}
	return (c);
}

static void	ft_reverse(char *str)
{
	int		first;
	int		last;
	char	temp;

	first = 0;
	last = ft_strlen_pf(str) - 1;
	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}

static char	*ft_hex(unsigned int num)
{
	int		count;
	char	*hex;
	char	*ptr;

	count = ft_hexcount(num) + 1;
	hex = (char *)malloc((count + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	ptr = hex;
	while (--count)
	{
		if (num % 16 < 10)
			*ptr = (num % 16) + '0';
		else if (num % 16 > 9)
			*ptr = (num % 16) + 'a' - 10;
		num /= 16;
		ptr++;
	}
	*ptr = '\0';
	return (hex);
}

int	ft_lowhex_pf(unsigned int num)
{
	char	*hex;
	int		count;
	int		i;

	hex = ft_hex(num);
	count = ft_strlen_pf(hex);
	i = 8 - count + 1;
	if ((int)num < 0)
		while (--i)
			count += ft_putchar_fd_pf('f', 1);
	ft_reverse(hex);
	ft_putstr_fd_pf(hex, 1);
	free(hex);
	return (count);
}