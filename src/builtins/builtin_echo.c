/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:54:54 by lsuardi           #+#    #+#             */
/*   Updated: 2021/03/28 23:55:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_valid_nflag(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	ft_putecho(char **av, int ac, bool *n_flag)
{
	int		i;
	bool	no_more_n;

	i = 1;
	no_more_n = false;
	while (i < ac && ft_strncmp(av[i], "-n", 2) == 0
		&& is_valid_nflag(av[i]))
	{
		*n_flag = true;
		i++;
	}
	while (i < ac)
	{
		if (no_more_n)
			ft_putchar_fd(' ', 1);
		no_more_n = true;
		ft_putstr(av[i]);
		i++;
	}
	if (!*n_flag)
		ft_putchar_fd('\n', 1);
}

int	builtin_echo(int argc, char **argv, char **envp)
{
	bool	n_flag;

	(void)envp;
	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	n_flag = false;
	ft_putecho(argv, argc, &n_flag);
	return (0);
}
