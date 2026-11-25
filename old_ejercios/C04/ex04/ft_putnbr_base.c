/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfredon <alfredon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 08:59:16 by alfredon          #+#    #+#             */
/*   Updated: 2026/11/24 12:41:17 by alfredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr_recursive(unsigned int nbr, char *base,
			unsigned int base_length);

int		check_base(char *base);

void	ft_putnbr_base(int nbr, char *bas)
{
	unsigned int	base_length;
	unsigned int	number;

	base_length = 0;
	if (check_base(bas) == 0)
		return ;
	while (bas[base_length] != '\0')
		base_length++;
	if (nbr < 0)
	{
		write (1, "-", 1);
		number = (unsigned int)(-(nbr + 1)) + 1;
	}
	else
		number = (unsigned int)nbr;
	putnbr_recursive(number, bas, base_length);
}

int	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	putnbr_recursive(unsigned int nbr, char *base, unsigned int base_length)
{
	if (nbr >= base_length)
		putnbr_recursive(nbr / base_length, base, base_length);
	write (1, &base[nbr % base_length], 1);
}
