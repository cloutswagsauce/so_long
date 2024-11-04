/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:01:19 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/10/10 16:08:28 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	i = 0;
	len = ft_lstsize(lst) - 1;
	while (i < len && lst)
	{
		i ++;
		lst = lst -> next;
	}
	return (lst);
}
