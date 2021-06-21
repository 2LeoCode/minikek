#include <libft.h>

char	*ft_strtrim(const char *s, const char *set)
{
	const size_t	set_len = ft_strlen(set);
	const size_t	s_len = ft_strlen(s);
	const char		*end_ptr = s + s_len - 1;
	char			*trimmed;

	while (*s && ft_memchr(set, *s, set_len))
		s++;
	if (!*s)
		return (ft_memdup("", 0));
	while ((end_ptr != s) && ft_memchr(set, *end_ptr, set_len))
		end_ptr--;
	trimmed = ft_memndup(s, s_len, (size_t)end_ptr - (size_t)s + 1);
	return (trimmed);
}
