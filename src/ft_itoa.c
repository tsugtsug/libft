/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:12:53 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:02 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	digit_cal(long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_putnbr(long nbr, char *str)
{
	long	nbr1;
	long	nbr2;

	nbr1 = nbr / 10;
	nbr2 = nbr % 10;
	if (nbr1 != 0)
		str = ft_putnbr(nbr1, str);
	*str++ = nbr2 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	char	*tmp;

	nbr = n;
	if (n < 0)
	{
		nbr = nbr * -1;
		str = (char *)malloc(sizeof(char) * (digit_cal(nbr) + 2));
		if (str == NULL)
			return (NULL);
		tmp = str;
		*str++ = '-';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (digit_cal(nbr) + 1));
		if (str == NULL)
			return (NULL);
		tmp = str;
	}
	str = ft_putnbr(nbr, str);
	*str = '\0';
	return (tmp);
}
