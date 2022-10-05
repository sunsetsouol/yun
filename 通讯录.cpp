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
int main()
{
	list *head=NULL;
	int menu;
	printf("请依次输入号码 姓名 关系 \n");
	head=add (head);
	list *p;
	do
	{
		printf("输入-1结束，输入1录入联系人信息，输入0删除联系人,输入2查询，输入3修改,输入4将联系人保存至文件夹\n");
		scanf("%d",&menu);

		if(menu==1)
		{
			printf("请依次输入号码 姓名 关系 \n");
			head=add (head);
		}
		if(menu==0)
		{
			list *q;
			printf("请输入要删除的联系人姓名\n");
			p=listsearch(head);
			if(p)
				free(p);
			else
				printf("没有找到该联系人\n");

		}
		if(menu==2)
		{

			printf("请输入要查询的联系人名字\n");
			p=listsearch(head);
			if(p)
				printf("号码；%s,关系；%s\n",p->Number ,p->Relationship );
			else
				printf("没有找到该联系人\n");
		}
		if(menu==3)
		{
			printf("请输入要修改联系人姓名\n");
			p=listsearch(head);
			if(p)
			{
				printf("请输入号码 关系\n");
				scanf("%s %s",&p ->Number ,&p ->Relationship ) ;
			}
			else
				printf("没有找到该联系人\n");
		}
		if(menu==4)
		{
			p=head;
			FILE *fp=fopen("maillist","a+");
			if(p==NULL)
				printf("无法打开该文件\n");
			while(p)
			{
				fprintf(fp,"%s\n%s\n%s\n",p->Name ,p->Relationship ,p->Number );
				p=p->next ;
			}
			fclose(fp);
		}
	}
	while(menu!=-1);
	return 0;
}
list* add(list *Phead)
{
	printf("号码 姓名 关系；\n");
	list *p=(list*)malloc(sizeof(list));
	scanf("%s %s %s",&(p->Number) ,&(p->Name) ,&(p->Relationship) );
	p ->next=NULL;
	list *last=Phead;
	if(Phead)
	{
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
