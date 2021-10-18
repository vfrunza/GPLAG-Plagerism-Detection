#include <stdio.h>

int main() {
	
	int br = 0, i;
	int brC = 0, brB = 0, brS = 0, brV = 0, brP = 0;
	float c, b, s, v, p, max;
	char unos;
	printf("Unesite vozila: ");
	
	do {
		scanf("%c", &unos);
		if(unos == 'c' || unos == 'C') brC++;
		else if(unos == 'b' || unos == 'B') brB++;
		else if(unos == 's' || unos == 'S') brS++;
		else if(unos == 'v' || unos == 'V') brV++;
		else if(unos == 'p' || unos == 'P') brP++;
		else if(unos == 'k' || unos == 'K') break;
		else  {
			printf("Neispravan unos\n");
			continue;
		}
		br++;
	} while(unos != 'k' || unos != 'K');
	
	printf("Ukupno evidentirano %d vozila.\n", br);
	
	c = 100.0 * brC / br;
	b = 100.0 * brB / br;
	s = 100.0 * brS / br;
	v = 100.0 * brV / br;
	p = 100.0 * brP / br;
	
	if(br == 0) printf("Najpopularnija boja je crna (0.00%).");
	
	max = c;
	for(i = 0; i < 4; i++) {
		if(b > max) max = b;
		else if(s > max) max = s;
		else if(v > max) max = v;
		else if(p > max) max = p;
	}
	/*printf("%f %f %f %f %f %f\n", c, b, s, v, p, max);
	printf("%d %d %d %d %d", brC, brB, brS, brV, brP);
	CCbcsVSsCsPk*/
	if(max - c < 0.0001) printf("Najpopularnija boja je crna (%.2f%%).", c);
	else if(max - b < 0.0001) printf("Najpopularnija boja je bijela (%.2f%%).", b);
    else if(max - s < 0.0001) printf("Najpopularnija boja je siva (%.2f%%).", s);
    else if(max - v < 0.0001) printf("Najpopularnija boja je crvena (%.2f%%).", v);
    else if(max - p < 0.0001) printf("Najpopularnija boja je plava (%.2f%%).", p);
	
	return 0;
}
