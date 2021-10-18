#include <stdio.h>
#include <math.h>

int main()
{

	char tarik, bojan, mirza;
	float saldo_restoran, saldo_trovac, saldo_lorelei, novi_red;
	float restoran_popust = 0;

	saldo_lorelei = 0;
	saldo_trovac = 0;
	saldo_restoran = 0;

	float popust_na_cijenu = 0;
	int broj_jela_na_popust = 0;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	if(tarik == 'H') {
		saldo_restoran += 3.3;
		saldo_trovac += 3.0;
		saldo_lorelei += 5.0;

		if(fabs(popust_na_cijenu - 3.3)>0.001) {
			popust_na_cijenu = 3.3;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 3.3)<0.001) {
			broj_jela_na_popust ++;
		}

	}

	else if(tarik == 'P') {
		saldo_restoran += 6.8;
		saldo_trovac += 8.0;
		saldo_lorelei += 5.3;

		if(fabs(popust_na_cijenu - 6.8)>0.001) {
			popust_na_cijenu = 6.8;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 6.8)<0.001) {
			broj_jela_na_popust ++;
		}
	}

	else if(tarik == 'C') {
		saldo_restoran += 5.0;
		saldo_trovac += 3.9;
		saldo_lorelei += 6.0;

		if(fabs(popust_na_cijenu - 5.0)>0.001) {
			popust_na_cijenu = 5.0;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 5.0)<0.001) {
			broj_jela_na_popust ++;
		}
	}

	if(bojan == 'H') {

		saldo_restoran += 3.3;
		saldo_trovac += 3.0;
		saldo_lorelei += 5.0;

		if(fabs(popust_na_cijenu - 3.3)>0.001) {
			popust_na_cijenu = 3.3;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 3.3)<0.001) {
			broj_jela_na_popust ++;
		}
	} else if(bojan == 'P') {


		saldo_restoran += 6.8;

		saldo_trovac += 8.0;

		saldo_lorelei += 5.3;

		if(fabs(popust_na_cijenu - 6.8)>0.001) {
			popust_na_cijenu = 6.8;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 6.8)<0.001) {
			broj_jela_na_popust ++;
		}

	} else if(bojan == 'C') {


		saldo_restoran += 5.0;

		saldo_trovac += 3.9;

		saldo_lorelei += 6.0;

		if(fabs(popust_na_cijenu - 5.0)>0.001) {
			popust_na_cijenu = 5.0;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 5.0)<0.001) {
			broj_jela_na_popust ++;
		}

	}
	if(mirza == 'H') {

		saldo_restoran += 3.3;

		saldo_trovac += 3.0;

		saldo_lorelei += 5.0;

		if(fabs(popust_na_cijenu - 3.3)>0.001) {
			popust_na_cijenu = 3.3;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 3.3)<0.001) {
			broj_jela_na_popust ++;
		}


	} else if(mirza == 'P') {

		saldo_restoran += 6.8;

		saldo_trovac += 8.0;

		saldo_lorelei += 5.3;

		if(fabs(popust_na_cijenu - 6.8)>0.001) {
			popust_na_cijenu = 6.8;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 6.8)<0.001) {
			broj_jela_na_popust ++;
		}

	} else if(mirza == 'C') {

		saldo_restoran += 5.0;

		saldo_trovac += 3.9;
		saldo_lorelei += 6.0;

		if(fabs(popust_na_cijenu - 5.0)>0.001) {
			popust_na_cijenu = 5.0;
			broj_jela_na_popust = 1;
		} else if((popust_na_cijenu - 5.0)<0.001) {
			broj_jela_na_popust ++;
		}
	}



	restoran_popust = saldo_restoran - (popust_na_cijenu * broj_jela_na_popust * 0.1);


	if((saldo_restoran < saldo_lorelei) && (saldo_restoran < saldo_trovac)) {


		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", saldo_restoran);

	}
	if((saldo_trovac < saldo_restoran) && (saldo_trovac < saldo_lorelei)) {


		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", saldo_trovac);

	}
	if((saldo_lorelei < saldo_restoran) && (saldo_lorelei < saldo_trovac)) {


		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", saldo_lorelei);

	}
	if((saldo_trovac < saldo_restoran) && (saldo_trovac< saldo_lorelei) && (saldo_trovac > restoran_popust)) {


		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM). ", restoran_popust);

	}
	if((saldo_lorelei  < saldo_trovac) && (saldo_lorelei < saldo_restoran) && (saldo_lorelei > restoran_popust)) {

		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM). ", restoran_popust);

	}
	return 0;
}


