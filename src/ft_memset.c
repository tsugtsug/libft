/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:13:41 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:14 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*b_cpy;
	unsigned char	c_str;

	i = 0;
	c_str = (unsigned char)c;
	b_cpy = (unsigned char *)b;
	while (len--)
	{
		b_cpy[i] = c_str;
		i++;
	}
	return (b);
}
