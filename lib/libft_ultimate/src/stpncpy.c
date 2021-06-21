#include <libft.h>

char	*ft_stpncpy(char *dst, const char *src, size_t n)
{
	const size_t	size = ft_strnlen(src, n);

	ft_memcpy(dst, src, size);
	dst += size;
	if (size != n)
		ft_bzero(dst, n - size);
	return (dst);
}
