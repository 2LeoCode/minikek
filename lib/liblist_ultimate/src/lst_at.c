/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:15:15 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 21:19:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_at(const t_list *sentinel, size_t index)
{
	const t_list	*tmp = sentinel;

	if (index > *sentinel->list_size)
		return (NULL);
	while (index--)
		tmp = tmp->next;
	return ((t_list *)tmp);
}
