/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:14:58 by mlangloi          #+#    #+#             */
/*   Updated: 2023/03/18 12:51:17 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

struct dict
{
	int nombre;
	char *mot;
}

void	create_dict(struct *dict my_dict) //mettre le dictioonnaire dans une structure (ne fonctionne qu'avec le dictionnaire de base)
{
	int	fd;
	int	res;
	int	i;

	i = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return;
	res = read(fd, buf, BUF_SIZE);
	buf[res] = '\0';
	while (c < res)
	{
		while (buf[c] != ':')
		{
			dict[i].nombre = buf[c];
			i++;
			c++;
		}
		dict[i].nombre = '\0';
		c++;
		i = 0;
		while (buf[c] != '\n' && c < res)
		{
			dict[i].mot = buf[c];
			i++;
			c++;
		}
		dict[i].mot = '\0';
		c++;
	}
	if (close (fd) == -1)
	{
		free();
		return;
	}
	free();
	return;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str) //afficher une chaine 
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int str_is_numeric(char *str)  //verifie si la chaine ne contient aue des chiffres
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

int	main(int argc, char **argv)
{
	struct *dict my_dict;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("error\n");
		return (0);
	}
	my_dict = (struct *dict)malloc(sizeof (((char *) *  + (int) *  ))); //Comment malloc la structure ?
	create_dict(my_dict); 

	if (argc == 2) //avec dictionnaire de base
	{
		if (str_is_numeric(argv[1] == 0)) //verifier si on rentre bien un nombre
		{
			ft_putstr("error\n");
			return (0);
		}
		
	}

	if (argv == 3) //avec nouveau dictionnaire
	{
		if (str_is_numeric(argv[1]) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	
	free(my_dict);
	return 0;
}

