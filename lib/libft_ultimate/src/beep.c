#include <libft.h>

void	ft_beep(void)
{
	write(1, "\007", 1);
}
