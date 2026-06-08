/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:25:04 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/08 11:25:06 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pourcent_xx(va_list lst, char c)
{
	size_t			len;
	char			*str;
	unsigned int	n;

	len = 0;
	if (c == 'x')
	{
		str = "0123456789abcdef";
		n = va_arg(lst, unsigned int);
		len = ft_pourcent_x(str, n);
	}
	else if (c == 'X')
	{
		str = "0123456789ABCDEF";
		n = va_arg(lst, unsigned int);
		len = ft_pourcent_x(str, n);
	}
	return (len);
}

int	ft_pourcent_x(char *str, unsigned int n)
{
	size_t	len;

	if (n == 0)
		len = 0;
	if (n > 15)
		ft_pourcent_x(str, n / 16);
	ft_putchar(str[n % 16]);
	len++;
	return (len);
}
