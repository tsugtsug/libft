/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:50:48 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:44:22 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd_extra(long nbr, int fd)
{
	long	nbr1;
	long	nbr2;
	char	c;

	nbr1 = nbr / 10;
	nbr2 = nbr % 10;
	if (nbr1 != 0)
		ft_putnbr_fd_extra(nbr1, fd);
	c = nbr2 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(fd, "-", 1);
	}
	ft_putnbr_fd_extra(nbr, fd);
}
