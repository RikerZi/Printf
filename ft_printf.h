/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 07:55:37 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/03 19:56:31 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_c_arg(va_list lst);
int		ft_s_arg(va_list lst);
int		ft_di_arg(int n);
int		ft_u_arg(unsigned int n);
int		ft_xx_arg(char *str, unsigned int n);
int		ft_p_arg(char *str, size_t len, unsigned long n);
void	ft_putchar(char c);
int		ft_write_all(char *str);
int		ft_init_dix(va_list lst, char c);
int		ft_init_xx(va_list lst, char c);
int		ft_init_ptr(va_list lst);
int		ft_printf(const char *str, ...);

#endif
