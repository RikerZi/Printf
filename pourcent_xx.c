/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:25:04 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 10:09:00 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//__________________________fonction for %x & %X____________________________//
int	ft_pourcent_xx_init(va_list lst, char c)
{
	size_t			len;
	char			*str;
	unsigned int	n;

	len = 0;
	if (c == 'x')
	{
		str = "0123456789abcdef";
		n = va_arg(lst, unsigned int);
		len = ft_pourcent_xx(str, n);
	}
	else if (c == 'X')
	{
		str = "0123456789ABCDEF";
		n = va_arg(lst, unsigned int);
		len = ft_pourcent_xx(str, n);
	}
	return (len);
}

int	ft_pourcent_xx(char *str, unsigned int n)
{
	size_t	len;

	len = 0;
	if (n > 15)
		len += ft_pourcent_xx(str, n / 16);
	ft_putchar(str[n % 16]);
	len++;
	return (len);
}
