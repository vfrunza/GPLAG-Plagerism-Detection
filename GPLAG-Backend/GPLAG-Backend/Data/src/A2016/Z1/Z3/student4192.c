#include <stdio.h>

int main() {
	char boja;
	int brojac=0;
	int brojacp=0,brojacc=0,brojacv=0,brojacs=0,brojacb=0,max=0;
	float procenat;
	printf("Unesite vozila: ");
	for(;;)
	{
		scanf("%c",&boja);
		if(boja=='k'|| boja=='K') break;
		
		if(boja!='k'&&boja!='K'&&boja!='c'&&boja!='C'&&boja!='p'&&boja!='P'&&boja!='v'&&boja!='V'&&boja!='s'&&boja!='S'&&boja!='b'&&boja!='B')
		{
			
			printf("Neispravan unos\n");
			
		}
		
			
		if(boja=='c'||boja=='C') {brojacc++; brojac++;}
		if(boja=='p'||boja=='P') {brojacp++; brojac++;}
		if(boja=='v'||boja=='V') {brojacv++; brojac++;}
		if(boja=='s'||boja=='S') {brojacs++; brojac++;}
		if(boja=='b'||boja=='B') {brojacb++; brojac++;}
		if(brojacc>max) max=brojacc;
		if(brojacp>max) max=brojacp;
		if(brojacv>max) max=brojacv;
		if(brojacs>max) max=brojacs;
		if(brojacb>max) max=brojacb;
		
		
		
	}
	
	   if(max==0)
	   {
	   	printf("Ukupno evidentirano %d vozila.\n",brojac);
	   	procenat=0;
	   	printf("Najpopularnija boja je crna (%.2f%).",procenat);
	   }
	   else if(max>0 && max==brojacc)
		{printf("Ukupno evidentirano %d vozila.\n",brojac);
		procenat=((float)max/brojac)*(float)100;
		printf("Najpopularnija boja je crna (%.2f%).",procenat);
		}
		else	if(max>0 && max==brojacb)
		{printf("Ukupno evidentirano %d vozila.\n",brojac);
		procenat=((float)max/brojac)*(float)100;
		printf("Najpopularnija boja je bijela (%.2f%).",procenat);
		}
		else	if(max>0 && max==brojacs)
		{printf("Ukupno evidentirano %d vozila.\n",brojac);
		procenat=((float)max/brojac)*(float)100;
		printf("Najpopularnija boja je siva (%.2f%).",procenat);
		}
		else if(max>0 && max==brojacv)
		{printf("Ukupno evidentirano %d vozila.\n",brojac);
		procenat=((float)max/brojac)*(float)100;
		printf("Najpopularnija boja je crvena (%.2f%).",procenat);
		}
		else
		{printf("Ukupno evidentirano %d vozila.\n",brojac);
		procenat=((float)max/brojac)*(float)100;
		printf("Najpopularnija boja je plava (%.2f%).",procenat);
		}
	
		
	
		
		
	
	return 0;
}
