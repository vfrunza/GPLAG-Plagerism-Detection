#include <stdio.h>
#define P1 6.8
#define H1 3.3
#define C1 5.0

#define P2 8.0
#define H2 3.0
#define C2 3.9

#define P3 5.3
#define H3 5.0
#define C3 6.0

int main() {
	float cevapi1=0, cevapi2=0, cevapi3=0, hamburger1=0, hamburger2=0, hamburger3=0,pizza1=0,pizza2=0,pizza3=0;
	float suma1=0, suma2=0, suma3=0,popust=0;
	
	char tarik,mirza,bojan,novi_red;
    
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	
	if(tarik=='P')
	{
		pizza1=pizza1+P1;
		pizza2=pizza2+P2;
		pizza3=pizza3+P3;
	}
	if(bojan=='P')
	{
		pizza1=pizza1+P1;
		pizza2=pizza2+P2;
		pizza3=pizza3+P3;
	}
	if(mirza=='P')
	{
		pizza1=pizza1+P1;
		pizza2=pizza2+P2;
		pizza3=pizza3+P3;
	}
	
	
	
	
	if(tarik=='H')
	
	{
		hamburger1=hamburger1+H1;
		hamburger2=hamburger2+H2;
		hamburger3=hamburger3+H3;
	}
	
		if(bojan=='H')
	
	{
		hamburger1=hamburger1+H1;
		hamburger2=hamburger2+H2;
		hamburger3=hamburger3+H3;
	}
		if(mirza=='H')
	
	{
		hamburger1=hamburger1+H1;
		hamburger2=hamburger2+H2;
		hamburger3=hamburger3+H3;
	}
	
		
		if(tarik=='C')
		{
			cevapi1=cevapi1+C1;
			cevapi2=cevapi2+C2;
			cevapi3=cevapi3+C3;
		}
		if(bojan=='C')
		{
			cevapi1=cevapi1+C1;
			cevapi2=cevapi2+C2;
			cevapi3=cevapi3+C3;
		}
		
		if(mirza=='C')
		{
			cevapi1=cevapi1+C1;
			cevapi2=cevapi2+C2;
			cevapi3=cevapi3+C3;
		}

	
	 
		
	suma1=pizza1+hamburger1+cevapi1;
	suma2=pizza2+hamburger2+cevapi2;
	suma3=pizza3+hamburger3+cevapi3;
	
	if((suma1 < suma2)&&(suma1 < suma3))
	{ 
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma1);
		return 0;
	}
	if((suma2<suma1)&&(suma2<suma3))
		{ 
				printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma2);
		}




	if((suma3<suma1)&&(suma3 < suma2))
		{ 
				printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma3);
		}



if((tarik=='P')&&(bojan=='P')&&(mirza=='P'))
{
	popust=pizza1*0.9;
	
	if((popust<suma3)&&(popust<suma2))
{
	printf("\nSa popustom bi Restoran bio (%.2f KM).\n", popust);

}
}

if((tarik=='H')&&(bojan=='H')&&(mirza=='H'))
{
	popust=hamburger1*0.9;
	
	if((popust<suma3)&&(popust<suma2))
{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n" ,popust);

}
}

if((tarik=='C')&&(bojan=='C')&&(mirza=='C'))
{
	popust=cevapi1*0.9;
	
	if((popust<suma2)&&(popust<suma3))
{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n" ,popust);

}
}



if((tarik=='P')||(bojan=='P')||(mirza=='P'))
{
	popust=pizza1*0.9;
	popust=popust+hamburger1+cevapi1;
	if((popust<suma2)&&(popust<suma3))
	{
	printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).\n",popust);

}
}
return 0;
}