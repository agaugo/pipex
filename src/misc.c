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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;

    i = 0;
    if (dstsize != 0)
    {
        while ((dstsize - 1) != '\0' && *src)
        {
            *(dst++) = *(src++);
            dstsize--;
            i++;
        }
        *(dst) = '\0';
        src -= i;
        i = 0;
    }
    while (*src)
    {
        i++;
        src++;
    }
    return (i);
}

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

char	*ft_strdup(const char *s1)
{
    int		i;
    char	*buffer;

    i = 0;
    buffer = malloc(ft_strlen(s1) + 1);
    if (!buffer)
        return (0);
    while (s1[i])
    {
        buffer[i] = s1[i];
        i++;
    }
    buffer[i] = '\0';
    return (buffer);
}
