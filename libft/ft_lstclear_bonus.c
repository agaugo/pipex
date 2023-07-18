/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 19:32:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/22 19:32:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_temp;
	t_list	*node;

	if (!*lst || !*del)
		return ;
	node = *lst;
	next_temp = node->next;
	while (next_temp != NULL)
	{
		ft_lstdelone(node, del);
		node = next_temp;
		next_temp = node->next;
	}
	ft_lstdelone(node, del);
	*lst = NULL;
}
