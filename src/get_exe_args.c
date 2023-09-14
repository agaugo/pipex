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

#include "../include/pipex.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	free_all(char **exec_args)
{
	int	i;

	i = 0;
	while (exec_args[i] != NULL)
		free(exec_args[i]);
	free(exec_args);
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
	int		i;

	dirs[0] = "/bin/";
	dirs[1] = "/usr/bin/";
	dirs[2] = "/usr/local/bin/";
	dirs[3] = NULL;
	i = 0;
	while (dirs[i] != NULL)
	{
		return_dir = ft_strjoin(dirs[i], arg1);
		if (access(return_dir, F_OK) != -1)
			return (return_dir);
		free(return_dir);
		i++;
	}
	exit(1);
	return (NULL);
}

char **get_args(char *cmd_buffer)
{
    int i = 0, j = 0;
    char **args;
    char **partial_args;

    partial_args = ft_split(cmd_buffer, ' ');

    // Allocate memory for resulting array
    for (i = 0; partial_args[i] != NULL; i++);
    args = malloc(sizeof(char *) * (i + 1));

    // Handle the command (first argument)
    args[0] = get_root_dir(partial_args[0]);

    // Handle all other arguments
    for (j = 1; j < i; j++) {
        args[j] = ft_strdup(partial_args[j]);
    }
    args[j] = NULL;

    // Free the partial_args array and its contents
    for (i = 0; partial_args[i] != NULL; i++) {
        free(partial_args[i]);
    }
    free(partial_args);

    return args;
}

