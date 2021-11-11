#include <stdio.h>

int main() {
	char tarik, bojan, novi_red, mirza;
	float restoran1, restoran2, restoran3, UKrestoran;
	float fastfood1, fastfood2, fastfood3, UKfastfood;
	float bistro1, bistro2, bistro3, UKbistro;
	int komada_pice_rest = 0, komada_hamb_rest = 0, porcija_cevapa_rest = 0;
	float restoran_najskuplje = 0.0;
	float restoran_sa_popustom = 0.0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	/*Restoran "Kod konja i konjusara"*/
	if (tarik == 'P'){
		restoran1 = 6.80;
		komada_pice_rest += 1;
	} else if (tarik == 'H'){
		restoran1 = 3.30;
		komada_hamb_rest += 1;
	} else if (tarik == 'C'){
		restoran1 = 5.00;
		porcija_cevapa_rest += 1;
	}
	
	if (bojan == 'P'){
		restoran2 = 6.80;
		komada_pice_rest += 1;
	} else if (bojan == 'H'){
		restoran2 = 3.30;
		komada_hamb_rest += 1;
	} else if (bojan == 'C'){
		restoran2 = 5.00;
		porcija_cevapa_rest += 1;
	}
	
	if (mirza == 'P'){
		restoran3 = 6.80;
		komada_pice_rest += 1;
	} else if (mirza == 'H'){
		restoran3 = 3.30;
		komada_hamb_rest += 1;
	} else if (mirza == 'C'){
		restoran3 = 5.00;
		porcija_cevapa_rest += 1;
	}
	
	// cijena bez popusta 
	restoran_sa_popustom = komada_pice_rest * 6.8 + komada_hamb_rest * 3.30 + porcija_cevapa_rest * 5.0;
	// ako ce cijena biti manja ako apliciramo popust na picu, onda postavi novu cijenu sa popustom sa -10% na picu 
	if (restoran_sa_popustom > komada_pice_rest * 6.8 * 0.9 + komada_hamb_rest * 3.30 + porcija_cevapa_rest * 5.0)
		restoran_sa_popustom = komada_pice_rest * 6.8 * 0.9 + komada_hamb_rest * 3.30 + porcija_cevapa_rest * 5.0;
	// ako ce cijena biti manja ako apliciramo popust na hamburger, onda postavi novu cijenu sa popustom sa -10% na hamburger
	if (restoran_sa_popustom > komada_pice_rest * 6.8 + komada_hamb_rest * 3.30 * 0.9 + porcija_cevapa_rest * 5.0)
		restoran_sa_popustom = komada_pice_rest * 6.8 + komada_hamb_rest * 3.30 * 0.9 + porcija_cevapa_rest * 5.0;
	// ako ce cijena biti manja ako apliciramo popust na cevape, onda postavi novu cijenu sa popustom sa -10% na cevape
	if (restoran_sa_popustom > komada_pice_rest * 6.8 + komada_hamb_rest * 3.30 + porcija_cevapa_rest * 5.0 * 0.9)
		restoran_sa_popustom = komada_pice_rest * 6.8 + komada_hamb_rest * 3.30 + porcija_cevapa_rest * 5.0 * 0.9;


	UKrestoran = restoran1 + restoran2 + restoran3;
	
	/*Fast food "Trovac"*/
	if (tarik == 'P'){
		fastfood1 = 8.00;
	} else if (tarik == 'H'){
		fastfood1 = 3.00;
	} else if (tarik == 'C'){
		fastfood1 = 3.90;
	}
	
	if (bojan == 'P'){
		fastfood2 = 8.00;
	} else if (bojan == 'H'){
		fastfood2 = 3.00;
	} else if (bojan == 'C'){
		fastfood2 = 3.90;
	}
	
	if (mirza == 'P'){
		fastfood3 = 8.00;
	} else if (mirza == 'H'){
		fastfood3 = 3.00;
	} else if (mirza == 'C'){
		fastfood3 = 3.90;
	}
	UKfastfood = fastfood1 + fastfood2 + fastfood3;
	
	/*Bistro "Lorelei"*/
	if (tarik == 'P'){
		bistro1 = 5.30;
	} else if (tarik == 'H'){
		bistro1 = 5.00;
	} else if (tarik == 'C'){
		bistro1 = 6.00;
	}
	
	if (bojan == 'P'){
		bistro2 = 5.30;
	} else if (bojan == 'H'){
		bistro2 = 5.00;
	} else if (bojan == 'C'){
		bistro2 = 6.00;
	}
	
	if (mirza == 'P'){
		bistro3 = 5.30;
	} else if (mirza == 'H'){
		bistro3 = 5.00;
	} else if (mirza == 'C'){
		bistro3 = 6.00;
	}
	UKbistro = bistro1 + bistro2 + bistro3;
	
	if (UKrestoran < UKfastfood && UKrestoran < UKbistro){
		printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", UKrestoran);
	} else {
		if (UKfastfood < UKrestoran && UKfastfood < UKbistro){
			printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", UKfastfood);
		} else if (UKbistro < UKrestoran && UKbistro < UKfastfood){
			printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", UKbistro);
		}
		
		if (restoran_sa_popustom < UKfastfood && restoran_sa_popustom < UKbistro) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", restoran_sa_popustom);
		}
	}
	
	return 0;
}
