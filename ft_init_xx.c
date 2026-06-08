/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:42:30 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 19:57:14 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_xx(va_list lst, char c)
{
	size_t			len;
	char			*str;
	unsigned int	n;

	len = 0;
	if (c == 'x')
	{
		str = "0123456789abcdef";
		n = va_arg(lst, unsigned int);
		len = ft_xx_arg(str, n);
	}
	else if (c == 'X')
	{
		str = "0123456789ABCDEF";
		n = va_arg(lst, unsigned int);
		len = ft_xx_arg(str, n);
	}
	return (len);
}
