/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_uid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:24:52 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/08 11:24:54 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pourcent_uid(va_list lst, char c)
{
	size_t			len;
	int	n;
	unsigned int	m;

	len = 0;
	if (c == 'd' || c == 'i')
	{
		n = va_arg(lst, int);
		len = ft_pourcent_id(n);
	}
	else if (c == 'u')
	{
		n = va_arg(lst, unsigned int);
		len = ft_pourcent_u(m);
	}
	return (len);
}

int	ft_pourcent_id(int n)
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
		ft_pourcent_id(nb / 10);
	ft_putchar(nb % 10 + 48);
	len++;
	return (len);
}

int	ft_pourcent_u(unsigned int n)
{
	size_t	len;

	len = 0;
	if (nb >= 10)
		ft_pourcent_u(nb / 10);
	ft_putchar(nb % 10 + 48);
	len++;
	return (len);
}
