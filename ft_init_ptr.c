/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:44:26 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 17:51:20 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_ptr(va_list lst)
{
	size_t			len;
	unsigned long	n;
	char			*str;

	len = 0;
	str = "0123456789abcdef";
	n = va_arg(lst, unsigned long);
	len = ft_p_arg(str, len, n);
	return (len);
}
