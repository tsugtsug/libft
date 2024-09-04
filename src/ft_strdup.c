/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:17:39 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:34 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	rtn = (char *)malloc(i + 1);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
