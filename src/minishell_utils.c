#include <minishell.h>

void	ft_sort_strarray(char **arr, int (*cmpf)(const char *, const char *))
{
	char	**it;

	while (*arr)
	{
		it = arr;
		while (*++it)
			if ((*cmpf)(*arr, *it) > 0)
				ft_swap(arr, it, sizeof(char *));
		arr++;
	}
}
