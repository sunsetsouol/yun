#include "strack.h"
int main()
{

	int menu=0;
	do
	{
		printf("输入1计算,输入2进行进制转换，输入-1结束\n");
		scanf("%d",&menu);
		if(menu==1)
		{
			strack s_num,s_sym;
			initstrack(&s_num);
			initstrack(&s_sym);
			char exp[200];
			printf("请输入表达式\n");
			scanf("%s",&exp);
			int tem=0;
			int num1,num2;
			int i=0;
			int minus=0;
			if(exp[0]=='-')									//判断开头是否为负数，如果是则记下来将第一个读的数转化为负数存到数据栈
			{
				i++;
				minus=-1;
			}
			while(exp[i]!=0||s_sym.top !=0)					//当表达式不为空并且符号不为空，运算继续
			{
				if(exp[i]>='0'&&exp[i]<='9')				//当下位为数字，用asc求出数字
				{
					tem+=exp[i]-'0';
					i++;
					if(exp[i]<'0'||exp[i]>'9')				//当下位不是数字，将数字存进栈，如果是数字继续
					{
						if(minus==-1)
							tem=-tem;
						pushnum(&s_num,tem);
						tem=0;
						minus=0;
					}
					else
					{
						tem*=10;
					}
				}

				else
				{
					if(exp[i]=='('&&exp[i+1]=='-')															//当“（”后直接加-表示下一个数是负数，记录并将下一位数转化为负数存入数据栈
					{
						pushsym(&s_sym,exp[i]);
						minus=-1;
						i+=2;
					}
					if(s_sym.elem ==NULL||priorityleft(s_sym.elem->symbol)<priorityright(exp[i]) )			//当符号栈不为空或右边符号优先级高于左边，将符号放到栈
					{
						pushsym(&s_sym,exp[i]);
						i++;
						continue;
					}
					if(s_sym.elem ->symbol=='('&&exp[i]==')')												//将括号中数据运算完后去掉括号
					{
						popsym(&s_sym);
						i++;
						continue; 
					}

					if((exp[i]==0&&s_sym.top!=0)||priorityleft(s_sym.elem->symbol)>priorityright(exp[i]))	//当运算未结束或左运算符优先级高于右
					{
						switch(popsym(&s_sym))
						{
							case'+':
								num1=popnum(&s_num);
								num2=popnum(&s_num);
								pushnum(&s_num,num1+num2);
								break;
							case'-':
								num1=popnum(&s_num);
								num2=popnum(&s_num);
								pushnum(&s_num,num2-num1);
								break;
							case'*':
								num1=popnum(&s_num);
								num2=popnum(&s_num);
								pushnum(&s_num,num1*num2);
								break;
							case'/':
								num1=popnum(&s_num);
								num2=popnum(&s_num);
								pushnum(&s_num,num2/num1);
								break;
							case'^':
								num1=popnum(&s_num);
								num2=popnum(&s_num);
								pushnum(&s_num,power(num2,num1));
								break; 
						}
					}

				}

			}
			printf("%d\n",s_num.elem ->data);

			freestrack(s_num.elem );
			freestrack(s_sym.elem );
		}
		if(menu==2)
		{
			int base1,base2;
			printf("请输入要将几进制的数转化为几进制的数\n");
			scanf("%d %d",&base1,&base2);
			char num[200];
			printf("请输入%d进制下的数\n",base1);
			scanf("%s",&num);
			int i=0,tem;
			strack number;
			number.top =0;
			number.elem =NULL;
			while(num[i]!=0)
			{
				if(num[i]>='0'&&num[i]<='9')
				{
					tem=num[i]-'0';
				}
				else
				{
					switch(num[i])
					{
						case'A':
							tem=10;
							break;
						case'B':
							tem=11;
							break;
						case'C':
							tem=12;
							break;
						case'D':
							tem=13;
							break;
						case'E':
							tem=14;
							break;
						case'F':
							tem=15;
							break;
					}
				}

				pushnum(&number,tem) ;
				i++;
				tem=0;
			}
			int j=number.top ;
			for(i=0; i<j ; i++)
			{
				tem+=popnum(&number)*power(base1,i );
			}
			int out=tem;
			j=0;
			while(tem!=0)
			{
				tem/=base2;
				j++;
			}
			tem=out;
			out=0;
			for(i=j; i>0; i--)
			{
				out*=10;
				out+=tem/power(base2,i-1);
				tem=tem%power(base2,i-1);
			}
			printf("%d进制下该数为%d\n",base2,out);
			freestrack(number.elem );
		}


	}
	while(menu!=-1);
	return 0;
}
