/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:17:10 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/19 16:22:12 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrev(t_list *lst)
{
	t_list	*out;
	t_list	*new;
	t_list	*tmp;

	out = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		ft_lstadd(&out, new);
		free(lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (out);
}
