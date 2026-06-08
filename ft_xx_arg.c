/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:34:33 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 19:17:33 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xx_arg(char *str, unsigned int n)
{
	size_t	len;

	if (n == 0)
		len = 0;
	if (n > 15)
		ft_xx_arg(str, n / 16);
	ft_putchar(str[n % 16]);
	len++;
	return (len);
}
