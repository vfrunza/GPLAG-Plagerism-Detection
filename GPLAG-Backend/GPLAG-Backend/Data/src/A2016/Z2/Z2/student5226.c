#include <stdio.h>

int main() {
	int broj_uglova,i,pravi_stepen,prave_minute,prave_sekunde;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_uglova);
	float uglovi[500],PI,stepeni,minute,ostatak1,ostatak2,sekunde;
	PI=3.1415926;
	if(broj_uglova<500)
	{
	  for(i=0;i<broj_uglova;i++)
	   {
		scanf("%f",&uglovi[i]);
	    }
	  printf("Uglovi su: \n");
	  for(i=0;i<broj_uglova;i++)
	  {
		stepeni=uglovi[i]*180/PI;
		ostatak1=stepeni-(int)stepeni;
		pravi_stepen=stepeni-ostatak1;
		minute=ostatak1*60;
		if(minute<0) minute=minute*(-1);
		ostatak2=minute-(int)minute;
		minute=minute+0.5;
		prave_minute=minute-ostatak2;
		
		sekunde=ostatak2*60;
		if(sekunde<0) sekunde=sekunde*(-1);
		sekunde=sekunde+0.5;
		prave_sekunde=sekunde;
		
		if(prave_sekunde<=30)
		{printf("%d stepeni %d minuta %d sekundi\n",pravi_stepen,prave_minute,prave_sekunde);}
		
		
	  }
	
	
	}
	return 0;
}
