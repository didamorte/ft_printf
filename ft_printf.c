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
		ft_putchar_fd_pf(va_arg(list, int), 1);
	else if (format == 's')
		ft_putstr_fd_pf(va_arg(list, char *), 1);
	else if (format == 'x')
		ft_lowhex_pf(va_arg(list, int));
	else if (format == 'X')
		ft_uphex_pf(va_arg(list, int));
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd_pf(va_arg(list, int), 1);
	else if (format == 'u')
		ft_putnbr_fd_pf(va_arg(list, unsigned int), 1);
	else if (format == 'p')
	{
		ft_putstr_fd_pf("0x", 1);
		ft_lowhex_pf(va_arg(list, int));
	}
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
			count += ft_type(*(++format), list);
			format++;
		}
		count += write(1, &(*format) , 1);
		format++;
	}
	va_end(list);
	return(count);
}

int main()
{
	ft_printf("Ola %s, tens %d anos", "Diogo", 19);
}