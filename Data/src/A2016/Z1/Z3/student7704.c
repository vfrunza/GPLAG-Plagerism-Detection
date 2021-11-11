#include <stdio.h>

int main() {
	int C,B,S,V,P, ukupno, max;
	double procenat;
	char boja;
	C = 0;
	B = 0;
	S = 0;
	V = 0;
	P = 0;
	max = 0;
	printf("Unesite vozila: ");
	do {
		scanf("%c", &boja);
    if (boja == 'c' || boja == 'C') {
			C++;
			if (C > max) {
				max = C;
			}
		} else if (boja == 'b' || boja == 'B') {
			B++;
			if (B > max) {
				max = B;
				
			}
		} else if (boja == 's' || boja == 'S') {
			S++;
			if (S > max) {
				max = S;
				
			}
		} else if (boja == 'v' || boja == 'V') {
			V++;
			if (V > max) {
				max = V;
				
			}
		} else if (boja == 'p' || boja == 'P') {
			P++;
			if (P > max) {
				max = P;
			}
		} else if (!(boja == 'k' || boja == 'K')) {
			printf("Neispravan unos\n");
	    	} 
		} while(!(boja == 'k' || boja == 'K'));
		ukupno = C + V + B + P + S;
		printf("Ukupno evidentirano %d vozila.\n", ukupno);
		if (ukupno == 0) {
			procenat = 0;
		} else {
			procenat = (max * 100.)/ukupno;
		}
		if (max == C) {
			printf("Najpopularnija boja je crna (%.2f%%).", procenat);
		} else if (max == B) {
			printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
		} else if (max == S) {
			printf("Najpopularnija boja je siva (%.2f%%).", procenat);
		} else if (max == V) {
			printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
		} else if (max == P) {
			printf("Najpopularnija boja je plava (%.2f%%).", procenat);
			
		}
	return 0;
}
