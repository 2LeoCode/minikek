#include <minishell.h>

bool	check_error(pid_t *pid_value, char *executable_name)
{
	if (errno == ENOMEM)
		return (true);
	if (*pid_value == -1)
	{
		g_global_data.status = command_error(executable_name);
		*pid_value = 0;
	}
	return (false);
}

int	file_error(const char *path_to_file)
{
	printf("minishell: %s: %s\n", strerror(errno), path_to_file);
	dup2(g_global_data.stdfd[0], 0);
	dup2(g_global_data.stdfd[1], 1);
	return (-2);
}

int	create_file(const char *path, int flag)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | flag,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

void	close_all_fds(void)
{
	int	i;

	i = 2;
	while (++i <= 256)
		close(i);
}

void	end_exec(pid_t cpid)
{
	wait_if_child_running(&cpid);
	dup2(g_global_data.stdfd[0], 0);
	dup2(g_global_data.stdfd[1], 1);
	close_all_fds();
}
