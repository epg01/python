/*
 * Error handling: Division zero.
 */
#include <stdio.h>     /*
			* include printf funciotn.
			*/
#include <stdlib.h>    /*
			* include exit function.
			*/

int main(void)
{
	int Division(int Number);

	printf("%d\n", Division(32));
	printf("%d\n", Division(43));
	printf("%d\n", Division(0));
	return (0);
}

int Division(int Number)
{
	if (Number)
		return (42 / Number);
	else
	{
		printf("No existe división entre cero.");
		exit(1);
	}
}
