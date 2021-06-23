#include <minishell.h>

void	ft_sort_strarray(char **arr, int (*cmpf)(const char *, const char *))
{
	char	**it;
	char	**smallest;

	while (*arr)
	{
		smallest = arr;
		it = arr;
		while (*++it)
			if ((*cmpf)(*smallest, *it) > 0)
				smallest = it;
		if (arr != smallest)
			ft_swap(*arr, *smallest, sizeof(void *));
		arr++;
	}
}
