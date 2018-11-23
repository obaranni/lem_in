#include "../inc/lem_in.h"

int 		is_it_ants(t_read *r)
{
	char 	*box;

	box = r->buf;
	if (r->buf && *r->buf)
	{
		while (*box)
		{
			if (!ft_isdigit(*box))
			{
//				free(r->buf);
				return (0);
			}
			box++;
		}
	}
	return (1);
}

int			read_ants(t_read *r)
{
	if (r->ants_readed)
	{
		set_error(r, "Ants already readed!", r->i + 1, ERR);
		return (0);
	}
	r->ants = ft_atoi(r->buf);
	r->ants_readed = 1;
	return (1);
}