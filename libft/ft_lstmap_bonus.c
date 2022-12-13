/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:55:22 by etattevi          #+#    #+#             */
/*   Updated: 2022/11/02 13:58:57 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*node;

	if (!lst || !f | !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	new_node = new_lst;
	node = lst;
	while (node->next)
	{
		node = node->next;
		new_node->next = ft_lstnew(f(node->content));
		if (!new_node->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node = new_node->next;
	}
	return (new_lst);
}
