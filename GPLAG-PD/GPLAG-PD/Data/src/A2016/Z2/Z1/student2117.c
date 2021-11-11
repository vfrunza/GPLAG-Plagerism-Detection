#include <stdio.h>

#include <math.h>
int main() 
{
	int m,n,razlika,broj,x,kraj,k,j;
	printf("Unesite broj: ");
	scanf("%d",&m);
	broj=0;
	x=0;
	j=0;
	j=m;
	if((m>0 && m<10) || (m>-10 && m<0))
	{
		printf("%d",broj);
	}
	else if(m==0)
	printf("%d",broj);
	
	
	
	else
	{
		m=fabs(m);
		for(k=0;j!=0;k++)
		{
			n=j%10;
			j=j/10;
			if(n==0)
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
				n=m%10;
				razlika=(m/10)%10;
				razlika=fabs(n-razlika);
				broj=razlika*pow(10,x)+broj;
				m=m/10;
				x++;
				if(m<10)
					break;

			}while(m>0);
		}
		
		else
		{
		
			do
			{
				n=(m%10);
				razlika=(m/10)%10;
				if(razlika==0)
					break;
				else
				{
					razlika=fabs(n-razlika);
					broj=razlika*pow(10,x)+broj;
					m=m/10;
					x++;
				}
			}while(m>0);
		}
	printf("%d",broj);
	}

	return 0;
}
