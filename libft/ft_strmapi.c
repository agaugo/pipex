/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:36:22 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 10:49:55 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		c;
	char	*buffer;

	buffer = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buffer)
		return (0);
	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		buffer[c] = f(i, s[i]);
		c++;
		i++;
	}
	buffer[c] = '\0';
	return (buffer);
}
