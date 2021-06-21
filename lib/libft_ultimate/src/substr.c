#include <libft.h>

char	*ft_substr(const char *s, unsigned start, size_t n)
{
	const size_t	len = ft_strlen(s);

	if (len < start)
		return (ft_memdup("", 0));
	return (ft_memndup(s + start, len - start, n));
}
