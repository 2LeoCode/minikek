#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const void	*p = ft_memchr(src, c, n);

	if (p)
		return (ft_mempcpy(dst, src, (size_t)p - (size_t)src + 1UL));
	ft_memcpy(dst, src, n);
	return (NULL);
}
