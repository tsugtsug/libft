/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:57:20 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:43:51 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalpha(int num)
{
	if ('A' <= num && num <= 'Z')
		return (1);
	else if ('a' <= num && num <= 'z')
		return (1);
	else
		return (0);
}
