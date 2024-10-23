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
#include "../libft/libft.h"

void	ft_putunsignednbr(unsigned int n)
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
		ft_putunsignednbr(nbr / 10);
	}
	ft_putchar_fd((nbr % 10) + '0', 1);
}

void	ft_putunsignednbr_hex(unsigned int n, int is_upper)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = -nbr;
	}
	if (nbr/16 != 0)
	{
		ft_putunsignednbr_hex(nbr / 16, is_upper);
        ft_putchar_fd((nbr % 16) + '0', 1);
	}
    else if (nbr >= 10 && is_upper)
        ft_putchar_fd('A' + (nbr - 10),1);
    else if (nbr >= 10)
        ft_putchar_fd('a' + (nbr - 10),1);
    else
        ft_putchar_fd((nbr) + '0', 1);
}
/*int main(void)
{
    ft_putnbr_fd(4223456, 2);
    return (0);
}*/
