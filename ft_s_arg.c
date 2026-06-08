/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:20:11 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 17:51:20 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_arg(va_list lst)
{
	char	*str;
	size_t	len;

	str = va_arg(lst, char *);
	len = ft_write_all(str);
	return (len);
}
