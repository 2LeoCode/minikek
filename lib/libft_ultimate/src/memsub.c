#include <libft.h>

void	*ft_memsub(const void *s, size_t len, unsigned start, size_t n)
{
	if (len < start)
		return (ft_memdup("", 0));
	return (ft_memndup(s + start, len - start, n));
}
