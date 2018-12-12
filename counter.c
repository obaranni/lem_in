#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int		main(int ac, char **av)
{
	int const_room;
	unsigned long long const_ways;
	int next_room;
	unsigned long long next_ways;	
	int	room;
	int	i;


	if (ac != 2)
	{
		printf("./a.out [room_to_find_ways]\n");
		return (1);
	}
	const_room = 2;
	const_ways = 4;
	next_ways = const_ways;
	room = atoi(av[1]);

	if (room == 0)
	{
		printf("Ways: 1\n");
		return (0);
	}
	else if (room == 1)
	{
		printf("Ways: 2\n");
		return (0);
	}

	i = 2;
	while (i < room)
	{
		next_room = const_room + 1;
		next_ways = const_ways * next_room + next_room;
		const_room = next_room;
		const_ways = next_ways;
		i++;
	}
	printf("Ways: %llu\n", next_ways);

	return (0);
}
