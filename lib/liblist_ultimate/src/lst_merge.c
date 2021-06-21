/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:56:55 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 22:01:11 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	lst_merge(t_list *sentinel_a, t_list *sentinel_b)
{
	sentinel_a->prev->next = sentinel_b->next;
	sentinel_b->next->prev = sentinel_a->prev;
	sentinel_b->prev->next = sentinel_a;
	sentinel_a->prev = sentinel_b->prev;
	sentinel_b->next = sentinel_b;
	sentinel_b->prev = sentinel_b;
}
