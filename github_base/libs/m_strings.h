/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strings.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:46:55 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/18 15:33:26 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

unsigned int	str_length(const char *str)
{
	unsigned int size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

/*char *concat_str(char *str1, char *str2)
{
	unsigned int str1_size;
	unsigned int str2_size;
	unsigned int c;
	char *res;

	str1_size = str_length(str1);
	str2_size = str_length(str2);
	res = (char*)malloc((str1_size + str2_size + 1) * sizeof(char));
	c = 0;
	while (*str1 != '\0')
	{
		res[c] = *str1;
		str1++;
		c++;
	}
	while (*str2 != '\0')
	{
		res[c] = *str2;
		str2++;
		c++;
	}
	res[c] = '\0';
	return (res);
}*/

int	is_the_same_str(char *s1, char *s2)
{
	unsigned int c;

	c = 0;
	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0')
		{
			return (1);
		}
		c++;
	}
	return (0);
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

