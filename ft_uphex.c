/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:05:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/12/18 19:25:32 by diogribe         ###   ########.fr       */
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

int	ft_uphex(unsigned int num, char *base)
{
	int		count;
	int		i;
	int		temp;
	char	*hex;

	if (num == 0)
		return (ft_putchar_fd('0', 1));
	hex = (char *)malloc(16 + 1 * sizeof(char));
	count = 0;
	i = 0;
	while (i <= 16 && num > 0)
	{
		temp = num % 16;
		num /= 16;
		hex[i] = base[temp];
		i++;
	}
	ft_reverse(hex);
	hex[i] = '\0';
	count += ft_putstr_fd(hex, 1);
	free(hex);
	return (count);
}