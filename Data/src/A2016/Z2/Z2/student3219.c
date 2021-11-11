#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n,i,j,p=0;
	printf("Unesite broj uglova: ");
	do
	{
		scanf("%d",&n);
		if(n<=0 || n>500)
		{
			printf("Pogresan unos");
		}
	}
	while(n<=0 || n>500);
	
	double niz[500];
	double unos=0;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&unos);
		niz[i] = unos;
	}
	double ukupno=0;
	int stepeni=0,minute=0,sekunde=0;
	int step[500];
	int min[500];
	int sek[500];
	for(i=0;i<n;i++)
	{
		ukupno=(niz[i]*180/PI)*3600;
		if (ukupno < 0)
			ukupno = (int)(ukupno - 0.5);
		else
			ukupno = (int)(ukupno + 0.5);
		stepeni=ukupno/3600;
		minute=(ukupno-stepeni*3600)/60;
		sekunde=fabs(ukupno-stepeni*3600-minute*60);
		minute = fabs(minute);
		if(sekunde>=60)
		{
			minute++;
			sekunde=sekunde-60;
		
			if(minute>=60)
			{
			    minute=minute-60;
			    if (stepeni < 0) 
			    	stepeni--;
			    else 
			    	stepeni++;
			}
		}
		if(sekunde>30)
		{
			for(j=i;j<n-1;j++)
			{
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
		if(sekunde<=30)
		{
			step[p]=stepeni;
			min[p]=minute;
			sek[p++]=sekunde;
		}
	}
	printf("Uglovi su: ");
	printf("\n");
	for(i=0;i<p;i++)
	{
		printf("%d stepeni %d minuta %d sekundi",step[i],min[i],sek[i]);
		printf("\n");
	}
	
	return 0;
}
