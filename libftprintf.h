#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int     ft_printf(const char *, ...);
void    ft_putunsignednbr(unsigned int n);
void	ft_putunsignednbr_hex(unsigned int n, int is_upper);

#endif
