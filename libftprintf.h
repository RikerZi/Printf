#ifndef LIBFT_PRINTF_H
#define LIBFT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int	ft_write_all(char *str);
#endif
