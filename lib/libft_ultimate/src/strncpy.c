#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	const size_t	size = ft_strnlen(src, n);

	ft_memcpy(dst, src, size);
	if (n != size)
		ft_bzero(dst + size, n - size);
	return (dst);
}
