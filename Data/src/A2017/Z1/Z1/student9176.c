#include <stdio.h>

int main()
{
	char tarik,bojan,mirza,novi_red;
	double restoran=0,fast_food=0,bistro=0,minimum,maximum;
	int pizza=0,hamburger=0,cevapi=0,restoran_odabran=0,fast_food_odabran=0,bistro_odabran=0;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&tarik);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&bojan);
	scanf("%c",&novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&mirza);
	scanf("%c",&novi_red);
	if(tarik=='P') {
		restoran += 6.8;
		fast_food += 8.0;
		bistro += 5.3;
		pizza++;
	} else if (tarik=='H') {
		restoran += 3.3;
		fast_food += 3.0;
		bistro += 5.0;
		hamburger++;
	}
	else {
		restoran += 5.0;
		fast_food += 3.9;
		bistro += 6.0;
		cevapi++;
		
	}
	if(bojan=='P') {
		restoran += 6.8;
		fast_food += 8.0;
		bistro += 5.3;
		pizza++;
	}
	else if(bojan=='H') {
		restoran += 3.3;
		fast_food += 3.0;
		bistro += 5.0;
		hamburger++;
	}
	else {
		restoran += 5.0;
		fast_food += 3.9;
		bistro += 6.0;
		cevapi++;
	}
	if(mirza=='P') {
		restoran += 6.8;
		fast_food += 8.0;
		bistro += 5.3;
		pizza++;
	}
	else if(mirza=='H') {
		restoran += 3.3;
		fast_food += 3.0;
		bistro += 5.0;
		hamburger++;
	}
	else {
		restoran += 5.0;
		fast_food += 3.9;
		bistro += 6.0;
		cevapi++;
	}
	if(restoran<fast_food && restoran<bistro) {
		minimum=restoran;
		restoran_odabran=1;
	}
	else if(fast_food<restoran && fast_food<bistro) {
		minimum=fast_food;
		fast_food_odabran=1;
	}
	else {
		minimum=bistro;
		bistro_odabran=1;
	}
	if(pizza*6.8 > hamburger*3.3 && pizza*6.8 > cevapi*5.0) 
	{
		maximum= pizza*6.8;
	}
	else if(hamburger*3.3 > pizza*6.8 && hamburger*3.3 > cevapi*5.0) {
		maximum= hamburger*3.3;
	}
	else {
		maximum= cevapi*5.0;
	}
	restoran=restoran-(maximum*0.1);
	if(restoran_odabran==1) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n",minimum);
	}
	else if(fast_food_odabran==1) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",minimum);
	}
	else {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",minimum);
	}
	if(restoran_odabran !=1 && restoran<minimum) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",restoran);
		
	}
	
	return 0;
}
