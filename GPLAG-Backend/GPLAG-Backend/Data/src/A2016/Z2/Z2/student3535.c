#include <stdio.h>
#define PI 3.1415926

int main() {
	float niz[500],stepeni,minute,sekunde;
	int broj,i,c,a,b;

   do{
	printf("Unesite broj uglova: ");
	scanf("%d",&broj);
   }while(broj>500);


	for(i=0;i<broj;i++)
	{
		scanf("%f",&niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<broj;i++)
	{
	stepeni=niz[i]*(180/PI);
	if(stepeni<0)
	{
    stepeni=stepeni*(-1);
	minute=(stepeni-(int)(stepeni))*60;
	stepeni=stepeni*(-1);
	}
	else
    minute=(stepeni-(int)(stepeni))*60;
   
	sekunde=(minute-(int)(minute))*60;
	if(sekunde>=60)
	{
		minute++;
		sekunde=sekunde-60;
	}
	if(minute>=60)
	{
		stepeni++;
		minute=minute-60;
	}


	c=(int)(sekunde+0.5);

	if(c>30||c<(-30)) continue;
	printf("%d stepeni %d minuta %d sekundi\n",(int)(stepeni),(int)(minute+0.5),c);
	}
	return 0;
}
