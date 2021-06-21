/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:11:07 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 21:14:30 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_pop(t_list *element)
{
	(*element->list_size)--;
	element->prev->next = element->next;
	element->next->prev = element->prev;
	element->next = NULL;
	element->prev = NULL;
	free(element);
}

void	lst_pop_front(t_list *sentinel)
{
	if (sentinel->next != sentinel)
		lst_pop(sentinel->next);
}

void	lst_pop_back(t_list *sentinel)
{
	if (sentinel->prev != sentinel)
		lst_pop(sentinel->prev);
}
