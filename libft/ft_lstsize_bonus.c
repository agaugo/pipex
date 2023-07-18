/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 16:17:57 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 16:30:23 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*temp;

	temp = lst;
	cnt = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		cnt++;
	}
	return (cnt);
}
