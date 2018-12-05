#include "../inc/libft.h"

static void	ft_print_float(int fd, float nbr)
{
	float	tmp;
	long	l;

	tmp = nbr;
	l = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		if (l > 1000000000)
			return ;
		l *= 10;
	}
	while (l)
	{
		ft_putchar_fd((char)(((long)nbr / l) + '0'), fd);
		nbr = nbr - (((long)nbr / l) * (float)l);
		l /= 10;
	}
}

void		ft_putnbr_float(int fd, float nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	ft_print_float(fd, nbr);
	write(fd, ".", 1);
	nbr -= (int)nbr;
	nbr *= 1000000;
	ft_print_float(fd, nbr);
}