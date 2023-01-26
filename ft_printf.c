/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:00 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/01/26 17:43:02 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	va_list	ptr;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(ptr, str);//el primer bytesument/parametre es str
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			bytes += write (1, &str[i],  1);
			i++;//conta caracters que hi ha al str
		}
		else
		{
			//i = i + print_percent((char *)(str + i), ptr, bytes);
			bytes +=  print_percent((char *)(str + i + 1), ptr);
			i += 2;	// Para saltarse el %i <-- Cualquier formato
			//printf("\nbytes in function: %i\n", bytes);
		}
	}
	va_end (ptr);
	//return (i);
	return (bytes);
}

int	print_percent(char *str, va_list ptr)//, int bytes)
{
	if (*str == 'c')
		return (ft_putchar (va_arg(ptr, int)));//es int ascii, un caracter
	else if (*str == 's')
		return (ft_putstr (va_arg(ptr, char *)));
	/*else if (*str == 'p')//void * == unsigned long
		putvoid(va_bytes(ptr, unsigned long));*/
	else if (*str == 'i' || *str == 'd')
		return (ft_putnum (va_arg(ptr, int)));
	else if(*str == 'u')
		ft_putusnum(va_arg(ptr, unsigned int));
	/*else if(*str == 'x')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if(*str == 'X')
		ft_puthex(va_arg(ptr, unsigned int), "0123456789ABCDEF");*/
	else if(*str == '%')
		return (ft_putchar('%'));
	return (0);
}

