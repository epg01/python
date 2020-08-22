 /*
 * This program that keep asking you to type, litarally, 'your name'
 */

#include <stdio.h>
#include <stdlib.h>

#define Buff_Size 1000
#define True      1
#define Character_String(String_Character) ((*String_Character) == ' ' || (*String_Character) == '\n' || (*String_Character) == '\t')

int _getline(char **String_Character, int *Length_String)
{
	int Character = 0, State = 1;
	char String[Buff_Size];

	while (True)
	{
		if ((*Length_String < Buff_Size) && State)
		{
			Character = getchar();
			String[(*Length_String)++] = Character;
		}
		if ((Character == '\n' || Character == EOF) && State)
		{
			*String_Character = (char *)malloc(sizeof(char) * (*Length_String + 1));
			(*Length_String) = State = 0;
		}
		else if (!State)
		{
			(*String_Character)[*Length_String] = String[*Length_String];
			if (String[*Length_String] == '\n' || String[*Length_String] == EOF)
				break;
			(*Length_String)++;
		}
	}
	if (String[*Length_String] == '\n')
		(*String_Character)[(*Length_String)++] = Character;
	(*String_Character)[*Length_String] = '\0';
	return (*Length_String);
}

int Match(char *Key, char *String_Character)
{
	while (*Key)
	{
		if (*Key == *String_Character)
			Key++, String_Character++;
		else
			break;
	}
	while (*String_Character)
		if (Character_String(String_Character))
			String_Character++;
		else
			break;
	if (!*String_Character)
		return (0);
	else
		return (1);
}

int main(void)
{
	char *String_Character = NULL;
	int Length_String      = 0;

	while ((_getline(&String_Character, &Length_String) != EOF))
	{
		if (!(Match("your name", String_Character)))
		{
			printf("Well done\n");
			break;
		}
		else
		{
			printf("Try again, write your name\n");
			free(String_Character);
			String_Character = NULL;
			Length_String    = 0;
		}
	}
	free(String_Character);
	return (0);
}
