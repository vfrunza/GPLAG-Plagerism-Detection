#include <stdio.h>

int main() {
	int hamburger=0, cevapi=0, pizza=0;
	float restoran, fastfood, bistro;
	char tarik, bojan, mirza, novired;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	
	switch(tarik) {
		case 'H':
			hamburger++;
			break;
		case 'C':
			cevapi++;
			break;
		case 'P':
			pizza++;
			break;
	}
	switch(bojan) {
		case 'H':
			hamburger++;
			break;
		case 'C':
			cevapi++;
			break;
		case 'P':
			pizza++;
			break;
	}
	switch(mirza) {
		case 'H':
			hamburger++;
			break;
		case 'C':
			cevapi++;
			break;
		case 'P':
			pizza++;
			break;
	}
	
	restoran=pizza*6.8+hamburger*3.3+cevapi*5.;
	fastfood=pizza*8+hamburger*3+cevapi*3.9;
	bistro=pizza*5.3+hamburger*5+cevapi*6;
	
	if (restoran<=fastfood && restoran<=bistro)
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	else if (fastfood<=restoran && fastfood<=bistro) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", fastfood);
		if (pizza>=1) {
			restoran=pizza*6.8*0.9+hamburger*3.3+cevapi*5;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
		else if (pizza==0 && cevapi>=1) {
			restoran=hamburger*3.3+cevapi*5*0.9;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
		else {
			restoran=hamburger*3.3*0.9;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
	}
	
	else {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", bistro);
		if (pizza>=1) {
			restoran=pizza*6.8*0.9+hamburger*3.3+cevapi*5;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
		else if (pizza==0 && cevapi>=1) {
			restoran=hamburger*3.3+cevapi*5*0.9;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
		else {
			restoran=hamburger*3.3*0.9;
			if (restoran<fastfood && restoran<bistro)
				printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);
		}
	}
	return 0;
}
