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

#include "libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	child(int *fd_pipe, char **argv)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0666);
	if (infile == -1)
	{
		perror("Unable to open input file");
		exit(1);
	}
	if (dup2(fd_pipe[1], 1) == -1)
	{
		perror("Error redirecting output to pipe");
		exit(1);
	}
	if (dup2(infile, 0) == -1)
	{
		perror("Error redirecting input from file");
		exit(1);
	}
	close(fd_pipe[0]);
	execute(argv[2]);
}

void	parent(int *fd_pipe, char **argv)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1)
	{
		perror("Unable to open output file");
		exit(2);
	}
	if (dup2(fd_pipe[0], 0) == -1)
	{
		perror("Error redirecting input from pipe");
		exit(2);
	}
	if (dup2(outfile, 1) == -1)
	{
		perror("Error redirecting output to file");
		exit(2);
	}
	close(fd_pipe[1]);
	execute(argv[3]);
}

int	main(int argc, char *argv[])
{
	int	fd_pipe[2];
	int	process_id;

	if (argc != 5)
		exit(2);
	if (pipe(fd_pipe) == -1)
	{
		perror("Pipe creation error");
		exit(1);
	}
	process_id = fork();
	if (process_id == -1)
	{
		perror("Fork error");
		exit(1);
	}
	if (process_id == 0)
		child(fd_pipe, argv);
	parent(fd_pipe, argv);
	return (0);
}
