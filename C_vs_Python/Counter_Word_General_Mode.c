/*
 * This progam counts the ocurrences of each word.
 */

/*
 * We include the library <stdio.h> to use the getline and print function and
 * the <stdlib.h> library to dynamically allocate memory.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Binary tree data structure.
 */

/**
 * struct Elemet_ - Data structure that will contain the elements of the list.
 * @Name: Pointer to name, That is, it will contain the word that is written
 *        in the terminal.
 * @Number_Of_Ocurrence_Of_Name: Number of times the word is repetead.
 * @Rigth: Pointer to a structure of type struct Element.
 * Lefth: Pointer to a structure of type struct Element.
 */

struct Element_
{
	char *Name;
	size_t Number_Of_Ocurrence_Of_Name;
	struct Element_ *Right;
	struct Element_ *Left;
};

/**
 * struct List_ - Structure that contains the information of the list, that is,
 *                the size of the list and two pointers to funciotns.
 * @Size_List:    List size, that is, the number of the nodes that the list contains.
 * @Head:         Pointer to the first node created in the data structure.
 * @Match:        Pointer to funtion that compares two string.
 * @Destroy:      Pointer to funtion that destroys the memory dynamically allocated
 *                to the name pointer.
 */

struct List_
{
	size_t Size_List;
	struct Element_ *Head;
	int (*Match)(char *Data1, char *Data2);
	void (*Destroy)(char *Data);
};

typedef struct Element_ Element;
typedef struct List_ List;

/**
 * Match - Match function, work as a lexicographic function.
 * @Key1: String to compare.
 * @Key2: String to compare.
 */

int Match(char *Key1, char *Key2)
{
	while (*Key1 && *Key2)
		if (*Key1 == *Key2)
			Key1++, Key2++;
		else if (*Key1 < *Key2)
			return (1);
		else
			return (-1);
	if (!(*Key1) && !(*Key2))
		return (0);
	else
		return (-1);
}

/**
 * List_Ins - Function that creates a node or counts a repeated word within a
 *            node previously created by this function.
 * @element: double pointer to data structure.
 * @Name: Pointer to a string of characters, this contains the word written in the terminal.
 */

int List_Ins(Element **element, char *Name)
{
	int State = 0;

	if (!(*element))
	{
		Element *New_Element;

		New_Element = (Element *)malloc(sizeof(Element));

		if (!New_Element)
			return (-1);
		else
		{
			New_Element->Name                        = Name;
			New_Element->Right                       = New_Element->Left = NULL;
			New_Element->Number_Of_Ocurrence_Of_Name = 1;
			(*element)                               = New_Element;
			return (0);
		}
	}
	else if (!(State = Match((*element)->Name, Name)))
	{
		((*element)->Number_Of_Ocurrence_Of_Name)++;
		return (0);
	}
	else if (State == 1)
		return (List_Ins(&((*element)->Right), Name));
	else
		return (List_Ins(&((*element)->Left), Name));
}

/**
 * List_Init - Function that initializes the binary tree structure.
 * @list: Pointer to list.
 * @Destroy: Pointer to function.
 * @Match: Pointer to function.
 */

void List_Init(List *list, void (*Destroy)(char *Data), int (*Match)(char *Data1, char *Data2))
{
	list->Size_List = 0;
	list->Match     = Match;
	list->Destroy   = Destroy;
	list->Head      = NULL;
	printf("Se inicializo la estructura de datos tipo arboles binario\n");
	printf("\tTamaño de la lista = %d\n", (int)list->Size_List);
	printf("\tPuntero Head       = %p\n", (void *)list->Head);
}

/**
 * Organizar_String - Eliminate the line break placed in the terminal.
 * @String: String that is placed in the terminal.
 */

void Organizar_String(char *String)
{
	while (*String)
		String++;
	if (String[-1] == '\n')
		String[-1] = *String;
}

/**
 * main - Function to count the occurrences of words.
 */

int main(void)
{
	void print_Structure_Data(Element *);

	List list;
	char *String_Character = NULL;
	size_t Counter         = 0;


	List_Init(&list, NULL, NULL);
	while (getline(&String_Character, &Counter, stdin) != EOF)
	{
		Organizar_String(String_Character);
		if (!(List_Ins(&(list.Head), String_Character)))
		{
			String_Character = NULL;
			Counter          = 0;
		}
		else
		{
			free(String_Character);
			break;
		}
	}
	printf("Se procedera a imprimir el arbol binario\n");
	print_Structure_Data(list.Head);
}

/**
 * print_Structure_Data - Function that prints the binary tree data structure.
 * @element: pointer to list items.
 */

void print_Structure_Data(Element *element)
{
	if (element)
	{
		print_Structure_Data(element->Right);
		printf("%s ", element->Name);
		printf("%d\n", (int)element->Number_Of_Ocurrence_Of_Name);
		print_Structure_Data(element->Left);
	}
}
