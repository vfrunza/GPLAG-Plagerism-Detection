#include <stdio.h>

#define restoran_pica 6.80;
#define restoran_hamburger 3.30;
#define restoran_cevapi 5.00;

#define trovac_pica 8.00;
#define trovac_hamburger 3.00;
#define trovac_cevapi 3.90;

#define bistro_pica 5.30;
#define bistro_hamburger 5.00;
#define bistro_cevapi 6.00;

int main(){
	char tarik, bojan, mirza, novi_red;
	double suma_za_restoran=0, suma_za_trovac=0, suma_za_bistro=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	/* Za restoran */
	if(tarik=='P') suma_za_restoran+=restoran_pica;
	if(tarik=='H') suma_za_restoran+=restoran_hamburger;
	if(tarik=='C') suma_za_restoran+=restoran_cevapi;
	if(bojan=='P') suma_za_restoran+=restoran_pica;
	if(bojan=='H') suma_za_restoran+=restoran_hamburger;
	if(bojan=='C') suma_za_restoran+=restoran_cevapi;
	if(mirza=='P') suma_za_restoran+=restoran_pica;
	if(mirza=='H') suma_za_restoran+=restoran_hamburger;
	if(mirza=='C') suma_za_restoran+=restoran_cevapi;
	
	/* Za Trovac */
	if(tarik=='P') suma_za_trovac+=trovac_pica
	if(tarik=='H') suma_za_trovac+=trovac_hamburger;
	if(tarik=='C') suma_za_trovac+=trovac_cevapi;
	if(bojan=='P') suma_za_trovac+=trovac_pica;
	if(bojan=='H') suma_za_trovac+=trovac_hamburger;
	if(bojan=='C') suma_za_trovac+=trovac_cevapi;
	if(mirza=='P') suma_za_trovac+=trovac_pica;
	if(mirza=='H') suma_za_trovac+=trovac_hamburger;
	if(mirza=='C') suma_za_trovac+=trovac_cevapi;
	
	/* Za Bistro */
	if(tarik=='P') suma_za_bistro+=bistro_pica;
	if(tarik=='H') suma_za_bistro+=bistro_hamburger;
	if(tarik=='C') suma_za_bistro+=bistro_cevapi;
	if(bojan=='P') suma_za_bistro+=bistro_pica;
	if(bojan=='H') suma_za_bistro+=bistro_hamburger;
	if(bojan=='C') suma_za_bistro+=bistro_cevapi;
	if(mirza=='P') suma_za_bistro+=bistro_pica;
	if(mirza=='H') suma_za_bistro+=bistro_hamburger;
	if(mirza=='C') suma_za_bistro+=bistro_cevapi;
	
	if(suma_za_restoran<suma_za_trovac && suma_za_restoran<suma_za_bistro)
	printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", suma_za_restoran);
	
	if(suma_za_trovac<suma_za_restoran && suma_za_trovac<suma_za_bistro){
		suma_za_restoran-=((10./100)*suma_za_restoran);
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", suma_za_trovac);
		if(suma_za_restoran<suma_za_trovac) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma_za_restoran);
	}
	
	if(suma_za_bistro<suma_za_trovac && suma_za_bistro<suma_za_restoran){
		suma_za_restoran-=((10./100)*suma_za_restoran);
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", suma_za_bistro);
		if(suma_za_restoran<suma_za_bistro) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", suma_za_restoran);
	}
	
	
	
	
	return 0;
}
