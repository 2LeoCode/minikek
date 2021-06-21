#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	ft_mempcpy(dst, src, n);
	return (dst);
}
