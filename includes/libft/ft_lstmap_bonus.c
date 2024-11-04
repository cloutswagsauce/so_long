/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:57:27 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/12 13:09:48 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*current_node;
	t_list	*new_node;

	if (!lst || !f)
		return (0);
	first_node = ft_lstnew(f(lst -> content));
	if (!first_node)
		return (0);
	current_node = first_node;
	lst = lst -> next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		current_node -> next = new_node;
		current_node = new_node;
		lst = lst -> next;
	}
	return (first_node);
}
