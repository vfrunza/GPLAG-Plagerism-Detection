#include <stdio.h>

int main()
{
	char tarik;
	char bojan;
	char mirza;
	char novi_red;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	double fastfood=0;
	double restoran=0;
	double bistro=0;

	double ffpizza=8;
	double ffhamb=3;
	double ffcevapi=3.9;

	double rpizza=6.8;
	double rhamb=3.3;
	double rcevapi=5;

	double bpizza=5.3;
	double bhamb=5;
	double bcevapi=6;

	double pizzaurestoranu=0;
	double hamburestoranu=0;
	double cevapiurestoranu=0;


	if(tarik=='P') {
		fastfood+=ffpizza;
		restoran+=rpizza;
		pizzaurestoranu+=rpizza;
		bistro+=bpizza;
	}

	if(tarik=='H') {
		fastfood+=ffhamb;
		restoran+=rhamb;
		hamburestoranu+=rhamb;
		bistro+=bhamb;
	}

	if(tarik=='C') {
		fastfood+=ffcevapi;
		restoran+=rcevapi;
		cevapiurestoranu+=rcevapi;
		bistro+=bcevapi;
	}

	if(bojan=='P') {
		fastfood+=ffpizza;
		restoran+=rpizza;
		pizzaurestoranu+=rpizza;
		bistro+=bpizza;
	}

	if(bojan=='H') {
		fastfood+=ffhamb;
		restoran+=rhamb;
		hamburestoranu+=rhamb;
		bistro+=bhamb;
	}

	if(bojan=='C') {
		fastfood+=ffcevapi;
		restoran+=rcevapi;
		cevapiurestoranu+=rcevapi;
		bistro+=bcevapi;
	}

	if(mirza=='P') {
		fastfood+=ffpizza;
		restoran+=rpizza;
		pizzaurestoranu+=rpizza;
		bistro+=bpizza;
	}

	if(mirza=='H') {
		fastfood+=ffhamb;
		restoran+=rhamb;
		hamburestoranu+=rhamb;
		bistro+=bhamb;
	}

	if(mirza=='C') {
		fastfood+=ffcevapi;
		restoran+=rcevapi;
		cevapiurestoranu+=rcevapi;
		bistro+=bcevapi;
	}

	double ukupnacijena=0;
	if(fastfood<=restoran && fastfood<=bistro) {
		ukupnacijena = fastfood;
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", ukupnacijena);
	}
	if(restoran<=fastfood && restoran<=bistro) {
		ukupnacijena = restoran;
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", ukupnacijena);
	}
	if(bistro<=fastfood && bistro<=restoran) {
		ukupnacijena = bistro;
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", ukupnacijena);
	}


	if(!(restoran<=fastfood && restoran<=bistro)) {
		if(pizzaurestoranu>=hamburestoranu && pizzaurestoranu>=cevapiurestoranu) restoran=restoran-pizzaurestoranu/10;
		else if(hamburestoranu>=pizzaurestoranu && hamburestoranu>=cevapiurestoranu) restoran=restoran-hamburestoranu/10;
		else restoran=restoran-cevapiurestoranu/10;
	}


	if(restoran<ukupnacijena) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", restoran);

	return 0;
}
