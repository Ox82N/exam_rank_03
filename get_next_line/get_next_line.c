/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:40:39 by obenjair          #+#    #+#             */
/*   Updated: 2022/08/24 18:42:26 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

char *ft_strdup(char *str)
{
    int i = 0;
    char *ptr;

    while(str[i])
        i++;
    ptr = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while(str[i])
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

char *get_next_line(int fd)
{
    char line[1000000] = {0};
    char buf[1];
    int i = 0;
    int n;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return 0;
    while((n = read(fd, buf, 1)) && n > 0)
    {
        line[i++] = buf[0];
        line[i] = 0;
    }
    if(!line[0])
        return NULL;
    return (ft_strdup(line));
}