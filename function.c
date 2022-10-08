#include "function.h"
list* add(list *Phead)
{
	printf("ĞÕÃû ºÅÂë ¹ØÏµ£»\n");
	list *p=(list*)malloc(sizeof(list));
	scanf("%s %s %s",&(p->Name) ,&(p->Number) ,&(p->Relationship) );
	p ->next=NULL;
	list *last=Phead;
	if(last)
	{
		while(last->next )
		{
			last=last->next ;
		}
		last ->next=p;
	}
	else
		Phead =p;
	return Phead;
}

list *listsearch(list *Phead)
{
	list *p;
	char name[20];
	scanf("%s",&name);
	if(strcmp(Phead->Name ,name)==0)
		p=Phead;
	else
	{
		p=Phead->next ;
		while(p && strcmp(p->Name ,name)!=0)
		{
			p=p->next ;
		}
	}
	return p;
}
