/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_record.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: farodrig <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/30 21:23:12 by farodrig      #+#    #+#                 */
/*   Updated: 2020/08/31 17:25:05 by farodrig      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int get_zeros(int nb)
{
	int digits;
	int c;
	int res;

	c = 1;
	res = 1;
	digits = get_amount_of_digits(nb);
	while (c < digits)
	{
		res *= 10;
		c++;
	}
	return res;
}

static int search_record(char ***dictionary, char *n_record)
{
	int record;
	record = 0;
	while (record < 50)
	{
		if (is_the_same_str(n_record, dictionary[record][0]))
		{
			print_str(dictionary[record][1]);
			return (1);
		}
		record++;
	}
	return (0);
}

void open_record(char ***dictionary, char *n_record)
{
	int nb;

	if(!search_record(dictionary, n_record))
	{
		nb = ft_atoi(n_record);
		while (nb > 0)
		{
			search_record(dictionary, ft_itoa((nb % 10) * get_zeros(nb)));
			nb /= 10;
		}
	} else {
		print_str("Error3\n");
		return ;
	}
	return;
}
