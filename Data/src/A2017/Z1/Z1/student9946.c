#include <stdio.h>

int main()
{
	char jeloTarik,jeloBojan,jeloMirza,novi_red;
	double hamburger=0,pizza=0,cevapi=0;
	double restoran,fast_food,bistro,popustRestoran,popustPizza,popustCevapi;


	printf("Unesite jelo za Tarika: ");
	scanf("%c", &jeloTarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &jeloBojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &jeloMirza);
	scanf("%c", &novi_red);
//Tarik jedno jelo
	if(jeloTarik=='H') {
		hamburger++;
	}
	if(jeloTarik=='P') {
		pizza ++;

	}
	if(jeloTarik=='C') {

		cevapi++;
	}
	//Bojan bira jedno jelo
	if(jeloBojan=='H') {
		hamburger++;
	}
	if(jeloBojan=='P') {
		pizza ++;

	}
	if(jeloBojan=='C') {
		cevapi++;
	}
	//Mirza bira jedno jelo
	if(jeloMirza=='H') {
		hamburger++;
	}
	if(jeloMirza=='P') {
		pizza ++;

	}
	if(jeloMirza=='C') {
		cevapi++;
	}
	//Za Restoran "Kod konja i konjušara"

	restoran=6.8*pizza+3.3*hamburger+cevapi*5.;

	popustRestoran=(6.8)*pizza+(3.3-0.33)*hamburger+cevapi*5.;
	popustPizza=(6.8*0.9)*pizza+(3.3)*hamburger+cevapi*5.;
	popustCevapi=6.8*pizza+3.3*hamburger+cevapi*(5.-0.05);

	//Za Fast-food "Trovač"
	fast_food=pizza*8.+hamburger*3.+cevapi*3.9;
	//Za Bistro "Lorelei"
	bistro=pizza*5.3+hamburger*5.+cevapi*6;
	printf("Najjeftiniji je ");
	if (bistro<=restoran && fast_food>=bistro) {
		printf("Bistro \"Lorelei\" (%.2lf KM).",bistro);

		if (bistro>popustPizza) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popustPizza);
		}

	}	else if (restoran<=fast_food && restoran<=bistro) {
		printf("Restoran \"Kod konja i konjusara\" (%.2lf KM).",restoran);

	}	else if (fast_food<=restoran && fast_food<=bistro) {
		printf("Fast-food \"Trovac\" (%.2lf KM).",fast_food);
		if (popustPizza<popustCevapi && popustPizza<fast_food) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popustPizza);
			return 0;
		} else if(fast_food>popustRestoran  ) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popustRestoran);

	//	}  else if (pizza==2) {
	//		printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popustPizza);

		} else if (fast_food>popustPizza) {
			printf("\nSa popustom bi Restoran bio jeftiniji (%.2lf KM).",popustPizza);
		}
	}
	return 0;
}
//ZAMJENI DA JE HAMBURGERU SNIZENA CIJENA DESET POSTO