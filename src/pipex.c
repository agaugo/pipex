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


int count_args(char *cmd_buffer){
    if (!ft_strchr(cmd_buffer, ' '))
        return (1);
    else
        return (2);
}

char **get_args(char *cmd_buffer){
    char **exec_args;
    char *arg1;
    int count;
    int len;

    len = 0;
    count = count_args(cmd_buffer);
    exec_args = malloc((sizeof(char *) * count + 1));
    if (!exec_args)
        return (NULL);
    if (count != 1) {
        while (cmd_buffer[len] != ' ')
            len++;
        arg1 = malloc(sizeof(char) * len + 1);
        if (!arg1)
            return (NULL);
        ft_strlcpy(arg1, cmd_buffer, len + 1);
        exec_args[0] = ft_strjoin("/bin/", arg1);
        free(arg1);
        printf("%s\n", exec_args[0]);
        exec_args[1] = ft_substr(cmd_buffer, len + 1, 3);
        exec_args[3] = NULL;
        return (exec_args);
    }

    return (NULL);
}

int child(int *fd_pipe, int fd_infile, char *cmd_buffer){
    char **exec_args;

    get_args(cmd_buffer);
    close(fd_pipe[0]);
    dup2(fd_infile, 0);
    dup2(fd_pipe[1], 1);
    execve("/bin/", exec_args, NULL);
    return (0);
}

int parent(int *fd_pipe, int fd_outfile, char *cmd_buffer){
    char **exec_args;

    get_args(cmd_buffer);
    close(fd_pipe[1]);
    dup2(fd_pipe[0], 0);
    dup2(fd_outfile, 1);
    execve("/bin/", exec_args, NULL);
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
