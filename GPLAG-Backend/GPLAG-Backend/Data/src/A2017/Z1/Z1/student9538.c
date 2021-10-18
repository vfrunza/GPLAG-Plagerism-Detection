#include <stdio.h>

int main() {
	char T,B,M,znak;
	double Cijena1=0,Cijena2=0,Cijena3=0;
	int H=0,P=0,C=0;
	double Hamburger1=3.3,Pizza1=6.8,Cevapi1=5,Hamburger2=3,Pizza2=8,Cevapi2=3.9,Hamburger3=5,Pizza3=5.3,Cevapi3=6;
	printf("Unesite jelo za Tarika: ");
	scanf("%c",&T);
	scanf("%c",&znak);
	printf("Unesite jelo za Bojana: ");
	scanf("%c",&B);
	scanf("%c",&znak);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c",&M);
	scanf("%c",&znak);
	if(T=='H') H++;
	else if(T=='P') P++;
	else if(T=='C')C++;
	if(B=='H') H++;
	else if(T=='P')P++;
	else if(T=='C') C++;
	if(M=='H') H++;
	else if(M=='P') P++;
	else if(M=='C') C++;
	Cijena1=H*Hamburger1+P*Pizza1+C*Cevapi1;
	Cijena2=H*Hamburger2+P*Pizza2+C*Cevapi2;
	Cijena3=H*Hamburger3+P*Pizza3+C*Cevapi3;
	if(Cijena1<Cijena2 && Cijena1<Cijena3) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",Cijena1);
	else {
	if 	(Cijena2<Cijena1 && Cijena2<Cijena3) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",Cijena2);
	else printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",Cijena3);
	if(H>P && H>C) Hamburger1=Hamburger1*0.9;
	else if(P>H && P>C) Hamburger2=Hamburger2*0.9;
	else Hamburger3=Hamburger3*0.9;
	Cijena1=H*Hamburger1+P*Pizza1+C*Cevapi1;
	if(Cijena1<Cijena2 && Cijena1<Cijena3) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",Cijena1);
	}
	return 0;
}
