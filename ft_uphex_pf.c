/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:05:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/22 18:38:12 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

static void	ft_reverse(char* str)
{
	int first;
	int last;
	char temp;

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

static char	*ft_hex(int num)
{
	int	count;
	char	*hex;
	char	*ptr;

	count = ft_hexcount(num) + 1;
	hex = (char *)malloc((count + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	if (num < 0)
	{
		ft_putchar_fd_pf('-', 1);
		num *= -1;
	}
	ptr = hex;
	while (--count)
	{
		if (num % 16 < 10)
			*ptr = (num % 16) + '0';
		else if (num % 16 > 9)
			*ptr = (num % 16) + 'A' - 10;
		num /= 16;
		ptr++;
	}
	*ptr = '\0';
	return (hex);
}

int	ft_uphex_pf(int num)
{
	char	*hex;
	int		count;

	hex = ft_hex(num);
	count = ft_strlen_pf(hex);
	ft_reverse(hex);
	ft_putstr_fd_pf(hex, 1);
	free(hex);
	return (count);
}

/* int main()
{
	ft_uphex_pf(960);
} */