/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:24:58 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 11:09:06 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//__________________________fonction for %p_______________________________//
int	ft_pourcent_ptr(va_list lst)
{
	size_t			len;
	unsigned long	n;
	char			*str;

	len = 0;
	str = "0123456789abcdef";
	n = va_arg(lst, unsigned long);
	len = ft_pourcent_p(str, n);
	return (len);
}

int	ft_pourcent_p(char *str, unsigned long n)
{
	size_t	len;

	if (n == 0)
	{
		ft_write_all("(nil)");
		return (5);
	}
	len = 0;
	if (n > 15)
		len += ft_pourcent_p(str, n / 16);
	else
	{
		ft_write_all("0x");
		len += 2;
	}
	ft_putchar(str[n % 16]);
	len++;
	return (len);
}
