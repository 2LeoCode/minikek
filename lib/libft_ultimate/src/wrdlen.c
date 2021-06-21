#include <libft.h>

size_t	ft_wrdlen(const char *s)
{
	const char	*ptr = s;

	while (*ptr && !ft_isspace(*ptr) && !ft_ispunct(*ptr))
		ptr++;
	return ((size_t)ptr - (size_t)s);
}
