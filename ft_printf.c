/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:31:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/22 17:23:03 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_type(const char format, va_list list)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_fd_pf(va_arg(list, int), 1);
	else if (format == 's')
		count += ft_putstr_fd_pf(va_arg(list, char *), 1);
	else if (format == 'x')
		count += ft_lowhex_pf(va_arg(list, int));
	else if (format == 'X')
		count += ft_uphex_pf(va_arg(list, int));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_fd_pf(va_arg(list, int), 1);
	else if (format == 'u')
		count += ft_putnbr_fd_pf(va_arg(list, unsigned int), 1);
	else if (format == 'p')
	{
		count += ft_putstr_fd_pf("0x", 1);
		count += ft_lowhex_pf(va_arg(list, int));
	}
	else if (format == '%')
		count += ft_putchar_fd_pf('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;

	count = 0;
	va_list list;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_type(*format, list);
			va_arg(list, void *);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(list);
	return(count);
}

int main()
{
	int result;
	int real;
	real = printf("Ola %s, tens %d anos andas na %x ou %X\n", "Diogo", 19, 42, 42);
	result = ft_printf("Ola %s, tens %d anos andas na %x ou %X\n", "Diogo", 19, 42, 42);
	printf("real: %d \nfake: %d", real, result);
}