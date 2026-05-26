/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikerzi <rikerzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:41:09 by raahouar          #+#    #+#             */
/*   Updated: 2026/05/26 16:51:05 by rikerzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i++);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_strlen("bonjour"));
// 	return (0);
// }