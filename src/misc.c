/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hflohil- <hflohil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:37:59 by hflohil-          #+#    #+#             */
/*   Updated: 2023/06/23 16:38:22 by hflohil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strchr(const char *s, int c)
{
    char			*target;
    char			c_char;

    target = (char *)s;
    c_char = (char)c;
    while (*target)
    {
        if (*target == c_char)
            return (target);
        target++;
    }
    if (c_char == '\0')
        return (target);
    else
        return (0);
}

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

size_t	ft_strlen(const char *s)
{
    int	i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}