#include <stdio.h>

int main() {
float brc=0,brb=0,brs=0,brv=0,brp=0;
float pc=0.0,pb=0.0,ps=0.0,pv=0.0,pp=0.0,s=0;
char znak;
printf("Unesite vozila: ");
do {
	scanf("%c",&znak);
	if ((znak=='C') || (znak=='c')){
		brc++; 
		continue;
	}
	 if((znak=='B') || (znak=='b')){	
	 	brb++;
	 	continue;
	 }
	if((znak=='S') || (znak=='s'))
	{ 
		brs++;
		continue;
	}
	
	if((znak=='V') || (znak=='v'))
	{ 
		brv++;
		continue;
	}
	
    if((znak=='P') || (znak=='p'))
    {
    	brp++;
    	continue;
    }
	if(((znak!='P') && (znak!='p')) && ((znak!='V') && (znak!='v')) && ((znak!='S') && (znak!='s')) && ((znak!='B') && (znak!='b')) && ((znak!='C') && (znak!='c')) && ((znak!='K') && (znak!='k')))
	{
		printf("Neispravan unos\n");
	}
	}while((znak!='K') && (znak!='k'));
	s=brc+brb+brs+brv+brp;
	printf("Ukupno evidentirano %g vozila.\n" ,s);
	if(s!=0){
		pc=(brc*100)/s;
		pb=(brb*100)/s;
		ps=(brs*100)/s;
		pv=(brv*100)/s;
		pp=(brp*100)/s;
	}
		if ((brc>=brb) && (brc>=brs) && (brc>=brv) && (brc>=brp))
		{ 
			printf("Najpopularnija boja je crna (%.2f%%)." ,pc);
			return 0;
		}
		if((brb>=brc) && (brb>=brs) && (brb>=brv) && (brb>=brp))
		{
			printf("Najpopularnija boja je bijela (%.2f%%)." ,pb);
			return 0;
		}
		if((brs>=brc) && (brs>brb) && (brs>=brv) && (brs>=brp))
		{	
			printf("Najpopularnija boja je siva (%.2f%%)." ,ps);
			return 0;
		}
		if((brv>=brc) && (brv>=brb) && (brv>=brs) && (brv>=brp))
		{
			printf("Najpopularnija boja je crvena (%.2f%%)." ,pv);
			return 0;
		}
		if((brp>=brc) && (brp>=brb) && (brp>=brs) && (brp>=brv)){
			printf("Najpopularnija boja je plava (%.2f%%)." ,pp);
			return 0;
		}
	return 0;
}
