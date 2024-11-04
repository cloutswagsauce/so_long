/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:56:48 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/12 13:09:46 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_next;
	t_list	*p_lst;

	p_lst = *lst;
	while (p_lst)
	{
		temp_next = p_lst -> next;
		del(p_lst -> content);
		free(p_lst);
		p_lst = temp_next;
	}
	*lst = 0;
}
