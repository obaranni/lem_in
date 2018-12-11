#include <stdio.h>



int		main(void)
{
	int const_room;
	int const_ways;
	int next_room;
	int next_ways;	

	const_room = 2;
	const_ways = 4;

	while (next_ways < 1000000000)
	{
		next_room = const_room + 1;
		next_ways = const_ways * next_room + next_room;
		printf("Ways: %d\n", next_ways);
		const_room = next_room;
		const_ways = next_ways;
	}

	return (0);
}
