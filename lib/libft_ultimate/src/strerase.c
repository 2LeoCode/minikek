#include <libft.h>

int	ft_strerase(char **s, unsigned int i)
{
	const size_t	len = ft_strlen(*s);
	char			*new_s;

	if (i >= len)
		return (-1);
	new_s = (char *)malloc(sizeof(char) * len);
	if (!new_s)
		return (-1);
	ft_memcpy(new_s, *s, i);
	ft_stpcpy(new_s + i, *s + i + 1);
	free(*s);
	*s = new_s;
	return (0);
}
