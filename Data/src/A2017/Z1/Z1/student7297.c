#include <stdio.h>
#include <stdlib.h>

int main(){
	float P1, P2, P3, H1, H2, H3, C1, C2, C3;
	P1=6.80;
	P2=8.00;
	P3=5.30;
	H1=3.30;
	H2=3.00;
	H3=5.00;
	C1=5.00;
	C2=3.90;
	C3=6.00;
	char tarik, bojan, mirza, novi_red;
	char c;
	float racun1, racun2, racun3;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
    racun1=0;
	racun2=0;
	racun3=0;
int P, H, C;
    P=0;
	H=0;
	C=0;
/*Za Tarika*/	
	if(tarik=='P')
	racun1=racun1+P1;
	if(tarik=='H')
	racun1=racun1+H1;
	if(tarik=='C')
	racun1=racun1+C3;
	if(tarik=='P')
	racun2=racun2+P2;
	if(tarik=='H')
	racun2=racun2+H2;
	if(tarik=='C');
	racun2=racun2+C2;
	if(tarik=='P')
	racun3=racun3+P3;
	if(tarik=='H')
	racun3=racun3+H3;
	if(tarik=='C')
	racun3=racun3+C3;
	/*Za Bojana*/
	if(bojan=='P')
	racun1=racun1+P1;
	racun2=racun2+P2;
	racun3=racun3+P3;
	if(bojan=='H')
	racun1=racun1+H1;
	racun2=racun2+H2;
	racun3=racun3+H3;
	if(bojan=='C')
	racun1=racun1+C1;
	racun2=racun2+C2;
	racun3=racun3+C3;
	/*Za Mirzu*/
	if(mirza=='P')
	racun1=racun1+P1;
	racun2=racun2+P2;
	racun3=racun3+P3;
	if(mirza=='H')
	racun1=racun1+H1;
	racun2=racun2+H2;
	racun3=racun3+H3;
	if(mirza=='C')
	racun1=racun1+C1;
	racun2=racun2+C2;
	racun3=racun3+C3;
	
	if(racun1<racun2 && racun1<racun3)
	printf("Najjeftiniji je Restoran 'Kod konja i konjusara' (%.2f KM).\n", racun1);
	 else if(racun2<racun1 && racun2<racun3)
	printf("Najjeftiniji je Fast-food 'Trovac' (%.2f KM).\n", racun2);
	else if(racun3<racun2 && racun3<racun1)
	printf("Najjeftiniji je Bistro 'Lorelei' (%.2f KM).\n", racun3);
	
	if(racun1>racun2 && racun1>racun3){
	racun1=racun1-0.1*racun1;
	printf("Sa popustom bi Restoran bio najjeftiniji (%.2f KM).\n", racun1);}
	else if(racun2>racun1 && racun2>racun3){
	racun2=racun2-0.1*racun2;
	printf("Sa popustom bi Fast-food bio najjeftiniji (%.2f KM).\n ", racun2);}
	else if(racun3>racun1 && racun3>racun2){
	racun3=racun3-0.1*racun3;
	printf("Sa popustom bi Bistro bio najjeftiniji (%.2f KM).\n ", racun3);}
	return 0;
}
