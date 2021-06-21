#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char		buf[SWAP_BUFFER_SIZE];
	size_t		n;

	while (size)
	{
		if (size >= SWAP_BUFFER_SIZE)
			n = SWAP_BUFFER_SIZE;
		else
			n = size;
		ft_memcpy(buf, a, n);
		ft_memcpy(a, b, n);
		ft_memcpy(b, buf, n);
		size -= n;
		a += n;
		b += n;
	}
}
