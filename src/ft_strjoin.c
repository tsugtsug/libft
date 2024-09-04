/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:34:24 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:39 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		rtn[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		rtn[i] = *s2;
		i++;
		s2++;
	}
	rtn[i] = '\0';
	return (rtn);
}
