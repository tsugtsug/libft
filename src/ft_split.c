/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:54:47 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:28 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_error(char **rtn, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(rtn[i]);
		i++;
	}
	free(rtn);
	return (NULL);
}

int	ft_split_sub(char const *s, char c, char **rtn, int j)
{
	int	count;
	int	i;
	int	l;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	rtn[j] = (char *)malloc(sizeof(char) * (count + 1));
	if (rtn[j] == NULL)
	{
		ft_error(rtn, j);
		return (-1);
	}
	l = 0;
	i = 0;
	while (s[i] != c && s[i])
		rtn[j][l++] = (char)s[i++];
	rtn[j][l] = '\0';
	return (i);
}

char	**ft_split_main(char const *s, char c, char **rtn)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = ft_split_sub(&s[i], c, rtn, j);
			i = i + k;
			if (k == -1)
				return (NULL);
			j++;
		}
		else
			i++;
	}
	rtn[j] = NULL;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		i;
	int		count;

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
	rtn = (char **)malloc(sizeof(char *) * (count + 1));
	if (rtn == NULL)
		return (NULL);
	rtn = ft_split_main(s, c, rtn);
	return (rtn);
}
