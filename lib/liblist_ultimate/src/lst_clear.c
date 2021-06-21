/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:27:54 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 22:32:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_clear(t_list *sentinel)
{
	t_list	*iterator;
	t_list	*head;

	iterator = sentinel->next;
	while (iterator != sentinel)
	{
		head = iterator->next;
		iterator->next = NULL;
		iterator->prev = NULL;
		free(iterator);
		iterator = head;
	}
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	*sentinel->list_size = 0;
}

void	lst_destroy(t_list *sentinel)
{
	lst_clear(sentinel);
	free(sentinel->list_size);
	free(sentinel);
}
