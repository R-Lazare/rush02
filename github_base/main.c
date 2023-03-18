/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:30:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/18 15:48:01 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/headers.h"

int main(int argc, char **argv)
{
	char *n_record;
	char *entry_value;
	int record;

	if (argc < 2 || argc > 3)
	{
		print_str("Error\n");
		return (0);
	}
	record = 0;
	char ***dictionary = (char ***)malloc(sizeof(char **) * 60);
	if (dictionary == NULL)
	{
		print_str("oups");
		return (0);
	}
	while (record < 50)
	{
		dictionary[record] = (char **)malloc(sizeof(char *) * 2);
		dictionary[record][0] = (char *)malloc(sizeof(char) * 48);
		dictionary[record][1] = (char *)malloc(sizeof(char) * 48);
		record++;
	}
	get_dict(dictionary);
	if (argc == 2)
	{
		n_record = argv[1];
		if (!str_is_numeric(n_record))
		{
			print_str("Error1\n");
			return (0);
		}
		open_record(dictionary, n_record);
	}
	else if (argc == 3)
	{
		n_record = argv[1];
		entry_value = argv[2];

		if (!str_is_numeric(n_record) || !entry_is_valid(entry_value))
		{
			print_str("Error2\n");
			return (0);
		}
	}
	free(dictionary);
	free(entry_value);
}
