#include <minishell.h>

bool	ft_env_exists(const char *name)
{
	int				i;
	const size_t	name_len = ft_strlen(name);

	i = -1;
	while (++i < g_global_data.env->count)
		if (ft_strlen(g_global_data.env->data[i]) >= name_len
			&& (!ft_strcmp(g_global_data.env->data[i], name)
				|| (!ft_memcmp(g_global_data.env->data[i], name, name_len)
					&& g_global_data.env->data[i][name_len] == '=')))
			return (true);
	return (false);
}

void	put_new_env_to_global(struct s_env *new_env)
{
	free(g_global_data.env);
	g_global_data.env = new_env;
}
