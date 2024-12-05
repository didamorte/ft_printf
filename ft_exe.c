/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:27:52 by diogribe          #+#    #+#             */
/*   Updated: 2024/12/05 16:44:43 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

/* int main()
{
	int real = 0;
	int fake = 0;

	real += printf("Character: %c\n", 'A');
	fake += ft_printf("Character: %c\n", 'A');

	real += printf("Null character: %c\n", '\0');
	fake += ft_printf("Null character: %c\n", '\0');

	real += printf("Empty string: %s\n", "");
	fake += ft_printf("Empty string: %s\n", "");

	real += printf("Null string: %p\n", NULL);
	fake += ft_printf("Null string: %p\n", NULL);

	real += printf("Regular string: %s\n", "Hello, World!");
	fake += ft_printf("Regular string: %s\n", "Hello, World!");

	real += printf("Null pointer: %p\n", NULL);
	fake += ft_printf("Null pointer: %p\n", NULL);

	real += printf("Valid pointer: %p\n", &ft_printf);
	fake += ft_printf("Valid pointer: %p\n", &ft_printf);

	real += printf("Positive integer: %d\n", 42);
	fake += ft_printf("Positive integer: %d\n", 42);

	real += printf("Negative integer: %d\n", -42);
	fake += ft_printf("Negative integer: %d\n", -42);

	real += printf("Zero integer: %d\n", 0);
	fake += ft_printf("Zero integer: %d\n", 0);

	real += printf("Minimum integer: %d\n", INT_MIN);
	fake += ft_printf("Minimum integer: %d\n", INT_MIN);

	real += printf("Maximum integer: %d\n", INT_MAX);
	fake += ft_printf("Maximum integer: %d\n", INT_MAX);

	real += printf("Zero unsigned: %u\n", 0);
	fake += ft_printf("Zero unsigned: %u\n", 0);

	real += printf("Positive unsigned: %u\n", 42);
	fake += ft_printf("Positive unsigned: %u\n", 42);

	real += printf("Maximum unsigned: %u\n", UINT_MAX);
	fake += ft_printf("Maximum unsigned: %u\n", UINT_MAX);

	real += printf("Zero hex: %x\n", 0);
	fake += ft_printf("Zero hex: %x\n", 0);

	real += printf("Positive hex: %x\n", 42);
	fake += ft_printf("Positive hex: %x\n", 42);

	real += printf("Maximum unsigned hex: %x\n", UINT_MAX);
	fake += ft_printf("Maximum unsigned hex: %x\n", UINT_MAX);

	real += printf("Negative number hex: %x\n", -1);
	fake += ft_printf("Negative number hex: %x\n", -1);

	real += printf("Zero HEX: %X\n", 0);
	fake += ft_printf("Zero HEX: %X\n", 0);

	real += printf("Positive HEX: %X\n", 42);
	fake += ft_printf("Positive HEX: %X\n", 42);

	real += printf("Maximum unsigned HEX: %X\n", UINT_MAX);
	fake += ft_printf("Maximum unsigned HEX: %X\n", UINT_MAX);

	real += printf("Negative number HEX: %X\n", -1);
	fake += ft_printf("Negative number HEX: %X\n", -1);

	real += printf("Percent sign: %%\n");
	fake += ft_printf("Percent sign: %%\n");

	real += printf("Multiple percent signs: %% %% %%\n");
	fake += ft_printf("Multiple percent signs: %% %% %%\n");

	real += printf("Mixed types: %d %s %c %x %p\n",
	42, "Hello", 'A', 255, &ft_printf);
	fake += ft_printf("Mixed types: %d %s %c %x %p\n",
	42, "Hello", 'A', 255, &ft_printf);

	printf("real: %d\nfake: %d\n", real, fake);
} */

/* int main()
{
	int fake = 0;
	int real = 0;
	real += printf("char real: %c, %c, %c\n", 'D', 0, '\0');
	fake += ft_printf("char fake: %c, %c, %c\n", 'D', 0, '\0');

	real += printf("string real: %s, %s, %p\n", "Diogo", "", NULL);
	fake += ft_printf("string fake: %s, %s, %p\n", "Diogo", "", NULL);

	real += printf("numero real: %d, %i, %i, %u\n", 42, 21, -42, -21);
	fake += ft_printf("numero fake: %d, %i, %i, %u\n", 42, 21, -42, -21);

	real += printf("hex real: %x, %x, %x, %x\n", 0, 21, -1234, -21);
	fake += ft_printf("hex fake: %x, %x, %x, %x\n", 0, 21, -1234, -21);
	
	real += printf("HEX real: %X, %X, %X, %X\n", 0, 21, -42, -21);
	fake += ft_printf("HEX fake: %X, %X, %X, %X\n", 0, 21, -42, -21);

	real += printf("mem real: %p, %p, %p, %p\n",
	 (void *)42, (void *)21, (void *)-42, (void *)-21);
	fake += ft_printf("mem fake: %p, %p, %p, %p\n",
	 (void *)42, (void *)21, (void *)-42, (void *)-21);
	printf("real: %d \nfake: %d", real, fake);
} */