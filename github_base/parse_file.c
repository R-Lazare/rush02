/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:49:00 by rluiz             #+#    #+#             */
/*   Updated: 2023/03/18 16:49:08 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct dict {
    int nombre;
    char *mot;
};

struct dict *parse_file(char *filename, int *num_lines) {
    int fd, n, count = 0;
    char buf[1];
    struct dict *dict_arr;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        // error opening file
        return NULL;
    }
    // count number of lines in file
    while ((n = read(fd, buf, 1)) > 0) {
        if (buf[0] == '\n') {
            count++;
        }
    }
    if (n == -1) {
        // error reading file
        return NULL;
    }
    // allocate memory for array of dict structs
    dict_arr = (struct dict *) malloc(count * sizeof(struct dict));
    if (dict_arr == NULL) {
        // error allocating memory
        return NULL;
    }
    // reset file descriptor to beginning of file
    lseek(fd, 0, SEEK_SET);
    // read and parse each line of file
    count = 0;
    while ((read = getline(&line, &len, fd)) != -1) {
        int num;
        char *word;
        // parse line into number and word
        if (sscanf(line, "%d : %m[^\n]", &num, &word) == 2) {
            // store number and word in dict struct
            dict_arr[count].nombre = num;
            dict_arr[count].mot = word;
            count++;
        }
        else {
            // error parsing line
            free(line);
            free(dict_arr);
            return NULL;
        }
    }
    free(line);
    close(fd);
    *num_lines = count;
    return dict_arr;
}

