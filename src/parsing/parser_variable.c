#include <minishell.h>

static int	replace_questionmark_env(char **token, char **ptr_to_dollar)
{
	const size_t	ptr_index = (size_t)(*ptr_to_dollar) - (size_t)(*token);
	char			*env;

	env = ft_itoa(g_global_data.status);
	if (!env || ft_strreplace_first(token, "$?", env, free))
	{
		free(env);
		return (-1);
	}
	free(env);
	*ptr_to_dollar = *token + ptr_index;
	return (0);
}

static int	replace_regular_env(char **token, char **ptr_to_dollar)
{
	char			*to_replace;
	char			*env;
	bool			failure;
	const size_t	ptr_index = (size_t)(*ptr_to_dollar) - (size_t)(*token);

	failure = false;
	to_replace = ft_strndup(*ptr_to_dollar, ft_wrdlen(*ptr_to_dollar + 1) + 1);
	ft_rplchr(to_replace, '\"', 0);
	if (!to_replace)
		return (-1);
	env = ft_getenv(to_replace + 1);
	if (!env)
		env = "";
	if (ft_strreplace_first(token, to_replace, env, free))
		failure = true;
	free(to_replace);
	if (failure)
		return (-1);
	*ptr_to_dollar = *token + ptr_index;
	return (0);
}

static char	*go_to_next_var(const char *tok)
{
	char	*ptr;

	ptr = ft_strchr(tok, '$');
	while (ptr && ptr[1] != '?'
		&& (!ptr[1] || ft_isspace(ptr[1]) || ft_ispunct(ptr[1])))
		ptr = ft_strchr(ptr + 1, '$');
	return (ptr);
}

int	replace_env_tokens(char **tokens)
{
	char	*ptr;

	while (*tokens)
	{
		if (**tokens != '\'')
		{
			ptr = go_to_next_var(*tokens);
			while (ptr)
			{
				if (!ft_memcmp(ptr, "$?", 2))
				{
					if (replace_questionmark_env(tokens, &ptr))
						return (-1);
				}
				else if (replace_regular_env(tokens, &ptr))
					return (-1);
				ptr = go_to_next_var(ptr + !!*ptr);
			}
		}
		tokens++;
	}
	return (0);
}
