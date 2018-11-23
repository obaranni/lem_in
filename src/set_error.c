#include "../inc/lem_in.h"

int 		set_error(t_read *r, char *err_msg, int err_line, int err_lvl)
{
	r->error.err_msg = (char*)malloc(sizeof(char)
			* (ft_strlen(err_msg)));
	ft_strcpy(r->error.err_msg, err_msg);
	r->error.err_line = err_line;
	r->error.err_lvl = err_lvl;
	return(1);
}