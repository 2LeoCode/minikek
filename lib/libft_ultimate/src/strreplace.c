#include <libft.h>

int	ft_strreplace(char *s, char *before, char *after)
{
	const size_t	len1 = ft_strlen(before);
	const size_t	len2 = ft_strlen(after);
	const size_t	len_s = ft_strlen(s);

	if (len1 != len2)
		return (-1);
	s = ft_memfind(s, before, len_s, len1);
	while (s)
	{
		ft_memcpy(s, after, len2);
		s = ft_memfind(s, before, len_s, len1);
	}
	return (0);
}
