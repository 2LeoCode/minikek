/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:36:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 21:11:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static t_list	*lst_new_element(void *data, size_t size)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list) + size);
	if (!new_element)
		return (NULL);
	new_element->size = size;
	ft_memcpy(new_element->data, data, size);
	return (new_element);
}

int	lst_push_front(t_list *sentinel, void *data, size_t size)
{
	t_list	*new_element;

	new_element = lst_new_element(data, size);
	if (!new_element)
		return (-1);
	(*sentinel->list_size)++;
	new_element->list_size = sentinel->list_size;
	new_element->prev = sentinel;
	new_element->next = sentinel->next;
	new_element->next->prev = new_element;
	sentinel->next = new_element;
	return (0);
}

int	lst_push_back(t_list *sentinel, void *data, size_t size)
{
	t_list	*new_element;

	new_element = lst_new_element(data, size);
	if (!new_element)
		return (-1);
	(*sentinel->list_size)++;
	new_element->list_size = sentinel->list_size;
	new_element->next = sentinel;
	new_element->prev = sentinel->prev;
	new_element->prev->next = new_element;
	sentinel->prev = new_element;
	return (0);
}
