#include <stdio.h>

#define Pr 6.80 /*Pr-Cijena Pizze u Restoranu*/
#define Pf 8.00 /*Pf-Cijena Pizze u Fast-food-u*/
#define Pb 5.30 /*Pb-Cijena Pizze u Bistru*/

#define Hr 3.30 /*Hr-Cijena Hamburgera u Restoranu*/
#define Hf 3.00 /*Hf-Cijena Hamburgera u Fast-food-u*/
#define Hb 5.00 /*Hb-Cijena Hamburgera u Bistru*/

#define Cr 5.00 /*Cr-Cijena Cevapa u Restoranu*/
#define Cf 3.90 /*Cf-Cijena Cevapa u Fast-food-u*/
#define Cb 6.00 /*Cb-Cijena Cevapa u Bistru*/ 

int main() {
	
	char Tarik;
	char Bojan;
	char Mirza;
	char novi_red;
	double suma1, suma2, suma3, popust;

		printf("Unesite jelo za Tarika: ");
		scanf("%c", &Tarik);
		scanf("%c", &novi_red );
		
		printf("Unesite jelo za Bojana: ");
		scanf("%c", &Bojan);
		scanf("%c", &novi_red );
		
		printf("Unesite jelo za Mirzu: ");
		scanf("%c", &Mirza);
		scanf("%c", &novi_red );
		
if(Tarik == 'P' && Bojan == 'P' && Mirza =='P')
{
	suma1 = 3* Pr;
	suma2= 3* Pf;
	suma3= 3* Pb;
	popust = (Pr + Pf + Pb) - Pr/10;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}
else if(Tarik == 'H' && Bojan == 'H' && Mirza =='H')
{
	suma1 = 3* Hr;
	suma2= 3* Hf;
	suma3= 3* Hb;
	popust = (Hr + Hr + Hr) - 3*Hr/10;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'C' && Mirza =='C')
{
	suma1 = 3* Cr;
	suma2= 3* Cf;
	suma3= 3* Cb;
	popust = (Cr + Cf + Cb) - Cr/10;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'P' && Bojan == 'H' && Mirza =='H')
{
	suma1 = Hr + 2*Pr;
	suma2= Hf + 2*Pf;
	suma3= Hb + 2*Pb;
	popust = 2*Pr + Hr - Hr/10;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}
else if(Tarik == 'H' && Bojan == 'P' && Mirza =='H')
{
	suma1 = Pr + 2*Hr;
	suma2= Pf + 2*Hf;
	suma3= Pb + 2*Hb;
    popust = (2*Hr + Pr) - Pr/10;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1);
}
else if(Tarik == 'H' && Bojan == 'H' && Mirza =='P')
{
	suma1 = Pr + 2*Hr;
	suma2= Pf + 2*Hf;
	suma3= Pb + 2*Hb;
    popust = (2*Hr + Pr) - Pr/10;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1);
}
else if(Tarik == 'P' && Bojan == 'H' && Mirza =='C')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'P' && Mirza =='H')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'P' && Bojan == 'C' && Mirza =='H')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'H' && Bojan == 'C' && Mirza =='P')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
}
else if(Tarik == 'H' && Bojan == 'P' && Mirza =='C')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'H' && Mirza =='P')
{
	suma1= Pr + Hr + Cr;
	suma2= Pf + Hf + Cf;
	suma3= Pb + Hb + Cb;
	popust = (Pr + Hr + Cr) - Pr/10;
	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'P' && Mirza =='P')
{
	suma1 = Cr + 2*Pr;
	suma2= Cf + 2*Pf;
	suma3= Cb + 2*Pb;
	popust= (Cr + Pr + Pr) - Pr/10; 
	printf("\nNajjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	
}
else if(Tarik == 'P' && Bojan == 'C' && Mirza =='P')
{
	suma1 = Cr + 2*Pr;
	suma2= Cf + 2*Pf;
	suma3= Cb + 2*Pb;
	popust= (Cr + Pr + Pr) - Pr/10;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}	
	else if(Tarik == 'P' && Bojan == 'P' && Mirza =='C')
{
	suma1 = Cr + 2*Pr;
	suma2= Cf + 2*Pf;
	suma3= Cb + 2*Pb;
	popust= (Cr + Pr + Pr) - Pr/10;
	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}
else if(Tarik == 'H' && Bojan == 'P' && Mirza =='P')
{
	suma1 = Hr + 2*Pr;
	suma2= Hf + 2*Pf;
	suma3= Hb + 2*Pb;
    popust = (2*Pr + Hr) - 2*Pr/10;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}
else if(Tarik == 'P' && Bojan == 'H' && Mirza =='P')
{	
	suma1 = Hr + 2*Pr;
	suma2= Hf + 2*Pf;
	suma3= Hb + 2*Pb;
    popust = (2*Pr + Hr) - Pr/10;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
	
}
else if(Tarik == 'P' && Bojan == 'P' && Mirza =='H')
{	
	suma1 = Hr + 2*Pr;
	suma2= Hf + 2*Pf;
	suma3= Hb + 2*Pb;
    popust = (2*Pr + Hr) - Pr/10;
    	printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
}
else if(Tarik == 'H' && Bojan == 'C' && Mirza =='C')
{	
	suma1 = Hr + 2*Cr;
	suma2= Hf + 2*Cf;
	suma3= Hb + 2*Cb;
    popust = (2*Cr + Hr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'H' && Mirza =='C')
{	
	suma1 = Hr + 2*Cr;
	suma2= Hf + 2*Cf;
	suma3= Hb + 2*Cb;
    popust = (2*Cr + Hr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'C' && Mirza =='H')
{	
	suma1 = Hr + 2*Cr;
	suma2= Hf + 2*Cf;
	suma3= Hb + 2*Cb;
    popust = (2*Cr + Hr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'P' && Bojan == 'C' && Mirza =='C')
{	
	suma1 = Pr + 2*Cr;
	suma2= Pf + 2*Cf;
	suma3= Pb + 2*Cb;
    popust = (2*Cr + Pr) - Pr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'P' && Mirza =='C')
{	
	suma1 = Pr + 2*Cr;
	suma2= Pf + 2*Cf;
	suma3= Pb + 2*Cb;
    popust = (2*Cr + Pr) - Pr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'C' && Mirza =='P')
{	
	suma1 = Pr + 2*Cr;
	suma2= Pf + 2*Cf;
	suma3= Pb + 2*Cb;
    popust = (2*Cr + Pr) - Pr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'C' && Bojan == 'H' && Mirza =='H')
{	
	suma1 = Cr + 2*Hr;
	suma2= Cf + 2*Hf;
	suma3= Cb + 2*Hb;
    popust = (2*Hr + Cr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'H' && Bojan == 'C' && Mirza =='H')
{	
	suma1 = Cr + 2*Hr;
	suma2= Cf + 2*Hf;
	suma3= Cb + 2*Hb;
    popust = (2*Hr + Cr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}
else if(Tarik == 'H' && Bojan == 'H' && Mirza =='C')
{	
	suma1 = Cr + 2*Hr;
	suma2= Cf + 2*Hf;
	suma3= Cb + 2*Hb;
    popust = (2*Hr + Cr) - Cr/10;
    	printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
}

if(suma2< suma1 && suma2< suma3) 
{
	if(popust<suma2)
	{
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
}

if(suma3< suma1 && suma3< suma2) 
{
	if(popust<suma3)
	{
		printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
}
	return 0;

}
