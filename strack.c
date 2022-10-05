#include "strack.h"
void pushnum(strack *s,int num)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=num;
	p->symbol=1;
	p->next=s->elem;
	s->elem=p;
	s->top++;
}
void pushsym(strack *s,char sym)
{
	node *p=(node *)malloc(sizeof(node));
	p->symbol=sym;
	p->data=0;
	p->next=s->elem;
	s->elem=p;
	s->top++;
}

int popnum(strack *s)
{
	int data=-1;
	if(s->top==0)
	{
		printf("error");
	}else
	{
		node *p=s->elem;
		s->elem=p->next;
		data=p->data;
		free(p);
		s->top--;
	}
	return data;
}
char popsym(strack *s)
{
	char sym=0;
	if(s->top==0)
	{
		printf("error");
	}else
	{
		node *p=s->elem;
		s->elem=p->next;
		sym=p->symbol;
		free(p);
		s->top--;
	}
	return sym;
}
void initstrack(strack *s)
{
	s->top =0;
	s->elem =NULL;
}
int emptystrack(strack *s)
{
	int out;
	if(s==NULL)
	out=1;
	else
	out=(s->elem ==NULL)?0:1;
	return out;
 } 

int priorityleft(char s)
{
	int out;
	switch(s)
	{
		case'+':
			out=2;
			break;
		case'-':
			out=2;
			break;
		case'*':
			out=4;
			break;
		case'/':
			out=4;
			break;
		case'(':
			out=0;
			break;
		case')':
			out=5;
			break;	
	}
	return out;
}
int priorityright(char s)
{
	int out=-1;
	switch(s)
	{
		case'+':
			out=1;
			break;
		case'-':
			out=1;
			break;
		case'*':
			out=3;
			break;
		case'/':
			out=3;
			break;
		case'(':
			out=5;
			break;
		case')':
			out=0;
			break;
	}
	return out;
}

