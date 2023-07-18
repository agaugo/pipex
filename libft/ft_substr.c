/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:12:49 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/19 19:12:50 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	buffer = (char *)malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (0);
	while (i < len && s[start] != '\0')
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/*
int	main(void)
{
	printf("%s\n", ft_substr("hello my friend", 3, 8));
	return (0);
}
*/