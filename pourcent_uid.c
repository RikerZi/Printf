/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcent_uid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:24:52 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 11:08:34 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//__________________________fonction for %i & %d__________________________//
int	ft_pourcent_id_init(va_list lst)
{
	size_t			len;
	int				n;

	len = 0;
	n = va_arg(lst, int);
	len = ft_pourcent_id(n);
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
		len++;
	}
	if (nb >= 10)
		len += ft_pourcent_id(nb / 10);
	ft_putchar(nb % 10 + 48);
	len++;
	return (len);
}

//__________________________fonction for %u_______________________________//
int	ft_pourcent_u_init(va_list lst)
{
	size_t			len;
	unsigned int	n;

	n = va_arg(lst, unsigned int);
	len = ft_pourcent_u(n);
	return (len);
}

int	ft_pourcent_u(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n >= 10)
		len += ft_pourcent_u(n / 10);
	ft_putchar(n % 10 + 48);
	len++;
	return (len);
}
