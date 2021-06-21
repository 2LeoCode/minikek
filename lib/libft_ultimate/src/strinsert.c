#include <libft.h>

int	ft_strinsert(char **s, unsigned int i, int c)
{
	const size_t	len = ft_strlen(*s);
	char			*new_s;

	if (i > len)
		return (-1);
	new_s = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_s)
		return (-1);
	new_s[i] = c;
	ft_memcpy(new_s, *s, i);
	ft_stpcpy(new_s + i + 1, *s + i);
	free(*s);
	*s = new_s;
	return (0);
}
