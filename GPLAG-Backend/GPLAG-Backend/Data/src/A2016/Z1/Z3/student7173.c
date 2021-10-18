#include <stdio.h>

int main() {
	int C, B, S, V, P, max, count;
	float percentage;
	char ch;
	C = B = S = V = P = 0;

	printf("Unesite vozila: ");
	count = 0;
	do {
		scanf("%c", &ch);
		count += 1;
		if (ch == 'C' || ch == 'c') {
			C +=1;
		} else if (ch == 'B' || ch == 'b') {
			B +=1;
		} else if (ch == 'S' || ch == 's') {
			S +=1;
		} else if (ch == 'V' || ch == 'v') {
			V +=1;
		} else if (ch == 'P' || ch == 'p') {
			P +=1;
		} else if (ch == '\n' || ch == 'K' || ch == 'k') {
			count -= 1;
		} else {
			printf("Neispravan unos\n");
			count -= 1;
		}
	} while (ch != 'K' && ch != 'k');
	
	printf("Ukupno evidentirano %d vozila.\n", count);
	if (count == 0) {printf("Najpopularnija boja je crna (0.00%%)."); return 0;}
	
	max = C;
	if (B > max) {
		max = B;
	}
	if (S > max) {
		max = S;
	}
	if (V > max) {
		max = V;
	}
	if (P > max) {
		max = P;
	}
	if (S > max) {
		max = S;
	}
	
	percentage = ((double)max) / count * 100;
	
	if (C == max) {
		printf("Najpopularnija boja je crna (%.2f%%).", percentage);
		return 0;
	} else if (B == max) {
		printf("Najpopularnija boja je bijela (%.2f%%).", percentage);
	} else if (S == max) {
		printf("Najpopularnija boja je siva (%.2f%%).", percentage);
	} else if (V == max) {
		printf("Najpopularnija boja je crvena (%.2f%%).", percentage);
	} else {
		printf("Najpopularnija boja je plava (%.2f%%).", percentage);
	}
	 

	return 0;
}
