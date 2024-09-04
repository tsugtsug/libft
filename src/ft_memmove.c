/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:57:46 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:11 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d_cpy;
	const char	*s_cpy;

	d_cpy = (char *)dst;
	s_cpy = (char *)src;
	if (d_cpy == s_cpy)
		return (dst);
	else if (s_cpy < d_cpy && len != 0)
	{
		d_cpy = d_cpy + len - 1;
		s_cpy = s_cpy + len - 1;
		while (len--)
			*d_cpy-- = *s_cpy--;
	}
	else
	{
		while (len--)
			*d_cpy++ = *s_cpy++;
	}
	return (dst);
}
