#include <stdio.h>

int main()
{
    char autom;
    int max=0;
    float procenat;
    int brojac_ukupno_auta=0;
    int brojac_crnih=0,brojac_bijelih=0, brojac_sivih=0, brojac_crvenih=0, brojac_plavih=0;
    char max_znak=0;
    
    printf("Unesite vozila: ");
    /*beskonacna petlja koju prekidam sa break; */
    while (100000000==100000000)
	{
	
    scanf("%c", &autom);
    if (autom=='C' || autom=='c')
    { 
       brojac_crnih++;
    if (brojac_crnih>max) {max=brojac_crnih; 
    max_znak='C';}
	}
	else if (autom=='B' || autom=='b')
	{
	   brojac_bijelih++;
	   if (brojac_bijelih>max) {max=brojac_bijelih; 
	   max_znak='B';}
	}
	else if (autom=='S' || autom=='s')
	{
	    brojac_sivih++;
	    if (brojac_sivih>max){ max=brojac_sivih; 
	    max_znak='S';}
	}
	else if (autom=='V' || autom=='v')
	{
	    brojac_crvenih++;
	    if (brojac_crvenih>max) {max=brojac_crvenih; 
	    max_znak='V';}
	}
	else if (autom=='P' || autom=='p') 
	{
	    brojac_plavih++;
	    if (brojac_plavih>max){ max=brojac_plavih;
	    
	    max_znak='P';}
	}
	else if (autom=='K' || autom=='k')
	{
	    break;
	}
	else 
	{
	    printf("Neispravan unos\n");
	}
}
/*brojac za ukupan broj auta*/
brojac_ukupno_auta=brojac_crnih+brojac_bijelih+brojac_sivih+brojac_crvenih+brojac_plavih;
printf ("Ukupno evidentirano %d vozila.\n", brojac_ukupno_auta);

if (brojac_ukupno_auta==0) { printf("Najpopularnija boja je crna (0.00%)."); 

return 0; }

else {  
if (max_znak=='C') 
{ 
	procenat=(max*100.)/brojac_ukupno_auta;
	printf("Najpopularnija boja je crna (%.2f%). ", procenat);  return 0;}
if (max_znak=='B')
{
   procenat=(max*100.)/brojac_ukupno_auta;
   printf("Najpopularnija boja je bijela (%.2f%).", procenat);  return 0;}
if (max_znak=='P') 
{
	procenat=(max*100.)/brojac_ukupno_auta;
	printf("Najpopularnija boja je plava (%.2f%).", procenat); return 0;}
if (max_znak=='V') 
{
	procenat=(max*100.)/brojac_ukupno_auta; 
	printf("Najpopularnija boja je crvena (%.2f%).", procenat); return 0;}
if (max_znak=='S') 
{
	procenat=(max*100.)/brojac_ukupno_auta; 
	printf("Najpopularnija boja je siva (%.2f%).", procenat); return 0; } 
	
}

return 0;
}

