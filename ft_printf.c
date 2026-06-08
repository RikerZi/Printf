/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:24:44 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/08 11:24:48 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_write_all(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int	ft_check(char c, va_list lst)
{
	size_t	len;

	len = 0;
	if (c == '%')
	{
		ft_putchar('%');
		len++;
	}
	else if (c == 'c')
		len = ft_pourcent_c(lst);
	else if (c == 's')
		len = ft_pourcent_s(lst);
	else if (c == 'd' || c == 'i' || c == 'u')
		len = ft_pourcent_uid(lst, c);
	else if (c == 'x' || c == 'X')
		len = ft_pourcent_xx(lst, c);
	else if (c == 'p')
		len = ft_pourcent_ptr(lst);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	size_t	len;

	va_start(lst, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_check(str[i], lst);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(lst);
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	*c;

	a = 16;
	c = &a;
	ft_printf("je test mon printf, %c %s %i %X %p %d %u\n", 'l',"e nombre de char est :", 534, a, c, 552, 51);
	printf("je test mon printf, %c %s %i %X %p %d %u\n", 'l',"e nombre de char est :", 534, a, c, 552, 51);
	return (0);
}
*/
