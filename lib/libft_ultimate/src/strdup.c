#include <libft.h>

char	*ft_strdup(const char *s1)
{
	void			*s;
	const size_t	len = ft_strlen(s1);

	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	return ((char *)ft_memcpy(s, s1, len + 1));
}
