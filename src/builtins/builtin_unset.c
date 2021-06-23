/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:55:53 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/29 00:30:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	is_valid_identifier(const char *tok)
{
	if (!ft_isalpha(*tok) && *tok != '_')
		return (false);
	while (*++tok && (ft_isalnum(*tok) || *tok == '_'))
		continue ;
	return (!*tok);
}

int	builtin_unset(int argc, char **argv, char **envp)
{
	(void)envp;
	int	ret;

	ret = 0;
	while (--argc > 0)
	{
		if (!ft_strcmp(argv[argc], "PATH"))
		{
			ft_destroy_array((void **)g_global_data.path, NULL_ENDED);
			g_global_data.path = NULL;
		}
		if (!is_valid_identifier(argv[argc]))
		{
			ret = not_valid_identifier("unset", argv[argc]);
			continue ;
		}
		if (ft_delenv(argv[argc]))
			return (-1);
	}
	return (ret);
}
