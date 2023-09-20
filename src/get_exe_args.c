/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:59 by hflohil-          #+#    #+#             */
/*   Updated: 2023/08/23 15:17:59 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	free_and_exit(char **argv1, char **argv2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv1[i] != NULL)
	{
		free(argv1[i]);
		i++;
	}
	free(argv1);
	while (argv2[j] != NULL)
	{
		free(argv2[j]);
		j++;
	}
	free(argv2);
	perror("Failure to execute command");
	exit(127);
}

int	count_args(char *cmd_buffer)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (cmd_buffer[i] != '\0')
	{
		if (cmd_buffer[i] == ' ')
			c++;
		i++;
	}
	if (c == 0)
		c++;
	return (c);
}

char	*get_root_dir(char *arg1)
{
	char	*dirs[4];
	char	*return_dir;
	char	*cpy;
	int		i;

	dirs[0] = "/bin/";
	dirs[1] = "/usr/bin/";
	dirs[2] = "/usr/local/bin/";
	dirs[3] = NULL;
	i = 0;
	cpy = ft_strdup(arg1);
	while (dirs[i] != NULL)
	{
		return_dir = ft_strjoin(dirs[i], cpy);
		if (access(return_dir, X_OK) != -1)
		{
			free(cpy);
			return (ft_strjoin(dirs[i], arg1));
		}
		free(return_dir);
		i++;
	}
	free(cpy);
	return (NULL);
}

void	execute(char *args)
{
	char	**args_arr;
	char	**final_argv;
	int		i;

	i = 0;
	args_arr = ft_split(args, ' ');
	if (!args_arr || ft_strlen(args) == 0)
		exit(127);
	while (args_arr[i] != NULL)
		i++;
	final_argv = malloc(sizeof(char *) * (i + 1));
	if (!final_argv)
		return ;
	if (access(args_arr[0], X_OK) != -1)
		final_argv[0] = args_arr[0];
	else if (access(args_arr[0], X_OK == -1))
		final_argv[0] = get_root_dir(args_arr[0]);
	if (!final_argv[0])
		free_and_exit(final_argv, args_arr);
	i = 1;
	while (args_arr[i] != NULL)
	{
		final_argv[i] = args_arr[i];
		i++;
	}
	final_argv[i] = NULL;
	free(args_arr);
	execve(final_argv[0], final_argv, NULL);
	perror("Failed to run command");
	exit(1);
}
