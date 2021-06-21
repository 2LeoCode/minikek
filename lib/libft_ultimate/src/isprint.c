#include <libft.h>

int	ft_isprint(int c)
{
	return ((c < 127) && (c >= ' '));
}
