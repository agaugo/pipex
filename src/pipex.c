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

// > Launch
// > Pipe
// > Fork Process

// > Call Child Process
//      > Close read end of pipe, pipe[0]
//      > Redirect stdin to infile
//      > Redirect stdout to write end of pipe, pipe[1]
//      > Execute command
//              > Find path of the appropriate command
//              > Call execve using the path

// > Call Parent Process
//      > Close write end of pipe, pipe[1]
//      > Redirect stdout to outfile
//      > Redirect stdin to read end of pipe, pipe[0]
//      > Execute command
//              > Find path of the appropriate command
//              > Call execve using the path
//
//

//execve(const char *path, char *const argv[], char *const envp[]);

#include "../include/pipex.h"

char **get_args(char *cmd_buffer){
    static char **exec_args;
    char *cmd;
//    char *flag;
    int len;

    exec_args = malloc(sizeof(char *) * (3 + 1));
    if (!(ft_strchr(cmd_buffer, ' '))) {
        exec_args[0] = ft_strjoin("/bin/", cmd_buffer);
        exec_args[1] = NULL;
        exec_args[2] = NULL;
        return (exec_args);
    }
    len = 0;
    while (cmd_buffer[len] != ' ')
        len ++;
    cmd = malloc((sizeof(char) * (len + 1)));
    if (!cmd)
        return (NULL);
    return (NULL);
}

int child(int *fd_pipe, int fd_infile, char *cmd_buffer){
    char **exec_args;

    exec_args = get_args(cmd_buffer);
    close(fd_pipe[0]);
    dup2(fd_infile, 0);
    dup2(fd_pipe[1], 1);
    execve(exec_args[0], exec_args, NULL);
    return (0);
}

int parent(int *fd_pipe, int fd_outfile, char *cmd_buffer){
    char **exec_args;

    exec_args = get_args(cmd_buffer);
    close(fd_pipe[1]);
    dup2(fd_pipe[0], 0);
    dup2(fd_outfile, 1);
    execve(exec_args[0], exec_args, NULL);
    return (0);
}

int main(int argc, char *argv[])
{
    int fd_pipe[2];
    int process_id;
    int fd_infile;
    int fd_outfile;

    if (argc != 5)
        return (0);
    fd_infile = open(argv[1], O_RDONLY);
    fd_outfile = open(argv[4], O_WRONLY | O_CREAT, 0644);
    if (pipe(fd_pipe) < 0)
        return (1);
    process_id = fork();
    if (process_id == 0)
        child(fd_pipe, fd_infile, argv[2]);
    else {
        wait(NULL);
        parent(fd_pipe, fd_outfile, argv[3]);
    }
    return (0);
}
