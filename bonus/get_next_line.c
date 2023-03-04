/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:57:55 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 11:32:25 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_strjoin_v2(char *s1, char *s2)
{
	char	*str;
	int		size;

	if (!s1)
		s1 = ft_strdup("");
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	free(s1);
	return (str);
}

static char	*read_to_stash(int fd, char *stash)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			break ;
		buffer[r] = '\0';
		stash = ft_strjoin_v2(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*get_line_from_stash(char *stash)
{
	int		i;
	char	*line;

	if (!stash[0])
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i + 1);
	return (line);
}

static char	*get_new_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (0);
	line = get_line_from_stash(stash);
	stash = get_new_stash(stash);
	return (line);
}
