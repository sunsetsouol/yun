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
		printf("\t\t\t\t|--------------------通讯录--------------------|\n");
		printf("\t\t\t\t|0.结束程序\n");
		printf("\t\t\t\t|1.录入联系人信息\n");
		printf("\t\t\t\t|2.查询联系人信息\n");
		printf("\t\t\t\t|3.修改联系人信息\n");
		printf("\t\t\t\t|4.删除联系人\n\n\n");
		printf("输入相应编号进行相关操作\n"); 
		scanf("%d",&menu);
		system("cls");
		if(menu==1)
		{
			printf("请依次输入姓名 号码 关系 \n");
			head=add (head);
			printf("录入成功");
		}
		if(menu==4)
		{
			list *q,*p;
			printf("请输入要删除的联系人姓名\n");
			p=listsearch(head);
			if(p)
				free(p);
			else
				printf("没有找到该联系人\n");

		}
		if(menu==2)
		{
			list *p;
			printf("请输入要查询的联系人名字\n");
			p=listsearch(head);
			if(p)
				printf("号码；%s,关系；%s\n",p->Number ,p->Relationship );
			else
				printf("没有找到该联系人\n");
		}
		if(menu==3)
		{
			list *p;
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
		if(menu==5) 
		{
			list *p;
			for(p=head;p;p=p->next )
			{
				printf("姓名；%s，号码；%s，关系；%s",p->Name ,p->Number ,p->Relationship );
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
		printf("无法打开该文件\n");

	fprintf(fp,"end\n \n \n \n");
	fclose(fp);

	return 0;
}
