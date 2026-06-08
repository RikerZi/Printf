/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:41:18 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 20:13:29 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_dix(va_list lst, char c)
{
	size_t			len;
	int	n;
	unsigned int	m;

	len = 0;
	if (c == 'd' || c == 'i')
	{
		n = va_arg(lst, int);
		len = ft_di_arg(n);
	}
	else if (c == 'u')
	{
		n = va_arg(lst, unsigned int);
		len = ft_u_arg(m);
	}
	return (len);
}
