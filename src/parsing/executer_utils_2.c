#include <minishell.h>

void	set_back_fds(void)
{
	close(0);
	close(1);
	close(2);
	dup2(0, g_global_data.stdfd[0]);
	dup2(1, g_global_data.stdfd[1]);
}
