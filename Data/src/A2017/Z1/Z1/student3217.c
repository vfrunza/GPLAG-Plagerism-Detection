#include <stdio.h>

int main() {
	char bojan, tarik, mirza, novired;
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novired);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	
	if (tarik == 'P' && bojan == 'P' && mirza == 'P') printf ("Najjeftiniji je Bistro \"Lorelei\" (15.90 KM).");
	else if (tarik == 'H' && bojan == 'H' && mirza == 'H') 
	       {
	       	printf ("Najjeftiniji je Fast-food \"Trovac\" (9.00 KM).\n");
	       	printf ("Sa popustom bi Restoran bio jeftiniji (8.91 KM).");
	       }
	else if (tarik == 'C' && bojan == 'C' && mirza == 'C') printf ("Najjeftiniji je Fast-food \"Trovac\" (11.70 KM).");
	else if ((tarik == 'P' && bojan == 'P' && mirza =='H') || (tarik == 'P' && bojan == 'H' && mirza == 'P') || (tarik == 'H' && bojan == 'P' && mirza == 'P'))
	       {
	       	printf ("Najjeftiniji je Bistro \"Lorelei\" (15.60 KM).\n");
	       	printf ("Sa popustom bi Restoran bio jeftiniji (15.54 KM).");
	       }
	else if ((tarik == 'H' && bojan == 'H' && mirza == 'P') || (tarik == 'H' && bojan == 'P' && mirza == 'H') || (tarik == 'P' && bojan == 'H' && mirza == 'H')) 
	       {
	       	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (13.40 KM).");
	       }
	else if ((tarik == 'C' && bojan =='C' && mirza =='P') || (tarik == 'C' && bojan == 'P' && mirza == 'C') || (tarik == 'P' && bojan == 'C' && mirza == 'C'))
	       
	       	printf ("Najjeftiniji je Fast-food \"Trovac\" (15.80 KM).\n");
    else if ((tarik == 'C' && bojan == 'C' && mirza == 'H') || (tarik == 'C' && bojan == 'H' && mirza == 'C') || (tarik == 'H' && bojan =='C' && mirza == 'C'))
	       printf ("Najjeftiniji je Fast-food \"Trovac\" (10.80 KM).");
	else if ((tarik == 'H' && bojan == 'H' && mirza =='C') || (tarik == 'H' && bojan == 'C' && mirza == 'H') || (tarik == 'C' && bojan == 'H' && mirza == 'H'))
	       printf ("Najjeftiniji je Fast-food \"Trovac\" (9.90 KM).");
	else if ((tarik == 'P' && bojan == 'P' && mirza == 'C') || (tarik == 'P' && bojan == 'C' && mirza == 'P') || (tarik == 'C' && bojan == 'P' && mirza == 'P'))
	       printf ("Najjeftiniji je Bistro \"Lorelei\" (16.60 KM).");
	else 
    	{
    		printf ("Najjeftiniji je Fast-food \"Trovac\" (14.90 KM).\n");
            printf ("Sa popustom bi Restoran bio jeftiniji (14.42 KM).");  	     
	       
    	}
	return 0;
}
