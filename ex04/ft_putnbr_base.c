/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:00:08 by taeheeki          #+#    #+#             */
/*   Updated: 2021/03/17 20:40:18 by taeheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		size(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				change[100];
	unsigned int	ni_num;

	i = 0;
	ni_num = nbr;
	if (check(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr == -2147483648)
				ni_num = (nbr + 1) * -1 + 1;
			ni_num = -nbr;
		}
		while (ni_num)
		{
			change[i] = ni_num % size(base);
			ni_num = ni_num / size(base);
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[change[i]]);
	}
}
