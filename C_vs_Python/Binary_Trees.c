#include <stdio.h>

struct Nodo_
{
	char *Name;
	char *Date;
	struct Nodo_ *Rigth;
	struct Nodo_ *Left;
};

typedef struct Nodo_ Nodo;

int Compare_String(char *String1, char *String2)
{
	while (*String1 && *String2)
	{
		if (*String1 == *String2)
		{
			*String1++;
			*String2++;
		}
		else if (*String1 < *String2)
			return (0); /*
				     *  Indicar izquierda.
				     */
		else
			return (-1);  /*
				      * Indicar derechar
				      */
	}
	if (!(*String1) && !(*String2))
		return (1);
	else
		return (0);
}

int Add_Nodo(Nodo **Next, char *Name)
{
	if (!(*Next))
	{
		Nodo *New_Nodo;
		New_Nodo        = (Nodo *)malloc(sizeof(Nodo));
		New_Nodo->Name  = Name;
		New_Nodo->Righ  = NULL;
		New_Nodo->Left = NULL;
		(*Next)         = New_Nodo;
	}
	else if (!(Compare_String((*Next)->Name, String_Character)))
	{
		return (Add_Nodo(&((*Next)->Left), String_Character))
	}
	else
		return (Add_Nodo(&((*Next)->Rigth), String_Character))
}

int main(void)
{
	char String_Character = NULL;
	size_t Counter        = 0;
	Nodo *Head            = NULL;

	while (getline(&String_Character, Counter, stdin) != EOF)
	{
		Add_Nodo(&Head, String_Character);
	}
}
