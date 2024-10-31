#include "ft_printf.h"

int	ft_putnbr(unsigned int n)
{
	long long	nbr;
	int			sum;

	sum = 0;
	nbr = n;
	if (nbr < 0)
	{
		sum += ft_putchar_fd('-', 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		sum += ft_putnbr(nbr / 10);
	}
	sum += ft_putchar_fd((nbr % 10) + '0', 1);
	return (sum);
}

int	ft_putnbr_hex(unsigned	long n, int is_upper)
{
	int				sum;
	unsigned long	nbr;

	sum = 0;
	nbr = n;
	if (nbr / 16 != 0)
		sum += ft_putnbr_hex(nbr / 16, is_upper);
	if ((nbr % 16 >= 10 && nbr % 16 <= 15) && is_upper)
		sum += ft_putchar_fd('A' + (nbr % 16 - 10), 1);
	else if ((nbr % 16 >= 10 && nbr % 16 <= 15))
		sum += ft_putchar_fd('a' + (nbr % 16 - 10), 1);
	else
		sum += ft_putchar_fd((nbr % 16) + '0', 1);
	return (sum);
}

int	ft_print_void(void *n)
{
	int				sum;
	unsigned long	ptr;

	sum = 0;
	ptr = (unsigned long)n;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	sum += ft_putstr_fd("0x", 1);
	sum += ft_putnbr_hex(ptr, 0);
	return (sum);
}
