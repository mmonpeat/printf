/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlibft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:51 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/01/26 17:50:56 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)//cada vegada que fa if, fa el write
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar (s[i]);
		i++;
	}
	return (s[i]);
}

int	ft_putusnum(unsigned int u)
{
	char	digit;
	int		i;

	i = 0;
	if (u < 10)
	{
		digit = u + '0';
		if (write(1, &digit, 1) != 1)
			return (-1);
		return (1);
	}
	else if (u > 9)
	{
		i += ft_putnum(u / 10);
		i += ft_putnum(u % 10);
	}
	return (i);
}

int	ft_putnum(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		i++;//sumes el -
		n = -n;
	}	
	i = ft_putaux(n, i);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_putaux(int n, int i)
{
	char	digit;

	if (n < 10)
	{
		digit = n + '0';
		if (write(1, &digit, 1) != 1)
			return (-1);
		return (1);
	}
	else if (n > 10)
	{
		i += ft_putnum(n / 10);
		i += ft_putnum(n % 10);
	}
	return (i);
}
