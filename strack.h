#ifndef _STRACK_H_
#define _STRACK_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	char symbol;
	struct _Node *next;
} node;
typedef struct _Strack
{
	int top;
	node *elem;
} strack;
void push(strack *s,int num);
void pushsym(strack *s,char sym);
int popnum(strack *s);
char popsym(strack *s);
void initstrack(strack *s);
int priorityleft(char s);
int priorityright(char s);
void freestrack(node *s);
int power(int base,int index);

#endif
