/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 13:25:08 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/20 13:25:09 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	c;
	char			*buffer;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	c = 0;
	buffer = malloc((sizeof(char const) * len) + 1);
	if (!buffer)
		return (0);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		buffer[i + c] = s2[c];
		c++;
	}
	buffer[i + c] = '\0';
	return (buffer);
}
/*
int	main(void)
{
	printf("%s$\n", ft_strjoin("whatsup ", "my friend"));
	return 0;
}
*/