/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:43:35 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:50 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rtn;
	unsigned int	i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
