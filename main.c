#include "strack.h"
int main()
{

	int menu=0;
	do
	{
		printf("����1����,����2���н���ת��������-1����\n");
		scanf("%d",&menu);
		if(menu==1)
		{
			strack s_num,s_sym;
			initstrack(&s_num);
			initstrack(&s_sym);
			char exp[200];
			printf("��������ʽ\n");
			scanf("%s",&exp);
			int tem=0;
			int num1,num2;
			int i=0;
			int minus=0;
			if(exp[0]=='-')									//�жϿ�ͷ�Ƿ�Ϊ����������������������һ��������ת��Ϊ�����浽����ջ
			{
				i++;
				minus=-1;
			}
			while(exp[i]!=0||s_sym.top !=0)					//�����ʽ��Ϊ�ղ��ҷ��Ų�Ϊ�գ��������
			{
				if(exp[i]>='0'&&exp[i]<='9')				//����λΪ���֣���asc�������
				{
					tem+=exp[i]-'0';
					i++;
					if(exp[i]<'0'||exp[i]>'9')				//����λ�������֣������ִ��ջ����������ּ���
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
					if(exp[i]=='('&&exp[i+1]=='-')															//����������ֱ�Ӽ�-��ʾ��һ�����Ǹ�������¼������һλ��ת��Ϊ������������ջ
					{
						pushsym(&s_sym,exp[i]);
						minus=-1;
						i+=2;
					}
					if(s_sym.elem ==NULL||priorityleft(s_sym.elem->symbol)<priorityright(exp[i]) )			//������ջ��Ϊ�ջ��ұ߷������ȼ�������ߣ������ŷŵ�ջ
					{
						pushsym(&s_sym,exp[i]);
						i++;
						continue;
					}
					if(s_sym.elem ->symbol=='('&&exp[i]==')')												//�������������������ȥ������
					{
						popsym(&s_sym);
						i++;
						continue; 
					}

					if((exp[i]==0&&s_sym.top!=0)||priorityleft(s_sym.elem->symbol)>priorityright(exp[i]))	//������δ����������������ȼ�������
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
			printf("������Ҫ�������Ƶ���ת��Ϊ�����Ƶ���\n");
			scanf("%d %d",&base1,&base2);
			char num[200];
			printf("������%d�����µ���\n",base1);
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
			printf("%d�����¸���Ϊ%d\n",base2,out);
			freestrack(number.elem );
		}


	}
	while(menu!=-1);
	return 0;
}
