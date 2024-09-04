/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:29:40 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:45:01 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_extra(char const *s1, size_t size_f, size_t size_b, char *rtn)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[size_f + i] && size_f + i < ft_strlen(s1) - size_b)
	{
		rtn[j] = s1[size_f + i];
		j++;
		i++;
	}
	rtn[j] = '\0';
	return (rtn);
}

size_t	ft_trim_front(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				i++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (count);
}

size_t	ft_trim_back(char const *s1, char const *set)
{
	size_t	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (s1[i])
		i++;
	while (i > 0)
	{
		i--;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	size_f;
	size_t	size_b;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size_f = ft_trim_front(s1, set);
	size_b = ft_trim_back(s1, set);
	if (size_f == ft_strlen(s1) || size_b == ft_strlen(s1))
	{
		rtn = (char *)malloc(sizeof(char) * 1);
		if (rtn == NULL)
			return (NULL);
		*rtn = '\0';
		return (rtn);
	}
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) - size_f - size_b + 1));
	if (rtn == NULL)
		return (NULL);
	rtn = ft_extra(s1, size_f, size_b, rtn);
	return (rtn);
}
