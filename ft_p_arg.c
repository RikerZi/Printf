/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:35:55 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 20:22:19 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_p_arg(char *str, size_t len, unsigned long n)
{
	if (n == 0)
	{
		ft_write_all("(nil)");
		return (4);
	}
	if (n > 15)
		ft_p_arg(str, len, n / 16);
	else
		ft_write_all("0x");
	ft_putchar(str[n % 16]);
	len++;
	return (len);
}
