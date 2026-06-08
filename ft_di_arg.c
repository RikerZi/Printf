/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:29:25 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 21:05:04 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di_arg(int n)
{
	size_t	len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		ft_di_arg(nb / 10);
	ft_putchar(nb % 10 + 48);
	len++;
	return (len);
}
