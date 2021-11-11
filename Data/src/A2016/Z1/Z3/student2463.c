#include <stdio.h>

int main() {
	int Brc=0, Brb=0, Brs=0, Brv=0, Brp=0;
	char Auto;
	float PC, PB, PS, PV, PP, Ukupno;
	
	printf("Unesite vozila: ");

	do{
		scanf("%c", &Auto);
	if(Auto=='c' || Auto=='C') 
	Brc++;
	else if (Auto=='b' || Auto=='B') 
	Brb++;
	else if (Auto=='s' || Auto=='S') 
	Brs++;
	else if (Auto=='v' || Auto=='V') 
	Brv++;
	else if (Auto=='p' || Auto=='P') 
	Brp++;
	else if(Auto=='K'|| Auto=='k')
	  break;
	else
		printf("Neispravan unos\n"); }
	while(Auto!='K' && Auto!='k');

    Ukupno= Brc+Brb+Brs+Brv+Brp;
	printf("Ukupno evidentirano %g vozila.\n", Ukupno);
	
	if(Ukupno==0) 
		printf("Najpopularnija boja je crna (0.00%%).");
	else if(Brc>=Brb && Brc>=Brs && Brc>=Brv && Brc>=Brp)
	{
		PC=Brc*100/Ukupno;
		printf("Najpopularnija boja je crna (%.2f%%).", PC);
	}
    else if(Brb>=Brc && Brb>=Brs && Brb>=Brv && Brb>=Brp)
	{
		PB=Brb*100/Ukupno;
		printf("Najpopularnija boja je bijela (%.2f%%).", PB);
	}
	 else if(Brs>=Brc && Brs>=Brb && Brs>=Brv && Brs>=Brp)
	{
	 	PS=Brs*100/Ukupno;
		printf("Najpopularnija boja je siva (%.2f%%).", PS);
	}
	else if(Brv>=Brc && Brv>=Brb && Brv>=Brs && Brv>=Brp)
	{
		PV=Brv*100/Ukupno;	
		printf("Najpopularnija boja je crvena (%.2f%%).", PV);
	}
	else if(Brp>=Brc && Brp>=Brb && Brp>=Brs && Brp>=Brv)
	{
		PP=Brp*100/Ukupno;
		printf("Najpopularnija boja je plava (%.2f%%).", PP);
	}
	return 0;
}
