/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:51:18 by diogribe          #+#    #+#             */
/*   Updated: 2024/12/18 19:24:16 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_reverse(char *str)
{
	int		first;
	int		last;
	char	temp;

	first = 0;
	last = ft_strlen(str) - 1;
	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}

int	ft_memprint(unsigned long long num, char *base)
{
	int		count;
	int		i;
	int		temp;
	char	*mem;

	mem = (char *)malloc(16 + 1 * sizeof(char));
	count = 0;
	i = 0;
	count += ft_putstr_fd("0x", 1);
	while (i <= 16 && num > 0)
	{
		temp = num % 16;
		num /= 16;
		mem[i] = base[temp];
		i++;
	}
	ft_reverse(mem);
	mem[i] = '\0';
	count += ft_putstr_fd(mem, 1);
	free(mem);
	return (count);
}
