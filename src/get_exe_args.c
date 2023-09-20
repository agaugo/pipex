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
	handle_error(127, "Failed to execute command");
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

void	copy_arr(char **arr1, char **arr2)
{
	int	i;

	i = 1;
	while (arr2[i] != NULL)
	{
		arr1[i] = arr2[i];
		i++;
	}
	arr1[i] = NULL;
}

int	count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	execute(char *args, char **envp)
{
	char	**args_arr;
	char	**final_argv;
	int		size;

	args_arr = ft_split(args, ' ');
	if (!args_arr || ft_strlen(args) == 0)
		handle_error(127, "Failed to run command");
	size = count(args_arr);
	final_argv = malloc(sizeof(char *) * (size + 1));
	if (!final_argv)
		return ;
	if (access(args_arr[0], X_OK) != -1)
		final_argv[0] = args_arr[0];
	else if (access(args_arr[0], X_OK == -1))
		final_argv[0] = get_root_dir(args_arr[0]);
	if (!final_argv[0])
		free_and_exit(final_argv, args_arr);
	copy_arr(final_argv, args_arr);
	free(args_arr);
	execve(final_argv[0], final_argv, envp);
	handle_error(1, "Failed to run command");
}
