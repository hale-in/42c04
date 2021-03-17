/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:04:32 by taeheeki          #+#    #+#             */
/*   Updated: 2021/03/17 22:13:25 by taeheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	ft_putnbr_base(int nbr, char *base)
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
			return (base[change[i]]);
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int result;
	int neg;

	i = 0;
	result = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (putnbr_base(str))
	{
		result = (result * 10) + ((str[i] - '0') * neg);
		i++;
	}
	return (result);
}
