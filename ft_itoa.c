/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikerzi <rikerzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:55:48 by raahouar          #+#    #+#             */
/*   Updated: 2026/05/26 16:50:27 by rikerzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}
char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	str = malloc((ft_intlen(nb) * sizeof(char)) + 1);
	i = ft_intlen(nb);
	str[i] = '\0';
	i--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = nb + 48;
	return (str);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int n = -3335;

// 	printf("%s\n", ft_itoa(n));
// }