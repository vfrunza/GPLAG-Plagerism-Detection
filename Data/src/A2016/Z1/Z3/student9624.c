#include <stdio.h>

int main() {
	char znak;
	int cznak=0,pznak=0,bznak=0,sznak=0,vznak=0,uk=1;
float p=0;
	printf("Unesite vozila: ");
	
	while(1)
	{
			
scanf("%c",&znak);	
 if(znak=='k' || znak=='K' )
break;
else if(znak=='c' || znak=='C' )
cznak++;
 else if(znak=='p' || znak=='P' )
pznak++;

else if(znak=='b' || znak=='B' )
bznak++;

else if(znak=='s' || znak=='S' )
sznak++;

else if(znak=='v' || znak=='V' )
vznak++;
else 
printf("Neispravan unos\n");

		 
	}
uk=cznak+pznak+bznak+sznak+vznak;


printf("Ukupno evidentirano %d vozila.",uk);
if(uk==0)
printf("\nNajpopularnija boja je crna (%.2f%%).",p );
else if(sznak>=pznak && sznak>bznak  && sznak>cznak  && sznak>=vznak )
{ p=(double)sznak/uk*100;
printf("\nNajpopularnija boja je siva (%.2f%%).",p );}
else if(cznak>=pznak && cznak>=bznak  && cznak>=sznak  && cznak>=vznak )
{p=(double)cznak/uk*100;
printf("\nNajpopularnija boja je crna (%.2f%%).",p );}
else if(bznak>=pznak && bznak>=sznak  && bznak>cznak  && bznak>=vznak )
{ p=(double)bznak/uk*100;
printf("\nNajpopularnija boja je bijela (%.2f%%).",p );}
else if(vznak>=pznak && vznak>sznak  && vznak>cznak  && vznak>bznak )
{ p=(double)vznak/uk*100;
printf("\nNajpopularnija boja je crvena (%.2f%%).",p );}
else if(pznak>vznak && pznak>sznak  && pznak>cznak  && pznak>bznak )
{ p=(double)pznak/uk*100;
printf("\nNajpopularnija boja je plava (%.2f%%).",p );}

	return 0;
}
