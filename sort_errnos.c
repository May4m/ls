/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_errnos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:26:50 by smamba            #+#    #+#             */
/*   Updated: 2016/06/12 10:26:51 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ft_sort_lexi_err(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 1;
	while (i[0])
	{
		i[0] = 0;
		i[1] = 1;
		while (dir[i[1]] != NULL && ft_errno(dir[i[1]]) != 0)
		{
			if (ft_strcmp(dir[i[1] - 1], dir[i[1]]) > 0)
			{
				i[0] = 1;
				buf = ft_strdup(dir[i[1] - 1]);
				dir[i[1] - 1] = ft_strdup(dir[i[1]]);
				dir[i[1]] = ft_strdup(buf);
				free(buf);
			}
			i[1]++;
		}
	}
	return (dir);
}

char		**ft_sort_errno(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 1;
	while (i[0])
	{
		i[0] = 0;
		i[1] = 1;
		while (dir[i[1]] != NULL)
		{
			if (ft_errno(dir[i[1] - 1]) < ft_errno(dir[i[1]]))
			{
				i[0] = 1;
				buf = ft_strdup(dir[i[1] - 1]);
				dir[i[1] - 1] = ft_strdup(dir[i[1]]);
				dir[i[1]] = ft_strdup(buf);
				free(buf);
			}
			i[1]++;
		}
	}
	return (ft_sort_lexi_err(dir));
}

int			ft_errno(char *path)
{
	DIR				*dirp;

	errno = 0;
	if ((dirp = opendir(path)) == NULL)
		if (errno != 20)
			return (errno);
	if (dirp != NULL)
		closedir(dirp);
	return (0);
}
