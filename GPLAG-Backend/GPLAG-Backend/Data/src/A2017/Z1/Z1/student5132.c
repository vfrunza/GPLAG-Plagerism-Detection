#include <stdio.h>

int main() {
	char tarik, bojan, mirza, novi_red;
	float p1=6.80, p2=8.00, p3=5.30, h1=3.30, h2=3.00, h3=5.00, c1=5.00, c2=3.90, c3=6.00, SRKIK, SFFT, SBL;
	float TARIK, BOJAN, MIRZA;
	// Unosimo jela
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	// Racunamo najjeftinije mjesto
	// Restoran "Kod konja i konjušara"
	
	if(tarik == 'C')
		TARIK = c1;
	else if(tarik == 'H')
		TARIK = h1;
	else 
		TARIK = p1;
		
	if(bojan == 'C')
		BOJAN = c1;
	else if(bojan == 'H')
		BOJAN = h1;
	else 
		BOJAN = p1;
		
	if(mirza == 'C')
		MIRZA = c1;
	else if(mirza == 'H')
		MIRZA = h1;
	else
		MIRZA = p1;
		
	SRKIK = TARIK + BOJAN + MIRZA;
	
	// Fast-food "Trovač" //
	
	if(tarik == 'C')
		TARIK = c2;
	else if(tarik == 'H')
		TARIK = h2;
	else
		TARIK = p2;	
		
	if(bojan == 'C')
		BOJAN = c2;
	else if(bojan == 'H')
		BOJAN = h2;
	else
		BOJAN = p2;
		
	if(mirza == 'C')
		MIRZA = c2;
	else if(mirza == 'H')
		MIRZA = h2;
	else
		MIRZA = p2;
		
	SFFT = TARIK + BOJAN + MIRZA;
	
	// Bistro "Lorelei" //
	
	if(tarik == 'C')
		TARIK = c3;
	else if(tarik == 'H')
		TARIK = h3;
	else
		TARIK = p3;
		
	if(bojan == 'C')
		BOJAN = c3;
	else if(bojan == 'H')
		BOJAN = h3;
	else
		BOJAN = p3;
	
	if(mirza == 'C')
		MIRZA = c3;
	else if(mirza == 'H')
		MIRZA = h3;
	else
		MIRZA = p3;
		
	SBL = TARIK + BOJAN + MIRZA;
	
	if(SRKIK<SFFT && SRKIK<SBL) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", SRKIK);
		return 0;
		} 
	else if(SFFT<SRKIK && SFFT<SBL)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", SFFT);
	
	else if(SBL<SRKIK && SBL<SFFT)
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", SBL);
		
	if(SRKIK>SBL || SRKIK>SFFT) {
		
		if(tarik == 'P' && bojan == 'P' && mirza == 'P')
			SRKIK = SRKIK*0.9;
			
		else if(tarik == 'C' && bojan == 'C' && mirza == 'C')
			SRKIK = SRKIK*0.9;
			
		else if(tarik == 'H' && bojan == 'H' && mirza == 'H')
			SRKIK = SRKIK*0.9;
			
		else if(tarik == 'P' && bojan == 'P' && mirza == 'C') {
			if('P'>'C')
				SRKIK = SRKIK - 2*p1/10;
			else 
				SRKIK = SRKIK - c1/10;
		}
		else if(tarik == 'P' && bojan == 'P' && mirza == 'H') {
			if('P'>'H')
				SRKIK = SRKIK - 2*p1/10;
			else 
				SRKIK = SRKIK - h1/10;
		}
		
		else if(tarik == 'P' && bojan == 'C' && mirza == 'P') {
			if('P'>'C')
				SRKIK = SRKIK - 2*p1/10;
			else 
				SRKIK = SRKIK - c1/10;
		}
		
		else if(tarik == 'P' && bojan == 'C' && mirza == 'C') {
			if('P'>'C')
				SRKIK = SRKIK - p1/10;
			else 
				SRKIK = SRKIK - 2*c1/10;
		}
		
		else if(tarik == 'P' && bojan == 'C' && mirza == 'H') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		
		else if(tarik == 'P' && bojan == 'H' && mirza == 'P') {
			if('P'>'H')
				SRKIK = SRKIK - 2*p1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'P' && bojan == 'H' && mirza == 'C') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'P' && bojan == 'H' && mirza == 'H') {
			if('P'>'H')
				SRKIK = SRKIK - p1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'H' && bojan == 'P' && mirza == 'P') {
			if('P'>'H')
				SRKIK = SRKIK - 2*p1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'H' && bojan == 'P' && mirza == 'H') {
			if('P'>'H')
				SRKIK = SRKIK - p1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'H' && bojan == 'P' && mirza == 'C') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'H' && bojan == 'H' && mirza == 'P') {
			if('P'>'H')
				SRKIK = SRKIK - p1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'H' && bojan == 'H' && mirza == 'C') {
			if('C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'H' && bojan == 'C' && mirza == 'P') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'H' && bojan == 'C' && mirza == 'H') {
			if('C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'H' && bojan == 'C' && mirza == 'C') {
			if('C'>'H')
				SRKIK = SRKIK - 2*c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'C' && bojan == 'P' && mirza == 'P') {
			if('P'>'C')
				SRKIK = SRKIK - 2*p1/10;
			else
				SRKIK = SRKIK - c1/10;
		}
		else if(tarik == 'C' && bojan == 'P' && mirza == 'H') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'C' && bojan == 'P' && mirza == 'C') {
			if('P'>'C')
				SRKIK = SRKIK - p1/10;
			else
				SRKIK = SRKIK - 2*c1/10;
		}
		else if(tarik == 'C' && bojan == 'H' && mirza == 'P') {
			if('P'>'C' && 'P'>'H')
				SRKIK = SRKIK - p1/10;
			else if('C'>'P' && 'C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - h1/10;
		}
		else if(tarik == 'C' && bojan == 'H' && mirza == 'H') {
			if('C'>'H')
				SRKIK = SRKIK - c1/10;
			else
				SRKIK = SRKIK - 2*h1/10;
		}
		else if(tarik == 'C' && bojan == 'C' && mirza == 'P') {
			if('P'>'C')
				SRKIK = SRKIK - p1/10;
			else
				SRKIK = SRKIK - 2*c1/10;
		}
		else if(tarik == 'C' && bojan == 'C' && mirza == 'H') {
			if('H'>'C')
				SRKIK = SRKIK - h1/10;
			else
				SRKIK = SRKIK - 2*c1/10;
		}
	}
	
	if(SRKIK<SBL && SRKIK<SFFT)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", SRKIK);

	return 0;
}