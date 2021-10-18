#include <stdio.h>

int main() {
	char tarik, bojan, mirza; 
	char novi_red; 
	
	printf("Unesite jelo za Tarika: "); 
    scanf("%c", &tarik); 
    scanf("%c", &novi_red);     
    printf("Unesite jelo za Bojana: "); 
    scanf("%c", &bojan); 
    scanf("%c", &novi_red);   
    printf("Unesite jelo za Mirzu: "); 
	scanf("%c", &mirza); 
    scanf("%c", &novi_red); 
    
   int porcija_cevapa=0,komada_pice=0,hamurgera=0;  
   if (tarik=='C')
   {porcija_cevapa ++;}
   else if (tarik=='P')
   {komada_pice ++ ;}
   else if (tarik=='H')
   {hamurgera ++;}                  
   
   if (bojan=='C')
   {porcija_cevapa ++;}
   else if (bojan=='P')
   {komada_pice ++ ;}
   else if (bojan=='H')
   {hamurgera ++;}
 
   if (mirza=='C')
   {porcija_cevapa ++;}
   else if (mirza=='P')
   {komada_pice ++ ;}
   else if (mirza=='H')
   {hamurgera ++;}
   
   double  Restoran,Trovac,Lorelei; 
   double restoran_postotak; 
   
   
   Restoran=komada_pice*6.80 +porcija_cevapa*5.00+hamurgera*3.30 ;
   if(komada_pice != 0) restoran_postotak = komada_pice*6.80 * 0.9 +porcija_cevapa*5.00+hamurgera*3.30 ;
   else if(porcija_cevapa != 0) restoran_postotak = komada_pice*6.80  +porcija_cevapa*5.00 * 0.9 +hamurgera*3.30 ;
   else restoran_postotak = komada_pice*6.80  +porcija_cevapa*5.00+hamurgera*3.30 *0.9 ;
   
   
   Trovac=komada_pice*8.00 +porcija_cevapa*3.90+hamurgera*3.00;
   Lorelei=komada_pice*5.30 +porcija_cevapa*6.00+hamurgera*5.00 ;
   
   if (Restoran<Trovac && Restoran<Lorelei)
   {printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",Restoran);}
   if(Trovac<Restoran && Trovac<Lorelei)
   {
       printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Trovac);
       if(restoran_postotak < Trovac) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_postotak); 
   }
   if(Lorelei<Restoran && Lorelei<Trovac)
   {printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Lorelei);
       if(restoran_postotak < Lorelei) printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran_postotak);
   }
   
   return 0;
}