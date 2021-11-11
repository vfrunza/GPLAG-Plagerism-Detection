#include <stdio.h>

#define PI 3.1415926

int main() {
	int n=0, i, j, stepen=0, minuta=0, sekunde=0;
	double rad, a=0, sekunda=0, sekunda1=0, c=0;
	rad=(double)180/PI;
	double niz[500];
	do
	{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
		
	} while(n<1 || n>500);
	
	for(i=0; i<n; i++)
{
	scanf("%lf", &niz[i]);
	niz[i]=niz[i]*rad;

}
printf("Uglovi su: \n");
for(i=0; i<n; i++)
{
	if(niz[i]>=0)
	{
	a=niz[i];
	stepen=(int)a;
	c=(a-stepen)*60;
	minuta=(int)c;
	sekunda=(c-minuta)*60;
	sekunda1=(sekunda-(int)sekunda)*10;
		if(sekunda1>=5)
		{
		sekunde=(int)sekunda+1;
		}
		
		else
		{ 
			sekunde=(int)sekunda;
		}
		
		if(sekunde==60)
		{
			sekunde=0;
			minuta++;
			if (minuta==60)
			{
				minuta=0;
				stepen++;
			}
		}
			
		
		if(sekunde>30)
		{
			for(j=i; j<n-1; j++)
			{
			niz[j]=niz[j+1];
			
			}
		n--;
		i--;
		continue;
		}
	
		printf("%d stepeni %d minuta %d sekundi \n", stepen, minuta, sekunde);
	}
	
		if(niz[i]<0)
	{
	a=niz[i];
	stepen=(int)a;
	c=(a-stepen)*(-1)*60;
	minuta=(int)c;
	sekunda=(c-minuta)*60;
	sekunda1=(sekunda-(int)sekunda)*10;
		if(sekunda1>=5)
		{
		sekunde=(int)sekunda+1;
		}
		
		else
		{ 
			sekunde=(int)sekunda;
		}
		
		if(sekunde==60)
		{
			sekunde=0;
			minuta++;
			if (minuta==60)
			{
				minuta=0;
				stepen--;
			}
		}
			
		
		if(sekunde>30)
		{
			for(j=i; j<n-1; j++)
			{
			niz[j]=niz[j+1];
			
			}
		n--;
		i--;
		continue;
		}
	
		printf("%d stepeni %d minuta %d sekundi\n", stepen, minuta, sekunde);
	}
	

}


	return 0;
}
