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

#include "../include/pipex.h"

void    free_all(char **exec_args){
    int i;

    i = 0;
    while (exec_args[i] != NULL)
        free(exec_args[i]);
    free(exec_args);
}

int count_args(char *cmd_buffer){
    if (!ft_strchr(cmd_buffer, ' '))
        return (1);
    else
        return (2);
}

char *get_root_dir(char *arg1) {
    char *dirs[4];
    char *return_dir;
    int i;

    dirs[0] = "/bin/";
    dirs[1] = "/usr/bin/";
    dirs[2] = "/usr/local/bin/";
    dirs[3] = NULL;
    i = 0;
    while (dirs[i] != NULL) {
        return_dir = ft_strjoin(dirs[i], arg1);
        if (access(return_dir, F_OK) != -1)
            return (return_dir);
        free(return_dir);
        i++;
    }
    return (NULL);
}

//You're right. I apologize for misunderstanding your question. The exec_args array is currently not set up to handle more than one argument. To change this, you will have to split the input command into words and add each word to the exec_args array.
//
//First, modify count_args to count all words, not just up to the first space.
//
//Then, in get_args, instead of manually extracting the first argument and using ft_substr to get the rest, split the command into words using ft_strsplit or a similar function. The first word is the command name, the rest are arguments. Here's a sketch of how this could look:

char **get_args(char *cmd_buffer){
    char    **exec_args;
    char    *arg1;
    int     count;
    int     len;

    len = 0;
    count = count_args(cmd_buffer);
    exec_args = malloc((sizeof(char *) * count + 1));
    if (!exec_args)
        return (NULL);
    if (count != 1) {
        while (cmd_buffer[len] != ' ' && cmd_buffer[len] != '\0')
            len++;
        arg1 = malloc(sizeof(char) * len + 1);
        if (!arg1)
            return (NULL);
        ft_strlcpy(arg1, cmd_buffer, len + 1);
        exec_args[0] = get_root_dir(arg1);
        free(arg1);
        exec_args[1] = ft_substr(cmd_buffer, len + 1, 3);
        exec_args[2] = NULL;
    }
    else {
        exec_args[0] = get_root_dir(cmd_buffer);
        exec_args[1] = NULL;
    }
    return (exec_args);
}

int child(int *fd_pipe, int fd_infile, char *cmd_buffer){
    char **exec_args;

    exec_args = get_args(cmd_buffer);
    printf("child process (infile) %s %s\n", exec_args[0], exec_args[1]);
    close(fd_pipe[0]);
    dup2(fd_infile, 0);
    dup2(fd_pipe[1], 1);
    if (execve(exec_args[0], exec_args, NULL) == -1) {
        perror(exec_args[0]);   // print out the error
        exit(1);               // exit if execve fails
    }
    return (0);
}

int parent(int *fd_pipe, int fd_outfile, char *cmd_buffer){
    char **exec_args;

    exec_args = get_args(cmd_buffer);
    printf("parent process (outfile) %s %s\n", exec_args[0], exec_args[1]);
    close(fd_pipe[1]);
    dup2(fd_pipe[0], 0);
    dup2(fd_outfile, 1);
    if (execve(exec_args[0], exec_args, NULL) == -1) {
        perror(exec_args[0]);   // print out the error
        exit(1);               // exit if execve fails
    }
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
