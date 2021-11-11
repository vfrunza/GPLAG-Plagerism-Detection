#include <stdio.h>
#define hfft 3.00
#define pfft 8.00
#define cfft 3.90
#define hr 3.30
#define pr 6.80
#define cr 5.00
#define pbl 5.30
#define hbl 5.00
#define cbl 6.00
int main() {
	char jelom,jelot,jelob;
	double popust,racunres,racunfas,racunbis;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&jelot);
	printf("Unesite jelo za Bojana: ");
	scanf(" %c",&jelob);
	printf("Unesite jelo za Mirzu: ");
	scanf(" %c",&jelom);
	if(jelom=='H' && jelob=='H' && jelot=='H' )
	{ racunres=3*hr;
	racunfas=3*hfft;
	racunbis=3*hbl;
	popust=(3*hr/10);
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if((racunres-popust)<racunfas)	
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else if(racunbis<racunfas && racunbis<racunres){printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
if(racunres-popust<racunbis)	   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust); }   return 0 ;
	} else if(jelom=='P' && jelob=='P' && jelot=='P'){
		racunres=3*pr;
	racunfas=3*pfft;
	racunbis=3*pbl;
	popust=(pr/10);
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else if (racunbis<racunres && racunbis<racunfas){ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	    if(racunres-popust<racunbis)
	     printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}  return 0 ;
		}
		else if(jelom=='C' && jelot=='C' && jelob=='C'){
			 racunres=3*cr;
	racunfas=3*cfft;
	racunbis=3*cbl;
	popust=(cr/10);
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunres && racunfas<racunbis){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else  if (racunbis<racunres && racunbis<racunfas){ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
if(racunres-popust<racunbis)	   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}
		else if((jelom=='P' && jelob=='C' && jelot=='H') || (jelom=='P' && jelob=='H' && jelot=='C') || (jelom=='H' && jelob=='C' && jelot=='P') || (jelom=='H' && jelob=='P' && jelot=='C') || (jelom=='C' && jelob=='H' && jelot=='P'))
		{
			 racunres=hr+pr+cr;
	racunfas=cfft+pfft+hfft;
	racunbis=hbl+pbl+cbl;
	popust=(pr/10);
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else if(racunbis<racunres && racunbis<racunfas){ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}
			else if((jelom=='P' || jelom=='H') && (jelob=='P' || jelob=='H') && (jelot=='P'  || jelot=='H')){
		if((jelom=='P' && jelob=='P' && jelot=='H') || (jelom=='P' && jelob=='H' && jelot=='P') || (jelom=='H' && jelob=='P' && jelot=='P'))
	{		 racunres=hr+(2*pr);
	racunfas=(2*pfft)+hfft;
	racunbis=hbl+(2*pbl);
	popust=(2*pr/10);	
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;}
	else if((jelom=='H' && jelob=='H' && jelot=='P') || (jelom=='H' && jelob=='P' && jelot=='H') || (jelom=='P' && jelob=='H' && jelot=='H')){
	 racunres=(2*hr)+pr;
	racunfas=pfft+(2*hfft);
	racunbis=(2*hbl)+pbl;
	popust=(2*hr/10);
	if(racunres<racunfas && racunres<racunbis){
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);}
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else { printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}}
			else if((jelom=='P' || jelom=='C') && (jelob=='P' || jelob=='C') && (jelot=='P'  || jelot=='C')){
		if((jelom=='P' && jelob=='P' && jelot=='C') || (jelom=='P' && jelob=='C' && jelot=='P') || (jelom=='C' && jelob=='P' && jelot=='P')){
			 racunres=cr+(2*pr);
	racunfas=(2*pfft)+cfft;
	racunbis=cbl+(2*pbl);
	popust=(pr/10);	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else{ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;}
	else if((jelom=='C' && jelob=='C' && jelot=='P') || (jelom=='C' && jelob=='P' && jelot=='C') || (jelom=='P' && jelob=='C' && jelot=='C')) {
			{	 racunres=(2*cr)+pr;
	racunfas=pfft+(2*cfft);
	racunbis=(2*cbl)+pbl;
	popust=(pr/10);
	
	
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else{ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}}}
			else if((jelom=='C' || jelom=='H') && (jelob=='C' || jelob=='H') && (jelot=='C'  || jelot=='H')){
		if((jelom=='H' && jelob=='H' && jelot=='C') || (jelom=='H' && jelob=='C' && jelot=='H') || (jelom=='C' && jelob=='H' && jelot=='H')){
			 racunres=(2*hr)+cr;
	racunfas=(2*hfft)+cfft;
	racunbis=(2*hbl)+cbl;
	popust=(hr/10);
				if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else{ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}
	else if((jelom=='C' && jelob=='C' && jelot=='H') || (jelom=='C' && jelob=='H' && jelot=='H') || (jelom=='C' && jelob=='H' && jelot=='C')) {
			{	 racunres=hr+(2*cr);
	racunfas=(2*cfft)+hfft;
	racunbis=hbl+(2*cbl);
	popust=(cr/10);
	
	
	if(racunres<racunfas && racunres<racunbis)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",racunres);
	else if(racunfas<racunbis && racunfas<racunres){
	    printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",racunfas);
	    if(racunres-popust<racunfas)
	    printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);}
	    else{ printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",racunbis);
	if(racunres-popust<racunbis)   printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",racunres-popust);   } return 0 ;
		}
}}
	return 0;
	
}
