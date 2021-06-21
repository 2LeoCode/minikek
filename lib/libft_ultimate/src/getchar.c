#include <libft.h>

int	ft_getchar(void)
{
	unsigned int	key;

	key = 0;
	if (read(0, &key, 3) == -1)
		return (-1);
	return (key);
}
