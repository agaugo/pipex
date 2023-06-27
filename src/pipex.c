/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:59 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/23 16:38:22 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd_[2];
    char test[5];

    if (pipe(fd_) < 0)
        return (1);

    write(fd_[1], "test", 4);
    read(fd_[0], test, 4);
    printf("%s\n", test);
    return (0);
}
