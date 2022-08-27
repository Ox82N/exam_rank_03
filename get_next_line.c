/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:45:12 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/09 19:06:29 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd) 
{
    char *s = malloc(10000), *c = s;
    while (read(fd, c, 1) > 0 && *c++ != '\n');
    return c > s ? (*c = 0, s) : (free(s), NULL);
}

----------------------------

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

    i = 0;
    while (src[i])
        i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *get_next_line(int fd)
{
    char line[1000000] = {0};
    char buf[1];
    int i = 0;
    int n;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    while ((n = read(fd, buf, 1)) && n > 0)
    {
        line[i++] = buf[0];
        line[i] = 0;
        if (buf[0] == '\n')
            return (ft_strdup(line));
    }
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}