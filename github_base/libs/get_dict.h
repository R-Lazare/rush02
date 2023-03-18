/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_dict.h                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: farodrig <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/29 19:20:57 by farodrig      #+#    #+#                 */
/*   Updated: 2023/03/18 15:45:53 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void get_dict(char ***dictionary)
{
	char *dictionary_name;
	char buff[BUFF_SIZE + 1];
	int fd;
	int ret;
	int c;
	int row;
	int o;

	c = 0;
	row = 0;
	dictionary_name = "./numbers.dict";
	fd = open(dictionary_name, O_RDONLY);
	if (fd == -1)
	{
		return;
	}
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	while (c < ret && row < 50)
	{
		o = 0;
		while (buff[c] != ':')
		{
			dictionary[row][0][o] = buff[c];
			o++;
			c++;
		}
		dictionary[row][0][o] = '\0';
		c++;
		o = 0;
		while (buff[c] != '\n' && c < ret)
		{
			dictionary[row][1][o] = buff[c];
			o++;
			c++;
		}
		dictionary[row][1][o] = '\0';
		row++;
		c++;
	}
	if (close(fd) == -1)
	{
		//free(dictionary_name);
		return;
	}
	//free(dictionary_name);
	return;
}
