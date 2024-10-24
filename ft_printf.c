#include "libftprintf.h"
#include "../../libft/libft.h"

void print_specify_format(va_list args, char c)
{
    if (c == 'd' || c == 'i')
        ft_putnbr_fd(va_arg(args, int), 1);
    else if (c == 'u')
        ft_putnbr(va_arg(args, unsigned int));
    else if (c == 's')
        ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == 'x')
        ft_putnbr_hex(va_arg(args, unsigned int), 0);
    else if (c == 'X')
        ft_putnbr_hex(va_arg(args, unsigned int), 1);
    else if(c == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
    else if(c == 'p')
    {
        print_void(va_arg(args, void *));
    }
    else 
        ft_putchar_fd('%', 1);
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list args;

    va_start(args, format);

    i = -1;
    while (format[++i])
    {
        if(format[i] == '%')
            print_specify_format(args, format
            [++i]);
        else
            ft_putchar_fd(format[i], 1);
    }

    va_end(args);
    return i;
}

int main()
{
    #include <stdio.h>
    // int age = 24;
    ft_printf("Olá meu nome é %s e tenho %% anos\n", "João");
    printf("Olá meu nome é %s e tenho %% anos\n", "João");

   // ft_printf("%d\n",ft_printf("abcdef\n"));
   // printf("%d\n", printf("abcdef\n"));
}