/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:18:15 by jsandsla          #+#    #+#             */
/*   Updated: 2020/10/31 14:37:06 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*new;
	void	*content;

	new = NULL;
	nlst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (new != NULL)
		{
			new->next = ft_lstnew(content);
			new = new->next;
		}
		else
			new = ft_lstnew(content);
		if (new == NULL)
		{
			del(content);
			new = ft_lstlast(nlst);
		}
		nlst = nlst == NULL ? new : nlst;
		lst = lst->next;
	}
	return (nlst);
}
