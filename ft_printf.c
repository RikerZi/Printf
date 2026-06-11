/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:24:44 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 10:35:37 by raahouar         ###   ########.fr       */
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
	else if (c == 'd' || c == 'i')
		len = ft_pourcent_id_init(lst);
	else if (c == 'u')
		len = ft_pourcent_u_init(lst);
	else if (c == 'x' || c == 'X')
		len = ft_pourcent_xx_init(lst, c);
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

// #include <stdio.h>

// int	main(void)
// {
// 	int	*p;
// 	int	a;

// 	a = 5555;
// 	p = &a;
// 	ft_printf("%d\n", ft_printf("%d\n", 7533));
// 	printf("%d\n", printf("%d\n", 7533));
// 	return (0);
// }
