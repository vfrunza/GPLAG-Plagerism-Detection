#include <stdio.h>
#define p1 6.80
#define h1 3.30
#define c1 5.00
#define p2 8.00
#define h2 3.00
#define c2 3.90
#define p3 5.30
#define h3 5.00
#define c3 6.00

int main()
{
	char tarik, bojan, mirza, novi_red;
	float menu1=0, menu2=0, menu3=0;
	float najjeftiniji;
	int ime, counterp=0, counterh=0, counterc=0, najveci_counter;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);

	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);

	switch(tarik) {
	case 'P':
		menu1+=p1;
		menu2+=p2;
		menu3+=p3;
		counterp++;
		break;
	case 'H':
		menu1+=h1;
		menu2+=h2;
		menu3+=h3;
		counterh++;
		break;
	case 'C':
		menu1+=c1;
		menu2+=c2;
		menu3+=c3;
		counterc++;
		break;
	}

	switch(bojan) {
	case 'P':
		menu1+=p1;
		menu2+=p2;
		menu3+=p3;
		counterp++;
		break;
	case 'H':
		menu1+=h1;
		menu2+=h2;
		menu3+=h3;
		counterh++;
		break;
	case 'C':
		menu1+=c1;
		menu2+=c2;
		menu3+=c3;
		counterc++;
		break;
	}

	switch(mirza) {
	case 'P':
		menu1+=p1;
		menu2+=p2;
		menu3+=p3;
		counterp++;
		break;
	case 'H':
		menu1+=h1;
		menu2+=h2;
		menu3+=h3;
		counterh++;
		break;
	case 'C':
		menu1+=c1;
		menu2+=c2;
		menu3+=c3;
		counterc++;
		break;
	}

	najjeftiniji=menu1;
	ime=1;

	if(menu2<najjeftiniji) {
		najjeftiniji=menu2;
		ime=2;
	}
	if(menu3<najjeftiniji) {
		najjeftiniji=menu3;
		ime=3;
	}

	if(ime==1)
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", najjeftiniji);
	else if (ime==2)
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", najjeftiniji);
	else
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", najjeftiniji);

	/*popust*/
	if(counterc==counterh && counterh==counterp)
		menu1-=0.1*p1;

	else {
		najveci_counter=counterc;
		if(counterh>najveci_counter) {
			najveci_counter=counterh;
		}
		if(counterp>najveci_counter) {
			najveci_counter=counterp;
		}
		/*printf("%d, %d, %d,  %f\n", counterp, counterh, counterc, menu1);*/
		if(najveci_counter==counterc) menu1-= 0.1*counterc*c1;
		else if(najveci_counter==counterp) menu1-=0.1*counterp*p1;
		else menu1-= 0.1*counterh*h1;
	}

	if(ime!=1 && menu1<najjeftiniji)
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", menu1);


	return 0;
}
