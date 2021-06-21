#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	const size_t	total_size = count * size;

	s = malloc(total_size);
	if (s)
		ft_bzero(s, total_size);
	return (s);
}
