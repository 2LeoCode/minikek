#include <minishell.h>

/*static int	remove_quotes(char **s_ptr)
{
	char	*new_s;

	new_s = ft_strntrim(*s_ptr, "\"\'", 1);
	if (!new_s)
		return (-1);
	free(*s_ptr);
	*s_ptr = new_s;
	return (0);
}*/

static void	fill_until_c(char **old, char *new, int *i, int c)
{
	while (*++*old && **old != c)
		new[(*i)++] = **old;
}

static int	remove_quotes(char **s)
{
	char	*new_s;
	char	*s_ptr;
	int		i;

	s_ptr = *s;
	new_s = ft_calloc(ft_strlen(s_ptr) + 1, sizeof(char));
	if (!new_s)
		return (-1);
	i = 0;
	while (*s_ptr)
	{
		if (*s_ptr == '\'')
			fill_until_c(&s_ptr, new_s, &i, '\'');
		else if (*s_ptr == '\"')
			fill_until_c(&s_ptr, new_s, &i, '\"');
		else
			new_s[i++] = *s_ptr;
		s_ptr += !!*s_ptr;
	}
	free(*s);
	*s = new_s;
	return (0);
}

t_cmd	**cmd_arr_without_quotes(t_cmd **cmd_arr)
{
	int	i;
	int	j;

	i = -1;
	while (cmd_arr[++i])
	{
		j = -1;
		while (++j < cmd_arr[i]->argc)
			if (remove_quotes(&cmd_arr[i]->argv[j]))
				return (NULL);
	}
	return (cmd_arr);
}

/*t_cmd	**cmd_arr_without_quotes(t_cmd **cmd_arr)
{
	int	i;
	int	j;

	i = -1;
	while (cmd_arr[++i])
	{
		j = -1;
		while (++j < cmd_arr[i]->argc)
		{
			if ((*cmd_arr[i]->argv[j] == '\'' || *cmd_arr[i]->argv[j] == '\"')
				&& remove_quotes(&cmd_arr[i]->argv[j]))
			{
				destroy_cmd_array(cmd_arr);
				return (NULL);
			}
		}
	}
	return (cmd_arr);
}*/

void	*invalid_file(const char *path)
{
	ft_putstr_fd("minishell: ", 2);
	perror(path);
	return (NULL);
}

void	add_to_av(char **token, t_cmd *current_cmd, unsigned int *index)
{
	current_cmd->argv[(*index)++] = *token;
	*token = NULL;
}
