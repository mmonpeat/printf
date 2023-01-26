/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:46:18 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/01/25 19:58:51 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>

int	ft_printf(char const *str, ...);
int	print_percent(char *str, va_list ptr);//, int arg);
int	ft_putchar(char c);
int	ft_putstr(char *s);
//int	ft_putvoid(unsigned long v, int fd);
int	ft_putnum(int n);
int	ft_putaux(int n, int i);
int	ft_putusnum(unsigned int u);
//int	puthex();

#endif
