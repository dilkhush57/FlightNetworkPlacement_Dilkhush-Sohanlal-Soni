/*Fare Matrix Program 1: Push Pop */

#include<stdio.h>
#include<conio.h>
#include<string.h>

int stack[10];
int stop=-1;

int push(int n)
{
	if(stop>9)
	return 0;
	else
	{
		stop++;
		stack[stop]=n;
	}
	return 1;

}

int pop()
{

	if(stop==-1)
	{
		return -1;
	}
	else
	{
		
		return(stack[stop--]);
	}
}

void main()
{
	int ch;
	clrscr();
	while(ch!=3)
	{
		printf("\nEnter Your Choice: \n 1. For PUSH \n 2. For Pattern check \n 3. for Exit from the Window");
		scanf("%d",&ch);
		if(ch==1)
		{
			int n=0,s=0;
			int f=1;
			while(n!= -1 && f)
			{
				printf("Enter the no to Push\t for exit -1 ");
				scanf("%d",&n);
				if(stop== -1)
				{
					push(n);
					s=n;
				}
				else
				{
					if( n == s+1 )
					{
						s=n;
						push(n);
					}
					else
					{
						printf("Invalid PUSH %d ",n);
						break;
					}
				}

			}
		}
		else if(ch==2)
		{
			int i=0,temp=0,j=0,len;
			char s[20];
			printf("\n Enter the Pattern");
			scanf("%s",s);
			len=strlen(s);
			while(i<len)
			{
				if(i==0)
				{
					for(j=0;j<= s[0]-'0' ;j++)
					{
						push(j);
					}
					temp=pop();
					printf("\%d",temp);
					temp=pop();
					i++;
				}
				else
				{
					if(temp == s[i]-'0')
					{
						printf("\n%d",temp);
						temp=pop();
						i++;
					}
					else if(temp < s[i]-'0')
					{
						
						int c=0,k;
						while(j<= s[i]-'0')
						{
							push(j);
							j++;
							c++;
						}
						for(k=0;k<c;k++)
						{
						if(temp!=-1)
						{printf("\n%d",temp);}
						temp=pop(); }
						i++;
					}
					else
					{	break; }
				}

			}
			if(temp==-1)
			{
				printf("\nValid Pattern");
			}
			else
			{
				printf("\n Invalid Pattern %d",temp);

			}
		}
		else if(ch==3)
		{
			printf("\nBye");
		}
		else
			printf("Enter Valid choice");
	}
	getch();
}

