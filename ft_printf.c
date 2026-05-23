/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 05:18:47 by raahouar          #+#    #+#             */
/*   Updated: 2026/05/23 05:48:56 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	size_t	i;
	size_t	len;

	va_start(lst, str);
	while (str[i])
	{

	}
}

#include <stdio.h>
int	main(void)
{

	ft_printf("je suis ft_printf");
	printf("je suis printf");
	return (0);
}
