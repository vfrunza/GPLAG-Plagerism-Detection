#include <stdio.h>
#define Pizza1 6.80     /* Restoran "Kod konja i konjušara" */
#define Hamburger1 3.30   /* Restoran "Kod konja i konjušara" */
#define Cevapi1 5.00      /* Restoran "Kod konja i konjušara" */
#define Pizza2 8.00       /* Fast-food "Trovač" */
#define Hamburger2 3.00   /* Fast-food "Trovač" */
#define Cevapi2 3.90      /* Fast-food "Trovač" */
#define Pizza3 5.30       /* Bistro "Lorelei" */
#define Hamburger3 5.00   /* Bistro "Lorelei" */
#define Cevapi3 6.00      /* Bistro "Lorelei" */

int main() {
    
    char tarik, bojan, mirza, novi_red, H, C, P;
    double b,c;
    
    printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	if ((tarik=='H') && (bojan=='H') && (mirza=='H'))  /*1*/ 
	{
	if ( ((3*Hamburger1) < (3*Hamburger2)) && ((3*Hamburger1) < (3*Hamburger3))  )
	    {
	        b=3*Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}	
	if ( ((3*Hamburger2) < (3*Hamburger3)) && ((3*Hamburger2) < (3*Hamburger1))  )
	    {
	    	b=3*Hamburger2;
	    	c=(3*Hamburger1)-((3*Hamburger1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((3*Hamburger3) < (3*Hamburger1)) && ((3*Hamburger3) < (3*Hamburger2))  )
	    {
	    	b=3*Hamburger3;
	    	c=(3*Hamburger1)-((3*Hamburger1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
		
	}
	
	if ((tarik=='H') && (bojan=='H') && (mirza=='C'))  /*2*/
	{
	if ( ((2*Hamburger1+Cevapi1) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger1+Cevapi1) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Cevapi2) < (2*Hamburger1+Cevapi1)) && ((2*Hamburger2+Cevapi2) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger2+Cevapi2;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Hamburger3+Cevapi3) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger3+Cevapi3) < (2*Hamburger1+Cevapi1))  )
	    {
	    	b=2*Hamburger3+Cevapi3;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='H') && (bojan=='H') && (mirza=='P'))  /*3*/
		{
	if ( ((2*Hamburger1+Pizza1) < (2*Hamburger2+Pizza2)) && ((2*Hamburger1+Pizza1) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Pizza2) < (2*Hamburger1+Pizza1)) && ((2*Hamburger2+Pizza2) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger2+Pizza2;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Hamburger3+Pizza3) < (2*Hamburger2+Pizza2)) && ((2*Hamburger3+Pizza3) < (2*Hamburger1+Pizza1))  )
	    {
	    	b=2*Hamburger3+Pizza3;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
    if ((tarik=='H') && (bojan=='C') && (mirza=='H'))  /*4*/ 
	{
	if ( ((2*Hamburger1+Cevapi1) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger1+Cevapi1) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Cevapi2) < (2*Hamburger1+Cevapi1)) && ((2*Hamburger2+Cevapi2) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger2+Cevapi2;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Hamburger3+Cevapi3) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger3+Cevapi3) < (2*Hamburger1+Cevapi1))  )
	    {
	    	b=2*Hamburger3+Cevapi3;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='H') && (bojan=='C') && (mirza=='C'))  /*5*/ 
	{
	if ( ((2*Cevapi1+Hamburger1) < (2*Cevapi2+Hamburger2)) && ((2*Cevapi1+Hamburger1) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi1*Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Hamburger2) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi2+Hamburger2) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi2+Hamburger2;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	
		}
	if ( ((2*Cevapi3+Hamburger3) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi3+Hamburger3) < (2*Cevapi2+Hamburger2))  )
	    {
	    	b=2*Cevapi3+Hamburger3;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
    
    if ((tarik=='H') && (bojan=='C') && (mirza=='P'))  /*6*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Hamburger1+Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Hamburger1+Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='H') && (bojan=='P') && (mirza=='H'))  /*7*/
		{
	if ( ((2*Hamburger1+Pizza1) < (2*Hamburger2+Pizza2)) && ((2*Hamburger1+Pizza1) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Pizza2) < (2*Hamburger1+Pizza1)) && ((2*Hamburger2+Pizza2) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger2+Pizza2;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Hamburger3+Pizza3) < (2*Hamburger2+Pizza2)) && ((2*Hamburger3+Pizza3) < (2*Hamburger1+Pizza1))  )
	    {
	    	b=2*Hamburger3+Pizza3;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='H') && (bojan=='P') && (mirza=='C'))  /*8*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Hamburger1+Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Hamburger1+Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='H') && (bojan=='P') && (mirza=='P'))  /*9*/ 
    {
	if ( ((2*Pizza1+Hamburger1) < (2*Pizza2+Hamburger2)) && ((2*Pizza1+Hamburger1) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza1+Hamburger1;
    printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Hamburger2) < (2*Pizza1+Hamburger1)) && ((2*Pizza2+Hamburger2) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza2+Hamburger2;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2 KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Hamburger3) < (2*Pizza1+Hamburger1)) && ((2*Pizza3+Hamburger3) < (2*Pizza2+Hamburger2))  )
	    {
	    	b=2*Pizza3+Hamburger3;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
	
		}
	}
	
	if ((tarik=='C') && (bojan=='H') && (mirza=='H'))  /*10*/ 
	{
	if ( ((2*Hamburger1+Cevapi1) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger1+Cevapi1) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Cevapi2) < (2*Hamburger1+Cevapi1)) && ((2*Hamburger2+Cevapi2) < (2*Hamburger3+Cevapi3))  )
	    {
	    	b=2*Hamburger2+Cevapi2;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	
		}
	if ( ((2*Hamburger3+Cevapi3) < (2*Hamburger2+Cevapi2)) && ((2*Hamburger3+Cevapi3) < (2*Hamburger1+Cevapi1))  )
	    {
	    	b=2*Hamburger3+Cevapi3;
	    	c=(2*Hamburger1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
    if ((tarik=='C') && (bojan=='H') && (mirza=='C'))  /*11*/ 
	{
	if ( ((2*Cevapi1+Hamburger1) < (2*Cevapi2+Hamburger2)) && ((2*Cevapi1+Hamburger1) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi1+Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Hamburger2) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi2+Hamburger2) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi2+Hamburger2;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Cevapi3+Hamburger3) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi3+Hamburger3) < (2*Cevapi2+Hamburger2))  )
	    {
	    	b=2*Cevapi3+Hamburger3;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='H') && (mirza=='P'))  /*12*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Cevapi1+Hamburger1+Pizza1)-((Pizza1)*0.1);
	    	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", b);
	    	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
	    	
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Cevapi1+Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='C') && (mirza=='H'))  /*13*/ 
	{
	if ( ((2*Cevapi1+Hamburger1) < (2*Cevapi2+Hamburger2)) && ((2*Cevapi1+Hamburger1) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi1+Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Hamburger2) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi2+Hamburger2) < (2*Cevapi3+Hamburger3))  )
	    {
	    	b=2*Cevapi2+Hamburger2;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Cevapi3+Hamburger3) < (2*Cevapi1+Hamburger1)) && ((2*Cevapi3+Hamburger3) < (2*Cevapi2+Hamburger2))  )
	    {
	    	b=2*Cevapi3+Hamburger3;
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='C') && (mirza=='C'))  /*14*/ 
	{
	if ( ((3*Cevapi1) < (3*Cevapi2)) && ((3*Cevapi1) < (3*Cevapi3))  )
	    {
	    	b=3*Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}	
	if ( ((3*Cevapi2) < (3*Cevapi1)) && ((3*Cevapi1) < (3*Cevapi3))  )
	    {
	    	b=3*Cevapi2;
	    	c=(3*Cevapi1)-((3*Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	
		}
	if ( ((3*Cevapi3) < (3*Cevapi2)) && ((3*Cevapi3) < (3*Cevapi1))  )
	    {
	    	b=3*Cevapi3;
	    	c=(3*Cevapi1)-((3*Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='C') && (mirza=='P'))  /*15*/ 
	{
	if ( ((2*Cevapi1+Pizza1) < (2*Cevapi2+Pizza2)) && ((2*Cevapi1+Pizza1) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Pizza2) < (2*Cevapi1+Pizza1)) && ((2*Cevapi2+Pizza2) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi2+Pizza2;
	    	c=(2*Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Cevapi3+Pizza3) < (2*Cevapi1+Pizza1)) && ((2*Cevapi3+Pizza3) < (2*Cevapi2+Pizza2))  )
	    {
	    	b=2*Cevapi3+Pizza3;
	    	c=(2*Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='P') && (mirza=='H'))  /*16*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Cevapi1+Pizza1+Hamburger1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Cevapi1+Pizza1+Hamburger1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='P') && (mirza=='C'))  /*17*/ 
	{
	if ( ((2*Cevapi1+Pizza1) < (2*Cevapi2+Pizza2)) && ((2*Cevapi1+Pizza1) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Pizza2) < (2*Cevapi1+Pizza1)) && ((2*Cevapi2+Pizza2) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi2+Pizza2;
	    	c=(2*Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	
		}
	if ( ((2*Cevapi3+Pizza3) < (2*Cevapi1+Pizza1)) && ((2*Cevapi3+Pizza3) < (2*Cevapi2+Pizza2))  )
	    {
	    	b=2*Cevapi3+Pizza3;
	    	c=(2*Cevapi1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='C') && (bojan=='P') && (mirza=='P'))  /*18*/ 
	{
	if ( ((2*Pizza1+Cevapi1) < (2*Pizza2+Cevapi2)) && ((2*Pizza1+Cevapi1) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Cevapi2) < (2*Pizza1+Cevapi1)) && ((2*Pizza2+Cevapi2) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza2+Cevapi2;
	    	c=(2*Pizza1+Cevapi1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Cevapi3) < (2*Pizza1+Cevapi1)) && ((2*Pizza3+Cevapi3) < (2*Pizza2+Cevapi2))  )
	    {
	    	b=2*Pizza3+Cevapi3;
	    	c=(2*Pizza1+Cevapi1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='H') && (mirza=='H'))  /*19*/
		{
	if ( ((2*Hamburger1+Pizza1) < (2*Hamburger2+Pizza2)) && ((2*Hamburger1+Pizza1) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Hamburger2+Pizza2) < (2*Hamburger1+Pizza1)) && ((2*Hamburger2+Pizza2) < (2*Hamburger3+Pizza3))  )
	    {
	    	b=2*Hamburger2+Pizza2;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Hamburger3+Pizza3) < (2*Hamburger2+Pizza2)) && ((2*Hamburger3+Pizza3) < (2*Hamburger1+Pizza1))  )
	    {
	    	b=2*Hamburger3+Pizza3;
	    	c=(2*Hamburger1+Pizza1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='H') && (mirza=='C'))  /*20*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Pizza1+Hamburger1+Cevapi1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Pizza1+Hamburger1+Cevapi1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='H') && (mirza=='P'))  /*21*/ 
	{
	if ( ((2*Pizza1+Hamburger1) < (2*Pizza2+Hamburger2)) && ((2*Pizza1+Hamburger1) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza1+Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Hamburger2) < (2*Pizza1+Hamburger1)) && ((2*Pizza2+Hamburger2) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza2+Hamburger2;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Hamburger3) < (2*Pizza1+Hamburger1)) && ((2*Pizza3+Hamburger3) < (2*Pizza2+Hamburger2))  )
	    {
	    	b=2*Pizza3+Hamburger3;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='C') && (mirza=='H'))  /*22*/ 
    {
	if ( ((Cevapi1+Hamburger1+Pizza1) < (Cevapi2+Hamburger2+Pizza2)) && ((Cevapi1+Hamburger1+Pizza1) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi1+Hamburger1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((Cevapi2+Hamburger2+Pizza2) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi2+Hamburger2+Pizza2) < (Cevapi3+Hamburger3+Pizza3))  )
	    {
	    	b=Cevapi2+Hamburger2+Pizza2;
	    	c=(Pizza1+Cevapi1+Hamburger1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((Cevapi3+Hamburger3+Pizza3) < (Cevapi1+Hamburger1+Pizza1)) && ((Cevapi3+Hamburger3+Pizza3) < (Cevapi2+Hamburger2+Pizza2))  )
	    {
	    	b=Cevapi3+Hamburger3+Pizza3;
	    	c=(Pizza1+Cevapi1+Hamburger1)-((Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
    if ((tarik=='P') && (bojan=='C') && (mirza=='C'))  /*23*/ 
	{
	if ( ((2*Cevapi1+Pizza1) < (2*Cevapi2+Pizza2)) && ((2*Cevapi1+Pizza1) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi1+Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Cevapi2+Pizza2) < (2*Cevapi1+Pizza1)) && ((2*Cevapi2+Pizza2) < (2*Cevapi3+Pizza3))  )
	    {
	    	b=2*Cevapi2+Pizza2;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Cevapi3+Pizza3) < (2*Cevapi1+Pizza1)) && ((2*Cevapi3+Pizza3) < (2*Cevapi2+Pizza2))  )
	    {
	    	b=2*Cevapi3+Pizza3;
	    	c=(2*Cevapi1+Hamburger1)-((2*Cevapi1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='C') && (mirza=='P'))  /*24*/ 
	{
	if ( ((2*Pizza1+Cevapi1) < (2*Pizza2+Cevapi2)) && ((2*Pizza1+Cevapi1) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Cevapi2) < (2*Pizza1+Cevapi1)) && ((2*Pizza2+Cevapi2) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza2+Cevapi2;
	    	c=(2*Pizza1+Cevapi1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Cevapi3) < (2*Pizza1+Cevapi1)) && ((2*Pizza3+Cevapi3) < (2*Pizza2+Cevapi2))  )
	    {
	    	b=2*Pizza3+Cevapi3;
	    	c=(2*Pizza1+Cevapi1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='P') && (mirza=='H'))  /*25*/ 
	{
	if ( ((2*Pizza1+Hamburger1) < (2*Pizza2+Hamburger2)) && ((2*Pizza1+Hamburger1) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza1+Hamburger1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Hamburger2) < (2*Pizza1+Hamburger1)) && ((2*Pizza2+Hamburger2) < (2*Pizza3+Hamburger3))  )
	    {
	    	b=2*Pizza2+Hamburger2;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Hamburger3) < (2*Pizza1+Hamburger1)) && ((2*Pizza3+Hamburger3) < (2*Pizza2+Hamburger2))  )
	    {
	    	b=2*Pizza3+Hamburger3;
	    	c=(2*Pizza1+Hamburger1)-((2*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	}
	
	if ((tarik=='P') && (bojan=='P') && (mirza=='C'))  /*26*/ 
	{
	if ( ((2*Pizza1+Cevapi1) < (2*Pizza2+Cevapi2)) && ((2*Pizza1+Cevapi1) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza1+Cevapi1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}
	if ( ((2*Pizza2+Cevapi2) < (2*Pizza1+Cevapi1)) && ((2*Pizza2+Cevapi2) < (2*Pizza3+Cevapi3))  )
	    {
	    	b=2*Pizza2+Cevapi2;
	    	c=(2*Pizza1+Cevapi1)-((Cevapi1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((2*Pizza3+Cevapi3) < (2*Pizza1+Cevapi1)) && ((2*Pizza3+Cevapi3) < (2*Pizza2+Cevapi2))  )
	    {
	    	b=2*Pizza3+Cevapi3;
	    	c=(2*Pizza1+Cevapi1)-((Cevapi1)*0.1);
    printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
   
		}
	}
	
	if ((tarik=='P') && (bojan=='P') && (mirza=='P'))  /*27*/ 
	{
	if ( ((3*Pizza1) < (3*Pizza2)) && ((3*Pizza1) < (3*Pizza3))  )
	    {
	    	b=3*Pizza1;
	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", b);
		}	
	if ( ((3*Pizza2) < (3*Pizza1)) && ((3*Pizza2) < (3*Pizza3))  )
	    {
	    	b=3*Pizza2;
	    	c=(3*Pizza1)-((3*Pizza1)*0.1);
	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", b);
	printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", c);
		}
	if ( ((3*Pizza3) < (3*Pizza1)) && ((3*Pizza3) < (3*Pizza2))  )
	    {
	    	b=3*Pizza3;
	    	c=(3*Pizza1)-((3*Pizza1)*0.1);
	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", b);
	
		}
	}
	
	return 0;
	
	
}
	
	

	





	
		
		
	


