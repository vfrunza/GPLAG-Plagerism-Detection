#include <stdio.h>
#include <math.h>
#define PI 3.1415926


int main() {
	double niz[500];
	double temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0;
	int dimenzija,stepeni, minute, sekunde,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&dimenzija);
	for(i=0;i<dimenzija;i++)
	{
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<dimenzija;i++)
	{
		temp1=niz[i]*(180/PI);
		stepeni=temp1;
		temp2=temp1-stepeni;
		temp3=temp2*60;
		minute=temp3;
		if(minute<0) minute=-minute;
		temp4=temp3-minute;
		temp5=temp4*60;
		sekunde=temp5;
		if(sekunde<0) sekunde=-sekunde;
		temp6=temp5-sekunde;
			
		if(temp6>=0.5)
		{
			sekunde=temp5+1;
		}
	
		
	if(sekunde==60)
		{
			sekunde=0;
			minute++;
		}
	if(minute==60)
	{
		stepeni++;
		minute=0;
	}

		
		if(sekunde>30)
		{
			for(j=i;j<dimenzija-1;j++)
				{	
					niz[j]=niz[j+1];
				
				
				}
				i--; dimenzija--;
		}
		

	}
	for(i=0; i<dimenzija; i++)
	{
		temp1=niz[i]*(180/PI);
		stepeni=temp1;
		temp2=temp1-stepeni;
		temp3=temp2*60;
		minute=temp3;
		temp4=temp3-minute;
		temp5=temp4*60;
		sekunde=temp5;
		temp6=temp5-sekunde;
			
		if(temp6>=0.5)
		{
			sekunde=temp5+1;
		}
		printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
	
	}

	return 0;
}
