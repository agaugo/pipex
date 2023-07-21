/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:38:07 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/23 16:38:08 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void    free_all(char **exec_args);
int     count_args(char *cmd_buffer);
char    *get_root_dir(char *arg1);
char    **get_args(char *cmd_buffer);
int     child(int *fd_pipe, int fd_infile, char *cmd_buffer);
int     parent(int *fd_pipe, int fd_outfile, char *cmd_buffer);

