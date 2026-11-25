/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfredon <alfredon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 11:59:43 by alfredon          #+#    #+#             */
/*   Updated: 2026/11/24 12:53:43 by alfredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
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

int	get_base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	get_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_sign(char *str, int *i)
{
	int	negative;

	negative = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			negative++;
		(*i)++;
	}
	return (negative);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	base_length;
	int	negative;
	int	digit;

	if (!check_base(base))
		return (0);
	i = 0;
	result = 0;
	base_length = get_base_length(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	negative = get_sign(str, &i);
	digit = get_digit(str[i], base);
	while (digit != -1)
	{
		result = result * base_length + digit;
		i++;
		digit = get_digit(str[i], base);
	}
	if (negative % 2 == 1)
		result = -result;
	return (result);
}
