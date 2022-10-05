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
	printf("������������� ���� ��ϵ \n");
	head=add (head);
	list *p;
	do
	{
		printf("����-1����������1¼����ϵ����Ϣ������0ɾ����ϵ��,����2��ѯ������3�޸�,����4����ϵ�˱������ļ���\n");
		scanf("%d",&menu);

		if(menu==1)
		{
			printf("������������� ���� ��ϵ \n");
			head=add (head);
		}
		if(menu==0)
		{
			list *q;
			printf("������Ҫɾ������ϵ������\n");
			p=listsearch(head);
			if(p)
				free(p);
			else
				printf("û���ҵ�����ϵ��\n");

		}
		if(menu==2)
		{

			printf("������Ҫ��ѯ����ϵ������\n");
			p=listsearch(head);
			if(p)
				printf("���룻%s,��ϵ��%s\n",p->Number ,p->Relationship );
			else
				printf("û���ҵ�����ϵ��\n");
		}
		if(menu==3)
		{
			printf("������Ҫ�޸���ϵ������\n");
			p=listsearch(head);
			if(p)
			{
				printf("��������� ��ϵ\n");
				scanf("%s %s",&p ->Number ,&p ->Relationship ) ;
			}
			else
				printf("û���ҵ�����ϵ��\n");
		}
		if(menu==4)
		{
			p=head;
			FILE *fp=fopen("maillist","a+");
			if(p==NULL)
				printf("�޷��򿪸��ļ�\n");
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
	printf("���� ���� ��ϵ��\n");
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
