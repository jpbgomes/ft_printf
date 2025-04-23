/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-b <jpedro-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:19:09 by jpedro-b          #+#    #+#             */
/*   Updated: 2025/04/21 17:32:27 by jpedro-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*last;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			last = tmp;
			del(tmp->content);
			tmp = tmp->next;
			free(last);
		}
		*lst = NULL;
	}
}
