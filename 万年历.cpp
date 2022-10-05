#include <stdio.h>
#include <stdlib.h>
typedef struct _Date
{
	int month;
	int day;
	int year;
} date;
int isleap (int year);
int numberofday (date t);
int Dayofweek(date g);
int main()
{
	date today;
	int menu=1 ;
	do
	{
		if(menu==1)
		{
			system("cls");
			a:
			printf("请输入日期(month day year)\n");
			scanf("%d %d %d",&today.month ,&today.day ,&today.year );
			if(today.day >numberofday(today))
			{
				printf("非法输入，%d年%d月只有%d天，请重新输入\n",today.year ,today.month ,numberofday(today));
				goto a;
			}
			if(today.month >12)
			{
				printf("非法输入，一年只有12个月，请重新输入\n");
				goto a; 
			}
			int d=numberofday(today);
			int i,cnt=0;
			for(i=1; i<Dayofweek(today); i++)
			{
				printf("\t");
				cnt++;
			}
			for(i=1; i<=d; i++)
			{
				if(i==today.day )
					printf("*");
				printf("%d\t",i );
				cnt++;
				if(cnt==7)
				{
					printf("\n");
					cnt=0;
				}

			}
			printf("\n");
		}
		if(menu==2)
		{
			b:
			int number=0;
			date g,x;
			x.year =today.year ;
			x.month =today.month ;
			int i;
			printf("输入目标日期\n");
			scanf("%d %d %d",&g.month ,&g.day ,&g.year );
			if(today.day >numberofday(today))
			{
				printf("非法输入，%d年%d月只有%d天，请重新输入\n",today.year ,today.month ,numberofday(today));
				goto b;
			}
			if(today.month >12)
			{
				printf("非法输入，一年只有12个月，请重新输入\n");
				goto b; 
			}
			if(g.year ==today.year )
			{
				if(g.month ==today.month )
				{
					number=g.day -today.day ;
				}
				else
				{
					number=numberofday(today)-today.day +g.day ;
					for(i=today.month +1; i<g.month ; i++)
					{
						x.month ++;
						number+=numberofday(x);
					}
				}
			}
			else
			{
				number=numberofday(today)-today.day +g.day ;
				x.month =today.month ;
				for(i=today.month +1; i<=12 ; i++)
				{
					x.month ++;
					number+=numberofday(x);
				}
				x.month =1;
				for(i=1; i<g.month ; i++)
				{
					number+=numberofday(x);
					x.month ++;
				}
				for(i=today.year +1; i<g.year ; i++)
				{
					if(isleap(i)==1)
						number+=366;
					else
						number+=365;
				}
			}
			printf("相距%d天\n",number);
		}

		printf("输入-1以结束，输入1继续,输入2计算与目标日期相距天数\n");
		scanf("%d",&menu);
	}
	while(menu!=-1);
	return 0;
}
int numberofday (date t)
{
	int a[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int dayspermonth;
	if(t.month ==2)
	{
		if(isleap(t.year )==1)
			dayspermonth=29;
		else
			dayspermonth=28;
	}
	else
		dayspermonth=a[t.month -1];
	return dayspermonth;
}
int isleap (int year)
{
	int isleap=0;
	if(year%400==0 || (year%4==0 &&year%100!=0))
		isleap=1;
	return isleap;
}
int Dayofweek(date g)
{
	if(g.month ==1||g.month ==2)
	{
		g.month +=12;
		g.year --;
	}
	g.day =1; 
	int week=(g.day +2*g.month +3*(g.month +1)/5+g.year +g.year /4-g.year /100+g.year /400+1)%7;
	return week;
}
