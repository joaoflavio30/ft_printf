/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardoso <jcardoso@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:14:56 by jcardoso          #+#    #+#             */
/*   Updated: 2024/10/22 10:14:56 by jcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../../libft/libft.h"

void	ft_putnbr(unsigned int n)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar_fd((nbr % 10) + '0', 1);
}

void	ft_putnbr_hex(unsigned long long n, int is_upper)
{
	unsigned long long nbr;

	nbr = n;
	if (nbr / 16 != 0)
	{
		ft_putnbr_hex(nbr / 16, is_upper);
	}
    if (nbr % 16 >= 10 && nbr % 16 <=15 && is_upper)
        ft_putchar_fd('A' + (nbr % 16 - 10),1);
    else if (nbr % 16 >= 10 && nbr % 16 <=15)
        ft_putchar_fd('a' + (nbr % 16 - 10),1);
    else if (nbr % 16 < 10)
        ft_putchar_fd((nbr % 16) + '0', 1);
}
int	print_void(void *p)
{
	unsigned long long n;

	n = (unsigned long long)p;
	if(!n)
	{
		ft_putstr_fd("(nil)", 1);
		return 5;
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_hex(n, 0);
	return 0;
}
/*int main(void)
{
    ft_putnbr_fd(4223456, 2);
    return (0);
}*/
