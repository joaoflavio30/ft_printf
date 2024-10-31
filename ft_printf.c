#include "ft_printf.h"

int	print_specify_format(va_list args, char c)
{
	int	sum;

	sum = 0;
	if (c == 'd' || c == 'i')
		sum = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		sum = ft_putnbr(va_arg(args, unsigned int));
	else if (c == 's')
		sum = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'x')
		sum = ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		sum = ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (c == 'c')
		sum = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'p')
		sum = ft_print_void(va_arg(args, void *));
	else if (c == '%')
		sum = ft_putchar_fd('%', 1);
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		sum;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	sum = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			sum += print_specify_format(args, format
				[++i]);
		else
			sum += ft_putchar_fd(format[i], 1);
	}
	va_end(args);
	return (sum);
}
//   int main()
//   {
//       #include <stdio.h>
//       ft_printf(" %d\n", ft_printf(0));
//       printf(" %d\n" ,printf(0));
//   }
