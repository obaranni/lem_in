#include "../inc/lem_in.h"

void		free_str_arr(char **strs)
{
	int 	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}