#include <stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.1415926

int main() {
	double nizUglova[500],stepeni=0,minute=0,sekunde=0;
	int brojclanova,i,j;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&brojclanova);
	for(i=0;i<brojclanova;i++)
	{
		scanf("%lf",&nizUglova[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<brojclanova;i++)
	{
		stepeni=nizUglova[i]*180/PI;
		minute=fabs((stepeni-(int)stepeni)*60);
		sekunde=fabs(60*(minute-(int)minute))+0.5;
		if((int)sekunde==60){ minute++; sekunde=0; }
		if((int)minute==60)
		  {
			if(stepeni<0) stepeni--;
			else stepeni++;
			 minute=0; 
		  }
		  if((int)sekunde>30)
		  {
		  	for(j=i;j<brojclanova;j++)
		  		nizUglova[j]=nizUglova[j+1];
		  	  i--;
		  	  brojclanova--;
		  	  
		  }
		 else
		 printf("%d stepeni %d minuta %d sekundi\n",(int)stepeni,(int)minute,(int)sekunde);
		
		
	}
	return 0;
}
