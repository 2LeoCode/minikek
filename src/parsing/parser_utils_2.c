#include <minishell.h>

static size_t	empty_string_cnt(int argc, char **argv)
{
	size_t	cnt;

	cnt = 0;
	while (argc--)
		if (!*argv[argc])
			cnt++;
	return (cnt);
}

static int	alloc_new_cmd(t_cmd **new, int ac, t_cmd *old)
{
	char			**ptr;
	int				i;

	*new = malloc(sizeof(t_cmd) + sizeof(char *) * (ac + 1));
	if (!*new)
		return (-1);
	(*new)->pipe = old->pipe;
	(*new)->redirect_out = old->redirect_out;
	(*new)->redirect_out2 = old->redirect_out2;
	(*new)->in = old->in;
	(*new)->out = old->out;
	(*new)->argc = ac;
	ptr = old->argv - 1;
	i = 0;
	while (*++ptr)
	{
		if (!**ptr)
		{
			free(*ptr);
			*ptr = NULL;
		}
		else
			(*new)->argv[i++] = *ptr;
	}
	return (0);
}

int	remove_empty_strings(t_cmd **cmd)
{
	const size_t	empty_cnt = empty_string_cnt((*cmd)->argc, (*cmd)->argv);
	t_cmd			*new_cmd;
	int				new_argc;

	if (!empty_cnt)
		return (0);
	new_argc = (*cmd)->argc - empty_cnt;
	if (alloc_new_cmd(&new_cmd, new_argc, *cmd))
		return (-1);
	new_cmd->argv[new_argc] = NULL;
	free(*cmd);
	*cmd = new_cmd;
	return (0);
}
