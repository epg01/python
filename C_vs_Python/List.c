#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Data structure.
 */

struct Element_
{
	void *Data;
	struct Element_ *Next;
};

struct List_
{
	int Size_List;
	struct Element_ *Head;
	struct Element_ *Tail;
	void (*Destroy)(void *Data);
};

typedef struct Element_ Element;
typedef struct List_ List;

/*
 * Macros.
 */

#define List_Size(list)     (list)->Size_List
#define True                1

int List_Rem_Next(List *list, Element *element, void **Data)
{
	Element *Old_Element;

	if (!element)
	{
		Old_Element        = list->Head;
		*Data              = Old_Element->Data;
		list->Head         = Old_Element->Next;
	}
	free(Old_Element);
	List_Size(list)--;
	return (0);
}

void List_Destroy(List *list)
{
	char *Data;

	while (List_Size(list))
		if (!(List_Rem_Next(list, NULL, (void **)&Data)) && list->Destroy)
			list->Destroy(Data);
	/*
	 *  The structure is cleaned as a precaution
	 */

	memset(list, 0, sizeof(List));
	printf("The list will be printed\n");
	printf("Size of the list = %d\n", List_Size(list));
	printf("Pointer Destroy = %p\n", (void *)list->Destroy);
}

void List_Init(List *list, void (*Destroy)(void *Data))
{
	list->Size_List    = 0;
	list->Destroy = Destroy;
	list->Head    = NULL;
	list->Tail    = NULL;
	printf("The list is initialized\n");
}

int List_Init_Next(List *list, Element *element, void *Data)
{
	Element *NewElement = NULL;

	NewElement = (Element *)malloc(sizeof(Element));

	if (!NewElement)
		return (1);

	NewElement->Data = Data;
	if (!element)
	{
		if (!List_Size(list))
			list->Tail = NewElement;
		NewElement->Next = list->Head;
		list->Head       = NewElement;
	}
	List_Size(list)++;
	return (0);
}

void Destroy(void *Data)
{
	free((char *)Data);
}

void print(Element *Next)
{
	if (!Next)
		;
	else
	{
		print(Next->Next);
		printf("\t%s", (char *)Next->Data);
	}
}

void print_list(List *list)
{
	printf("The cate names are:\n");
	print(list->Head);
}
int main(void)
{
	List list;
	char *String   = NULL;
	size_t Counter = 0;
	List_Init(&list, Destroy);

	while (True)
	{
		printf("Enter the name of the cat %d (Or enter nothing to stop.)\n", list.Size_List + 1);
		if (getline(&String, &Counter, stdin) != EOF && *String != '\n')
		{
			List_Init_Next(&list, NULL, String);
			String = NULL, Counter = 0;
		}
		else
			break;
	}
	print_list(&list);
	List_Destroy(&list);

	return (0);
}
