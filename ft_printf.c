/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:31:38 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/27 19:03:41 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(const char format, va_list list)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_fd_pf(va_arg(list, int), 1);
	else if (format == 's')
		count += ft_putstr_fd_pf(va_arg(list, char *), 1);
	else if (format == 'x')
		count += ft_lowhex_pf(va_arg(list, unsigned int), 'x');
	else if (format == 'X')
		count += ft_uphex_pf(va_arg(list, unsigned int));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_fd_pf(va_arg(list, int), 1);
	else if (format == 'u')
		count += ft_putnbr_fd_pf(va_arg(list, unsigned int), 1);
	else if (format == 'p')
	{
		count += ft_putstr_fd_pf("0x", 1);
		count += ft_lowhex_pf(va_arg(list, int), 'p');
	}
	else if (format == '%')
		count += ft_putchar_fd_pf('%', 1);
	return (count);
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
			format++;
			count += ft_type(*format, list);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (count);
}

/* int main()
{
	int fake = 0;
	int real = 0;
	real += printf("char real: %c, %c, %c\n", 'D', 'i', 'o');
	fake += ft_printf("char fake: %c, %c, %c\n", 'D', 'i', 'o');

	real += printf("string real: %s, %s, %s\n", "Diogo", "teste", "42");
	fake += ft_printf("string fake: %s, %s, %s\n", "Diogo", "teste", "42");

	real += printf("numero real: %d, %i, %i, %d\n", 42, 21, -42, -21);
	fake += ft_printf("numero fake: %d, %i, %i, %d\n", 42, 21, -42, -21);

	real += printf("hex real: %x, %x, %x, %x\n", 42, 21, -1234, -21);
	fake += ft_printf("hex fake: %x, %x, %x, %x\n", 42, 21, -1234, -21);
	
	real += printf("HEX real: %X, %X, %X, %X\n", 42, 21, -42, -21);
	fake += ft_printf("HEX fake: %X, %X, %X, %X\n", 42, 21, -42, -21);

	real += printf("mem real: %p, %p, %p, %p\n", (void *)42, (void *)21, (void *)-42, (void *)-21);
	fake += ft_printf("mem fake: %p, %p, %p, %p\n", (void *)42, (void *)21, -42, (void *)-21);
	printf("real: %d \nfake: %d", real, fake);
} */
