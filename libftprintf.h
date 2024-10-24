#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int     ft_printf(const char *, ...);
void    ft_putnbr(unsigned int n);
void	ft_putnbr_hex(unsigned long long n, int is_upper);
int     print_void(void *p);

#endif
