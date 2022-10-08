#include "function.h"
list* add(list *Phead)
{
	printf("姓名 号码 关系；\n");
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
list *listdelete(list *Phead)
{
	list *p,*q=Phead;
	char name[20];
	printf("请输入要删除的联系人姓名\n");
	scanf("%s",&name);
	if(strcmp(Phead->Name ,name)==0)
	{
		Phead=q->next ;
		free(q);
	}
	else
	{
		p=Phead->next ;
		while(p && strcmp(p->Name ,name)!=0)
		{
			q=p;
			p=q->next ;
		}
		if(p)
	{
		if(p->next )
		{
			q->next =p->next ;
			free(p);
		}
		else
		{
			free(p);
			q->next =NULL;
		}
	}
	else
		printf("没有找到该联系人\n");
	}
	return Phead;
}
