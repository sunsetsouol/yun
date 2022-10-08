#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MailList
{
	char Name[20];
	char Number[20];
	char Relationship[20];
	struct MailList *next;
} list;
list* add(list *Phead);
list *listsearch(list *Phead);
list *listdelete(list *Phead);
#endif
