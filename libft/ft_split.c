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

static void	free_mem(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static int	substr_size(const char *s, char c, int start)
{
	int	size;

	size = 0;
	while (s[start + size] != c && s[start + size] != '\0')
		size++;
	return (size);
}

static char	**fill_array(const char *s, char **array, int cnt, int c)
{
	int	i;
	int	start;
	int	size;

	i = 0;
	start = 0;
	size = 0;
	while (i < cnt)
	{
		while (s[start + size] == c && s[start] != '\0')
			start++;
		start += size;
		size = substr_size(s, c, start);
		array[i] = ft_substr(s, start, substr_size(s, c, start));
		if (!array[i])
		{
			free_mem(array, i);
			return (NULL);
		}
		i++;
	}
	array[i] = 0;
	return (array);
}

static int	str_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**array;

	if (!s)
		return (NULL);
	cnt = str_counter(s, c);
	array = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!array)
		return (NULL);
	array = fill_array(s, array, cnt, c);
	return (array);
}
