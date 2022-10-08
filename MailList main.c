#include "function.h"
int main()
{
	list *head=NULL;
	int menu;
	FILE *fp=fopen("maillist","r");
	if(fp)
	{
		char end[20]="end";
		list *p;
		int isleap=0;
		do
		{
			list *p=(list *)malloc(sizeof(list));
			fscanf(fp,"%s %s %s",&(p->Name) ,&(p->Number) ,&(p->Relationship));
			p->next =NULL;
			list *last=head;
			if(strcmp(p->Name ,end)!=0)
			{
				if(last)
				{
					while(last->next )
					{
						last=last->next ;
					}
					last->next =p;
				}
				else
				{
					head=p;
				}
			}else
			{
				isleap=-1;
			}
		}
		while(isleap!=-1);
	}
	fclose(fp);

	do
	{
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t|--------------------ͨѶ¼--------------------|\n");
		printf("\t\t\t\t|0.��������\n");
		printf("\t\t\t\t|1.¼����ϵ����Ϣ\n");
		printf("\t\t\t\t|2.��ѯ��ϵ����Ϣ\n");
		printf("\t\t\t\t|3.�޸���ϵ����Ϣ\n");
		printf("\t\t\t\t|4.ɾ����ϵ��\n\n\n");
		printf("������Ӧ��Ž�����ز���\n"); 
		scanf("%d",&menu);
		system("cls");
		if(menu==1)
		{
			printf("�������������� ���� ��ϵ \n");
			head=add (head);
			printf("¼��ɹ�");
		}
		if(menu==4)
		{
			list *q,*p;
			printf("������Ҫɾ������ϵ������\n");
			p=listsearch(head);
			if(p)
				free(p);
			else
				printf("û���ҵ�����ϵ��\n");

		}
		if(menu==2)
		{
			list *p;
			printf("������Ҫ��ѯ����ϵ������\n");
			p=listsearch(head);
			if(p)
				printf("���룻%s,��ϵ��%s\n",p->Number ,p->Relationship );
			else
				printf("û���ҵ�����ϵ��\n");
		}
		if(menu==3)
		{
			list *p;
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
		if(menu==5) 
		{
			list *p;
			for(p=head;p;p=p->next )
			{
				printf("������%s�����룻%s����ϵ��%s",p->Name ,p->Number ,p->Relationship );
			}
			
		}

	}
	while(menu!=0);

	list *p=head;
	fp=fopen("maillist","w");
	if(fp)
	{
		while(p)
		{
			fprintf(fp,"%s\n%s\n%s\n",p->Name ,p->Relationship ,p->Number );
			p=p->next ;
		}
	}
	else
		printf("�޷��򿪸��ļ�\n");

	fprintf(fp,"end\n \n \n \n");
	fclose(fp);

	return 0;
}
