#include <stdio.h>
#define P1 6.80																					/*pod indeksom 1-restoran; 2-fast food; 3-bistro */
#define P2 8.00
#define P3 5.30
#define H1 3.30
#define H2 3.00
#define H3 5.00
#define C1 5.00
#define C2 3.90
#define C3 6.00

int main() {
	int P=0,H=0,C=0;
	char T, B, M, novi_red; 																	/*Tarik, Bojan, Mirza */
	double cijena_uk1=0, cijena_uk2=0, cijena_uk3=0;											/* ukupna cijena: restoran(1) fast food(2) bistro(3)  */
	double popust3, popust2, popust1;
	char n='"';

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novi_red);
	
	if(T=='P') {
	P++;
		cijena_uk1=cijena_uk1+P1;
		cijena_uk2=cijena_uk2+P2;
		cijena_uk3=cijena_uk3+P3;
	}
	else if(T=='H') {
	H++;
		cijena_uk1=cijena_uk1+H1;
		cijena_uk2=cijena_uk2+H2;
		cijena_uk3=cijena_uk3+H3;
	}
	else if(T=='C') {
	C++;
		cijena_uk1=cijena_uk1+C1;
		cijena_uk2=cijena_uk2+C2;
		cijena_uk3=cijena_uk3+C3;
	}
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novi_red);
	
	if(B=='P') {
	P++;
		cijena_uk1=cijena_uk1+P1;
		cijena_uk2=cijena_uk2+P2;
		cijena_uk3=cijena_uk3+P3;
	}
	else if(B=='H') {
	H++;
		cijena_uk1=cijena_uk1+H1;
		cijena_uk2=cijena_uk2+H2;
		cijena_uk3=cijena_uk3+H3;
	}
	else if(B=='C') {
	C++;
		cijena_uk1=cijena_uk1+C1;
		cijena_uk2=cijena_uk2+C2;
		cijena_uk3=cijena_uk3+C3;
	}
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	
	if(M=='P') {
	P++;
		cijena_uk1=cijena_uk1+P1;
		cijena_uk2=cijena_uk2+P2;
		cijena_uk3=cijena_uk3+P3;
	}
	else if(M=='H') {
	H++;
		cijena_uk1=cijena_uk1+H1;
		cijena_uk2=cijena_uk2+H2;
		cijena_uk3=cijena_uk3+H3;
	}
	else if(M=='C') {
	C++;
		cijena_uk1=cijena_uk1+C1;
		cijena_uk2=cijena_uk2+C2;
		cijena_uk3=cijena_uk3+C3;
	}
	
	if(cijena_uk1<cijena_uk2 && cijena_uk1<cijena_uk3) {
		printf("Najjeftiniji je Restoran %cKod konja i konjusara%c (%.2f KM).\n", n, n, cijena_uk1);
		return 0;
	}
	else if(cijena_uk2<cijena_uk1 && cijena_uk2<cijena_uk3) {
		printf("Najjeftiniji je Fast-food %cTrovac%c (%.2f KM).\n", n, n, cijena_uk2);
	}
	else {
		printf("Najjeftiniji je Bistro %cLorelei%c (%.2f KM).\n", n,n, cijena_uk3);
	}
	
	if(cijena_uk1 > cijena_uk2 || cijena_uk1 > cijena_uk3) {
		
	popust1=0.68*P;
	popust2=0.33*H;
	popust3=0.50*C;
	
		if(P>=1) {
			cijena_uk1=cijena_uk1-popust1;
		}
		else if(H>=1) {
			cijena_uk1=cijena_uk1-popust2;
		}
		else if(C>=1) {
			cijena_uk1=cijena_uk1-popust3;
		}
	
	if(cijena_uk1<cijena_uk2 && cijena_uk1<cijena_uk3) {
		printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", cijena_uk1);
	}}
		
	

	return 0;
}
