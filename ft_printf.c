/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:31:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/12/05 15:30:57 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(const char format, va_list list)
{
	if (format == 'c')
		return (ft_putchar_fd_pf(va_arg(list, int), 1));
	else if (format == 's')
		return (ft_putstr_fd_pf(va_arg(list, char *), 1));
	else if (format == 'x')
		return (ft_lowhex_pf(va_arg(list, unsigned int)));
	else if (format == 'X')
		return (ft_uphex_pf(va_arg(list, unsigned int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd_pf(va_arg(list, int), 1));
	else if (format == 'u')
		return (ft_putuns_fd_pf(va_arg(list, unsigned int), 1));
	else if (format == 'p')
		return (ft_memprint_pf(va_arg(list, unsigned long long)));
	else if (format == '%')
		return (ft_putchar_fd_pf('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	list;

	count = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += ft_type(*(++format), list);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (count);
}
