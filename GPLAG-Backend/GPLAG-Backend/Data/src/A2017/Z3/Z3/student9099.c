#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *nizA, int d1, int *nizB, int d2)
{
	int i,j;
	int broj, brojac=1;
	int logicki=1;
	int temp=0;
	int a;
	
	for(i=0;i<d2;i++)
	{
		for(j=0;j<d2;j++)
		{
			if(*(nizB+i)==*(nizB+j) && i!=j)
			{
				logicki=0;
				break;
			}
		}
	}
		
	for(i=0;i<d2;i++)
	{
		if(logicki!=0)
		{
			if(*(nizB+i)<0 || *(nizB+i)>9)
			{
				logicki=0;
				break;
			}
			else 
			{
				logicki=1;
			}
		} else break;
	}

	
	if(logicki!=0)
	{
		for(j=0;j<d2;j++)
		{
			a=*(nizB+j);
			
			for(i=0;i<d1;i++)
			{
				broj=fabs(*(nizA+i));
				brojac=1;
				temp=0;
				
				do
				{
					if(broj%10!=a)
					{
						temp+=((broj%10)*brojac);
						
						brojac*=10;
					}
					
					broj/=10;
				}while(broj>0);
				
				if(broj==0 && temp==0) *(nizA+i)=0;
				
				else 
				{
					if(*(nizA+i)<0) temp*=-1;
					*(nizA+i)=temp;
				}
			}
		}
	}
	
	return logicki;
}

int main() {
	
	int i;
	
	int nizA[3]={12345,6789,34567};
	int nizB[3]={1,6,7};
	
	int izbaci=izbaci_cifre(nizA,3,nizB,3);
	
	if(izbaci!=0) 
	printf("Izbacivanje je bilo uspjesno! ");
	else 
	printf("Izbacivanje nije bilo uspjesno.");
	
	for(i=0;i<5;i++)
	{
		printf("%d ", nizA[i]);
	}
	
	
	return 0;
}
