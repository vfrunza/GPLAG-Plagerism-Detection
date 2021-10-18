#include <stdio.h>
#define c1 5.00
#define c2 3.90
#define c3 6.00
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00

int main() {
	
	char tarik, bojan, mirza, novi_red;
	
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);
    
   if (tarik == 'H' && bojan == 'H' && mirza == 'H'){
   	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (3*h2) );
   	printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (3*h1)-(3*(h1*10)/100));
   } else if (tarik == 'P' && bojan == 'P' && mirza == 'P'){
   	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", (3*p3));
   } else if (tarik == 'C' && bojan == 'C' && mirza == 'C'){
   	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (3*c2));
   } else if ((tarik == 'P' && bojan == 'H' && mirza == 'H')||(tarik == 'H' && bojan == 'P' && mirza == 'H')||(tarik == 'H'&&bojan=='H'&&mirza=='P')){
   	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", (p1+2*h1));
   } else if ((tarik == 'P' && bojan == 'P' && mirza == 'H')||(tarik == 'P' && bojan == 'H' && mirza == 'P')||(tarik == 'H'&&bojan=='P'&&mirza=='P')){
   	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", (2*p3+h3));
   	printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", ((2*p1+h1)-(2*(p1*10)/100)));
   } else if ((tarik == 'H' && bojan == 'H' && mirza == 'C')||(tarik == 'H' && bojan == 'C' && mirza == 'H')||(tarik == 'C'&&bojan=='H'&&mirza=='H')){
   	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*h2+c2));
   } else if ((tarik == 'H' && bojan == 'C' && mirza == 'C')||(tarik == 'C' && bojan == 'H' && mirza == 'C')||(tarik == 'C'&&bojan=='C'&&mirza=='H')){
    printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*c2+h2));
   } else if ((tarik == 'P' && bojan == 'P' && mirza == 'C')||(tarik == 'P' && bojan == 'C' && mirza == 'P')||(tarik == 'C'&&bojan=='P'&&mirza=='P')){
   printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", (2*p3+c3));
   } else if ((tarik == 'P' && bojan == 'C' && mirza == 'C')||(tarik == 'C' && bojan == 'P' && mirza == 'C')||(tarik == 'C'&&bojan=='C'&&mirza=='P')){
   printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (2*c2+p2));
   } else if ((tarik == 'P' && bojan == 'H' && mirza == 'C')||(tarik == 'C' && bojan == 'H' && mirza == 'P')||(tarik == 'C'&&bojan=='H'&&mirza=='P')||(tarik=='C' && bojan =='P'&&mirza=='H')){
   printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", (p2+h2+c2));	
   printf ("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", (p1+h1+c1)-(p1*10)/100);
   }
   
	return 0;
}
