#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			sum;

	sum = 0;
	nbr = n;
	if (nbr < 0)
	{
		sum += ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		sum += ft_putnbr_fd(nbr / 10, fd);
	}
	sum += ft_putchar_fd((nbr % 10) + '0', fd);
	return (sum);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
