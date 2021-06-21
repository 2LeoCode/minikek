/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:32:02 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 20:52:53 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_new(void)
{
	t_list	*sentinel;

	sentinel = malloc(sizeof(t_list));
	if (!sentinel)
		return (NULL);
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	sentinel->size = 0UL;
	sentinel->list_size = (size_t *)malloc(sizeof(size_t));
	*sentinel->list_size = 0UL;
	return (sentinel);
}

int	lst_init(t_list **empty_data)
{
	*empty_data = lst_new();
	return (!*empty_data * -1);
}
