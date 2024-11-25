/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:38:20 by diogribe          #+#    #+#             */
/*   Updated: 2024/11/20 19:58:30 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

/* printf */
int		ft_printf(const char *, ...);

/*Retorna o tamanho da string*/
size_t	ft_strlen_pf(const char *s);

/*Put number num file descriptor*/
void	ft_putnbr_fd_pf(int nb, int fd);
/*escreve um \n no final de uma string ou file*/
void	ft_putendl_fd_pf(char *s, int fd);
/*escreve uma string*/
void	ft_putstr_fd_pf(char *s, int fd);
/*escreve um caracter*/
void	ft_putchar_fd_pf(char c, int fd);
/*converte de decimal pra hex*/
void	ft_lowhex_pf(int num);
/*converte de decimal pra hex*/
void	ft_uphex_pf(int num);
#endif