#include <libft.h>

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const size_t	len = ft_strlen(s);

	if (len > maxlen)
		return (maxlen);
	return (len);
}
