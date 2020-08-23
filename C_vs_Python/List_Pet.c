/*
 * This program lets the user type in a pet named and then check
 * to see whether the name is in a list of pets.
 */

#include <stdio.h>

void Copy(char *String_Character)
{
	while (*String_Character)
		String_Character++;
	if (String_Character[-1] == '\n')
		String_Character[-1] = *String_Character;
}
int Match(char *Key, char *String_Character)
{
	while (*Key)
		if (*Key == *String_Character)
			Key++, String_Character++;
		else
			return (-1);
	if (!(*String_Character))
		return (0);
	else
		return (1);
}
int main(void)
{
	char *String_Character = NULL;
	size_t Counter         = 0;
	char *argv[]           = {"Zhopia", "Claus", "Linda", "Zam", NULL};
	unsigned int Index     = 0;

	getline(&String_Character, &Counter, stdin);
	Copy(String_Character);
	while (argv[Index])
	{
		if (!(Match(argv[Index], String_Character)))
		{
			printf("%s is my pet\n", String_Character);
			return (0);
		}
		else
			Index++;
	}
	printf("I do not have a pet named %s\n", String_Character);
	return (1);
}
