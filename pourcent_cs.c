/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:25:10 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 11:09:36 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//__________________________fonction for %s_______________________________//
int	ft_pourcent_s(va_list lst)
{
	char	*str;
	size_t	len;

	str = va_arg(lst, char *);
	len = ft_write_all(str);
	return (len);
}

//__________________________fonction for %c_______________________________//
int	ft_pourcent_c(va_list lst)
{
	char	c;

	c = va_arg(lst, int);
	ft_putchar(c);
	return (1);
}
