#include <stdio.h>

#define R_PIZZA 6.8
#define R_HAMBURGER 3.3
#define R_CEVAPI 5.0
#define R_IME "Restoran \"Kod konja i konjusara\""
#define F_PIZZA 8.0
#define F_HAMBURGER 3.0
#define F_CEVAPI 3.9
#define F_IME "Fast-food \"Trovac\""
#define B_PIZZA 5.3
#define B_HAMBURGER 5.0
#define B_CEVAPI 6.0
#define B_IME "Bistro \"Lorelei\""

int main()
{
	char jeloTarik, jeloBojan, jeloMirza, noviRed;
	float najjeftiniji_cijena,najjeftiniji_popust,popust_cevapi,popust_hamburger,popust_pizza;
	char najjeftiniji_kod_koga;
	float r_cijena = 0, f_cijena = 0, b_cijena = 0;
	int broj_pizza=0, broj_hamburgera=0, broj_cevapa=0;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &jeloTarik);
	scanf("%c", &noviRed);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &jeloBojan);
	scanf("%c", &noviRed);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &jeloMirza);
	scanf("%c", &noviRed);

	
	if(jeloMirza=='H'){
		broj_hamburgera++;
	}
	else if(jeloMirza=='C'){
		broj_cevapa++;
	}
	else{
		broj_pizza++;
	}

	if(jeloBojan=='H'){
		broj_hamburgera++;
	}
	else if(jeloBojan=='C'){
		broj_cevapa++;
	}
	else{
		broj_pizza++;
	}

	if(jeloTarik=='H'){
		broj_hamburgera++;
	}
	else if(jeloTarik=='C'){
		broj_cevapa++;
	}
	else{
		broj_pizza++;
	}

	r_cijena = broj_pizza*R_PIZZA + broj_cevapa*R_CEVAPI+broj_hamburgera*R_HAMBURGER;
	f_cijena = broj_pizza*F_PIZZA + broj_cevapa*F_CEVAPI+broj_hamburgera*F_HAMBURGER;
	b_cijena = broj_pizza*B_PIZZA + broj_cevapa*B_CEVAPI+broj_hamburgera*B_HAMBURGER;

    najjeftiniji_cijena = r_cijena;
	najjeftiniji_kod_koga = 'R';
	if(f_cijena<najjeftiniji_cijena){
		najjeftiniji_cijena = f_cijena;
		najjeftiniji_kod_koga='F';
	}
	if(b_cijena<najjeftiniji_cijena){
		najjeftiniji_cijena = b_cijena;
		najjeftiniji_kod_koga='B';
	}
	
	if(najjeftiniji_kod_koga=='F')
	printf("Najjeftiniji je %s (%.2f KM).",F_IME,najjeftiniji_cijena);
	else if(najjeftiniji_kod_koga=='B')
	printf("Najjeftiniji je %s (%.2f KM).",B_IME,najjeftiniji_cijena);
	else
	{
		printf("Najjeftiniji je %s (%.2f KM).",R_IME,najjeftiniji_cijena);
	}
	
	if(najjeftiniji_kod_koga!='R'){
		popust_cevapi = broj_hamburgera*R_HAMBURGER + broj_pizza*R_PIZZA+broj_cevapa*R_CEVAPI*0.9;
		popust_hamburger = broj_hamburgera*R_HAMBURGER*0.9 + broj_pizza*R_PIZZA+broj_cevapa*R_CEVAPI;
		popust_pizza = broj_hamburgera*R_HAMBURGER + broj_pizza*R_PIZZA*0.9+broj_cevapa*R_CEVAPI;
		
		najjeftiniji_popust = popust_pizza;
		if (popust_hamburger<najjeftiniji_popust){
			najjeftiniji_popust = popust_hamburger;
		}
		if(popust_cevapi<najjeftiniji_popust){
			najjeftiniji_popust=popust_cevapi;
		}
		
		
		if( najjeftiniji_popust < najjeftiniji_cijena){
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",najjeftiniji_popust);
		}
	}
	return 0;
}
