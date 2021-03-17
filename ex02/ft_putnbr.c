/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:44:40 by taeheeki          #+#    #+#             */
/*   Updated: 2021/03/15 21:22:24 by taeheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int nb)
{
	char c;

	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (0 <= nb && nb < 10)
		ft_putchar(nb);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-(nb / 10));
		ft_putchar(-(nb % 10));
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10);
	}
}
