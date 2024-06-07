/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:02:39 by rpothier          #+#    #+#             */
/*   Updated: 2023/12/07 13:48:42 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_node;
	void	*buffer;

	node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		buffer = f(lst->content);
		new_node = ft_lstnew(buffer);
		if (!new_node)
		{
			del(buffer);
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, new_node);
		lst = lst->next;
	}
	return (node);
}
