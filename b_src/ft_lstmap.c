/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:20:15 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/03 18:43:29 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*before;
	t_list	*new_lst;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		tmp -> content = (*f)(lst -> content);
		tmp -> next = NULL;
		if (new_lst == NULL)
			new_lst = tmp;
		else
			before -> next = tmp;
		before = tmp;
		lst = lst -> next;
	}
	return (new_lst);
}
