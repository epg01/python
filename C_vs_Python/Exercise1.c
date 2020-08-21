#include <stdio.h>
#include <stdlib.h>

int Match(char *Key, char *Name_Joined)
{
	while(*Key)
		if (*Key == *Name_Joined)
			Key++, Name_Joined++;
		else
			return (-1);
	if (!(*Name_Joined))
		return (0);
	else
		printf("Escribiste mal el nombre\n");
	return (-2);
}

int main(void)
{
	char Name_Joined[10];

	printf("Ingrese el nombre de Emmanuel\n");
	scanf("%s", Name_Joined);

	if (!(Match("Emmanuel", Name_Joined)))
		printf("Hello, Emmanuel welcome.\n");
	else
		printf("No eres Emmanuel :p\n");
	return (0);
}
