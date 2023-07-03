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
#include <fcntl.h>
#include <sys/wait.h>

//int parent(){
//
//};
//

int child(int *fd_pipe, int fd_infile, char *cmd){
    dup2()
}

int main(int argc, char *argv[])
{
    int fd_pipe[2];
    int process_id;
    int fd_infile;
    int fd_outfile;

    if (argc < 4 || argc > 5)
        return (0);

    //opening files
    fd_infile = open(argv[1], O_RDONLY);
    fd_infile = open(argv[4], O_WRONLY | O_CREAT, 0644);
    //pipe into fd_pipe, check for failure
    if (pipe(fd_pipe) < 0)
        return (1);
    //fork process
    process_id = fork();
    //child process (file1 cmd1)
    if (process_id == 0)
        child(fd_pipe, fd_infile, argv[2]);
    //parent process (cmd2 file2
    else {
        wait(NULL);
        printf("parent");
    }
    return (0);
}
