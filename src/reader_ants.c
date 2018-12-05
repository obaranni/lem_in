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
				return (0);
			box++;
		}
	}
	return (1);
}

short int			ft_pwrbase(ssize_t num, int base)
{
	short int		counter;

	base = (!base) ? 10 : base;
	counter = 1;
	if (num < 0 || base < 0)
		counter++;
	if (num == base && base < 10)
		return (counter);
	while ((num /= base))
		counter++;
	return (counter);
}


int			read_ants(t_read *r)
{
	if (r->ants_readed)
	{
		set_error(r, "Ants already read!", r->i + 1, ERR);
		return (0);
	}
	r->ants_readed = (unsigned int)ft_atoi(r->buf);
	if (ft_strlen(r->buf) != ft_pwrbase(r->ants_readed, 10))
	{
		set_error(r, "Too many ants!", r->i + 1, ERR);
		return (0);
	}
	return (1);
}