/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:27 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/18 15:11:32 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_a_number(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

void	add_number(char *str, int *res)
{
	while (is_a_number(*str))
	{
		if (*res == 0)
		{
			*res = (*str - '0');
		}
		else
		{
			*res = *res * 10 + (*str - '0');
		}
		str++;
	}
}

int int_length(long nb)
{
	int length;

	length = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		length++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

int get_amount_of_digits(int n)
{
	int count;
	count = 0;
	
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return count;
}

int	ft_atoi(char *str)
{
	unsigned int	minus_counter;
	int				res;

	res = 0;
	minus_counter = 0;
	while (*str != '\0')
	{
		if (*str == '-')
		{
			minus_counter++;
		}
		if (is_a_number(*str))
		{
			add_number(str, &res);
			break ;
		}
		str++;
	}
	if (minus_counter % 2 != 0)
	{
		res = -res;
	}
	return (res);
}
