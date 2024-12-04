/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:38:20 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/27 16:04:41 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

/* printf */
int		ft_printf(const char *format, ...);

/*Retorna o tamanho da string*/
size_t	ft_strlen_pf(const char *s);

/*escreve um int*/
int		ft_putnbr_fd_pf(int nb, int fd);
/*escreve um unsined int*/
int		ft_putuns_fd_pf(unsigned int nb, int fd);
/*escreve uma string*/
int		ft_putstr_fd_pf(char *s, int fd);
/*escreve um caracter*/
int		ft_putchar_fd_pf(char c, int fd);
/*converte de decimal pra hex*/
int		ft_lowhex_pf(unsigned int num);
/*converte de decimal pra hex*/
int		ft_uphex_pf(unsigned int num);
/*printa um espaço na memoria em hex*/
int		ft_memprint_pf(unsigned long long num);
#endif