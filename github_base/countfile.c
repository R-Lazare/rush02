/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:05:20 by rluiz             #+#    #+#             */
/*   Updated: 2023/03/18 16:05:22 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int count_lines(char *filename) {
    int fd, n, count = 0;
    char buf[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        // error opening file
        return -1;
    }
    while ((n = read(fd, buf, 1)) > 0) {
        if (buf[0] == '\n') {
            count++;
        }
    }
    if (n == -1) {
        // error reading file
        return -1;
    }
    close(fd);
    return count;
}

