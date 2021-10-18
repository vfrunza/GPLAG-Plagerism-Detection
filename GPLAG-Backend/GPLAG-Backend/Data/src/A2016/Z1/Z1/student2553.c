#include <stdio.h>
#define e 0.0001
int main() {
	float tarikp1=0,tarikp2=0,tarikpris=0,tarikz=0,tarikispit=0,
	bojanp1=0,bojanp2=0,bojanpris=0,bojanz=0,bojanispit=0,
	mirzap1=0,mirzap2=0,mirzapris=0,mirzaz=0,mirzaispit=0,tarikb=0,mirzab=0,bojanb=0;
	tarikp1=1;
	tarikp2=1;
	tarikpris=1;
	tarikz=1;
	tarikispit=1;
	tarikb=1;
	int tarik=0,bojan=0,mirza=0;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&tarikp1);
	if(tarikp1>20 || tarikp1<0){printf("Neispravan broj bodova");return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&tarikp2);
	if(tarikp2>20 || tarikp2<0){printf("Neispravan broj bodova");return 0;}
	printf("Prisustvo: ");
	scanf("%f",&tarikpris);
	if(tarikpris>10 || tarikpris<0){printf("Neispravan broj bodova");return 0;}
	printf("Zadace: ");
	scanf("%f",&tarikz);
	if(tarikz>10 || tarikz<0){printf("Neispravan broj bodova");return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&tarikispit);
	if(tarikispit>40 || tarikispit<0){printf("Neispravan broj bodova");return 0;}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&bojanp1);
	if(bojanp1>20 || bojanp1<0){printf("Neispravan broj bodova");return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&bojanp2);
	if(bojanp2>20 || bojanp2<0){printf("Neispravan broj bodova");return 0;}
	printf("Prisustvo: ");
	scanf("%f",&bojanpris);
	if(bojanpris>10 || bojanpris<0){printf("Neispravan broj bodova");return 0;}
	printf("Zadace: ");
	scanf("%f",&bojanz);
	if(bojanz>10 || bojanz<0){printf("Neispravan broj bodova");return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&bojanispit); 
	if(bojanispit>40 || bojanispit<0){printf("Neispravan broj bodova");return 0;}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&mirzap1);
	if(mirzap1>20 || mirzap1<0){printf("Neispravan broj bodova");return 0;}
	printf("II parcijalni ispit: ");
	scanf("%f",&mirzap2);
	if(mirzap2>20 || mirzap2<0){printf("Neispravan broj bodova");return 0;}
	printf("Prisustvo: ");
	scanf("%f",&mirzapris);
	if(mirzapris>10 || mirzapris<0){printf("Neispravan broj bodova");return 0;}
	printf("Zadace: ");
	scanf("%f",&mirzaz);
	if(mirzaz>10 || mirzaz<0){printf("Neispravan broj bodova");return 0;}
	printf("Zavrsni ispit: ");
	scanf("%f",&mirzaispit); 
	if(mirzaispit>40 || mirzaispit<0){printf("Neispravan broj bodova");return 0;}

	
	tarikb=tarikp1+tarikp2+tarikz+tarikpris+tarikispit+e;
	bojanb=bojanp1+bojanp2+bojanz+bojanpris+bojanispit+e;
	mirzab=mirzap1+mirzap2+mirzaz+mirzapris+mirzaispit+e;
	
	
	if(tarikb<55){tarik=5;}
	else if(tarikb>=55 && tarikb<65){tarik=6;}
	else if(tarikb>=65 && tarikb<75){tarik=7;}
	else if(tarikb>=75 && tarikb<85){tarik=8;}
	else if(tarikb>=85 && tarikb<92){tarik=9;}
	else if(tarikb>=92 && tarikb<=100){tarik=10;}
	
	if(bojanb<55){bojan=5;}
	else if(bojanb>=55 && bojanb<65){bojan=6;}
	else if(bojanb>=65 && bojanb<75){bojan=7;}
	else if(bojanb>=75 && bojanb<85){bojan=8;}
	else if(bojanb>=85 && bojanb<92){bojan=9;}
	else if(bojanb>=92 && bojanb<=100){bojan=10;}
	
	if(mirzab<55){mirza=5; }
	else if(mirzab>=55 && mirzab<65){mirza=6;}
	else if(mirzab>=65 && mirzab<75){mirza=7;}
	else if(mirzab>=75 && mirzab<85){mirza=8;}
	else if(mirzab>=85 && mirzab<92){mirza=9;}
	else if(mirzab>=92 && mirzab<=100){mirza=10;}
	
	if(tarik==5 && bojan==5 && mirza==5){printf("Nijedan student nije polozio.\n");}
	else if(tarik!=5 && bojan!=5 && mirza!=5){
		printf("Sva tri studenta su polozila.\n");
    	if(tarik==mirza && mirza==bojan){printf("Sva tri studenta imaju istu ocjenu.\n");}
		else if(tarik!=mirza && tarik!=bojan && bojan!= mirza){printf("Svaki student ima razlicitu ocjenu.\n");}
		else {printf("Dva od tri studenta imaju istu ocjenu.\n");}}
	
	else if(tarik==5 && ( bojan!=5 && mirza!=5)){printf("Dva studenta su polozila.\n");}
	else if(bojan==5 && ( tarik!=5 && mirza!=5)){printf("Dva studenta su polozila.\n");}
	else if(mirza==5 && ( bojan!=5 && tarik!=5)){printf("Dva studenta su polozila.\n");}
	else {printf("Jedan student je polozio.");}
	
	return 0;
}
