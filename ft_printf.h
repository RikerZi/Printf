/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raahouar <raahouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:25:46 by raahouar          #+#    #+#             */
/*   Updated: 2026/06/11 10:33:35 by raahouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_write_all(char *str);
int		ft_printf(const char *str, ...);
int		ft_pourcent_c(va_list lst);
int		ft_pourcent_s(va_list lst);
int		ft_pourcent_u_init(va_list lst);
int		ft_pourcent_u(unsigned int n);
int		ft_pourcent_xx(char *str, unsigned int n);
int		ft_pourcent_p(char *str, unsigned long n);
int		ft_pourcent_id(int n);
int		ft_pourcent_id_init(va_list lst);
int		ft_pourcent_xx_init(va_list lst, char c);
int		ft_pourcent_ptr(va_list lst);

#endif
