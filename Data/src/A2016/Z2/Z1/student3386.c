#include <stdio.h>
#include <math.h>
int main() 
{
	int n,c,razlika,broj,x,kraj,i,t;
	printf("Unesite broj: ");
	scanf("%d",&n);
	broj=0;
	x=0;
	t=0;
	t=n;
	if((n>0 && n<10) || (n>-10 && n<0))
	{
		printf("%d",broj);
	}
	else if(n==0)
	printf("%d",broj);
	
	
	
	else
	{
		n=fabs(n);
		for(i=0;t!=0;i++)
		{
			c=t%10;
			t=t/10;
			if(c==0)
			{
				kraj=2;
				break;
			}
			else
				kraj=3;
			
		}
		
		if (kraj==2)
		{
			do
			{
				c=n%10;
				razlika=(n/10)%10;
				razlika=fabs(c-razlika);
				broj=razlika*pow(10,x)+broj;
				n=n/10;
				x++;
				if(n<10)
					break;

			}while(n>0);
		}
		
		else
		{
		
			do
			{
				c=(n%10);
				razlika=(n/10)%10;
				if(razlika==0)
					break;
				else
				{
					razlika=fabs(c-razlika);
					broj=razlika*pow(10,x)+broj;
					n=n/10;
					x++;
				}
			}while(n>0);
		}
	printf("%d",broj);
	}
	
	return 0;
}