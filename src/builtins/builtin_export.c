/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:55:40 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/28 23:55:44 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_sort_strarray(char **arr, int (*cmpf)(const char *, const char *))
{
	char	**it;
	char	**smallest;

	while (*arr)
	{
		smallest = arr;
		it = arr;
		while (*++it)
			if ((*cmpf)(*smallest, *it) > 0)
				smallest = it;
		if (arr != smallest)
			ft_swap(*arr, *smallest, sizeof(void *));
		arr++;
	}
}

int	get_sorted_ep(char ***sorted, char **ep)
{
	int	i;

	*sorted = (char **)malloc(sizeof(char *) * (g_global_data.env->count + 1));
	if (!*sorted)
		return (-1);
	i = -1;
	while (ep[++i])
		(*sorted)[i] = ep[i];
	(*sorted)[i] = NULL;
	ft_sort_strarray(*sorted, ft_strcmp);
	return (0);
}

int	ft_printexp(char **ep)
{
	char			*rpl;
	char			**sorted;
	unsigned int	i;

	if (get_sorted_ep(&sorted, ep))
		return (-1);
	i = -1;
	while (sorted[++i])
		if (ft_memcmp(sorted[i], "_=", 2))
		{
			ft_putstr("declare -x ");
			rpl = ft_rplchr(sorted[i], '=', 0);
			ft_putstr(sorted[i]);
			if (rpl)
			{
				ft_putstr("=\"");
				ft_putstr(rpl + 1);
				ft_putstr("\"");
				*rpl = '=';
			}
			ft_putchar('\n');
		}
	free(sorted);
	sorted = NULL;
	return (0);
}

int	is_valid_arg(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (!(ft_isalpha(str[i]) || str[i] == '_'))
		return (not_valid_identifier("export", str));
	while (++i < len && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (not_valid_identifier("export", str));
	}
	return (1);
}

int	update_path(const char *new_path, bool update_env)
{
	char	**new_split;

	if (update_env && ft_setenv("PATH", new_path))
		return (-1);
	if (new_path)
	{
		new_split = ft_split(new_path, ':');
		if (!new_split)
			return (-1);
	}
	else
		new_split = NULL;
	if (g_global_data.path)
		ft_destroy_array((void **)g_global_data.path, NULL_ENDED);
	g_global_data.path = new_split;
	return (0);
}

int	builtin_export(int argc, char **argv, char **envp)
{
	char	*rpl;
	int		ret;
	int		alloc_ret;

	(void)envp;
	while (*++argv)
	{
		if (!is_valid_arg(*argv))
		{
			ret = 1;
			continue ;
		}
		rpl = ft_rplchr(*argv, '=', '\0');
		if (!ft_strcmp(*argv, "PATH"))
		{
			rpl += !!rpl;
			alloc_ret = update_path(rpl, true);
		}
		else if (!rpl)
			alloc_ret = ft_setenv(*argv, NULL);
		else
			alloc_ret = ft_setenv(*argv, rpl + 1);
		if (alloc_ret)
			return (minishell_error());
	}
	if (argc == 1 && ft_printexp(g_global_data.env->data))
		return (minishell_error());
	return (ret);
}
