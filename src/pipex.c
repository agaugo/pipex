/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:59 by hflohil-          #+#    #+#             */
/*   Updated: 2023/08/23 15:18:23 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void child(int *fd_pipe, char **argv)
{
  char** exec_args;
  int    infile;

  infile = open(argv[1], O_RDONLY, 0777);
  if (infile == -1)
    exit(1);
  dup2(fd_pipe[1], 1);
  dup2(infile, 0);
  close(fd_pipe[0]);
  exec_args = get_args(argv[2]);
  if (execve(exec_args[0], exec_args, NULL) == -1)
    {
      free_all(exec_args);
      exit(1);
    }
 
}

void parent(int *fd_pipe, char **argv)
{
  char** exec_args;
  int    outfile;

  outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
  if (outfile == -1)
    exit(1);
  dup2(fd_pipe[0], 0);
  dup2(outfile, 1);
  close(fd_pipe[1]);
  exec_args = get_args(argv[3]);
  if (execve(exec_args[0], exec_args, NULL) == -1)
    {
      free_all(exec_args);
      exit(1);
    }
 
}


int	main(int argc, char *argv[])
{
	int	fd_pipe[2];
	int	process_id;
 
	//check for right amount of args
	if (argc != 5)
		return (0);
	//piping to ft_pipe, if error occurs, exit
	if (pipe(fd_pipe) == -1)
	  exit(1);
	//forking process and assigning id to process_id
	process_id = fork();
	if (process_id == -1)
	  exit(1);
	//if process_id == 0, child process is run
	if (process_id == 0)
	  child(fd_pipe, argv);
	//if process_id != 0, we wait for child process before running parent process
	waitpid(process_id, NULL, 0);
	parent(fd_pipe, argv);

 	return (0);
}
