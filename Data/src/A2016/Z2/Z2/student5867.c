#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() 
{
	int vel, i, minute, sekunde, stepeni, k;
	float niz[500], razlika, razlika2, broj1;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &vel);
	
	for(i=0; i<vel; i++)
	scanf("%f", &niz[i]);
	printf("Uglovi su: ");
	
	for(i=0; i<vel; i++)
	{
		niz[i]*=180.0/PI;
		stepeni=niz[i];
		if(stepeni<0)
		{
		razlika=niz[i]*-1-stepeni*-1;
		}
		else
		razlika=niz[i]-stepeni;
		broj1=razlika*60;
		minute=(int)(razlika*60)%60;
		if(stepeni==0 && minute<0)
		minute=minute;
		razlika2=broj1-minute;
		sekunde=round(razlika2*60);
		if(sekunde==60)
		{
		sekunde=0;
		minute+=1;
		}
		if(minute==60 && stepeni>0)
		{
		minute=0;
		stepeni+=1;
		}
		else if(minute==60 && stepeni<0)
		{
		minute=0;
		stepeni-=1;
		}
		if(sekunde<0)
		sekunde=sekunde*-1;
		if(sekunde>30)
		{
		for(k=i; k<vel-1; k++)
		niz[k]=niz[k+1];
		vel--;
		i--;
		}
		
		else
		printf("\n%d stepeni %d minuta %d sekundi", stepeni, minute, sekunde);
		
		}
		
		
	return 0;
}
