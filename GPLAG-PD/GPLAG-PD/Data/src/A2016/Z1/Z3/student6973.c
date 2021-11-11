#include <stdio.h>

int main() {
	char slovo;
	int br = 0, brC = 0, brB = 0, brS = 0, brV = 0, brP = 0;
	printf("Unesite vozila: ");
	do {
		scanf(" %c", &slovo);
			if(slovo == 'C' || slovo == 'c' || slovo == 'B' || slovo == 'b' || slovo == 'S' || slovo == 's' ||
			slovo == 'V' || slovo == 'v' || slovo == 'P' || slovo == 'p') br++;
			if(slovo != 'C' && slovo != 'c' && slovo != 'B' && slovo != 'b' && slovo != 'S' && slovo != 's' &&
			slovo != 'V' && slovo != 'v' && slovo != 'P' && slovo != 'p' && slovo != 'K' && slovo != 'k' && slovo != ' ' ) printf("Neispravan unos\n");
			if(slovo == 'C' || slovo == 'c') brC++;
			else if(slovo == 'B' || slovo == 'b') brB++;
			else if(slovo == 'S' || slovo == 's') brS++;
			else if(slovo == 'V' || slovo == 'v') brV++;
			else if(slovo == 'P' || slovo == 'p') brP++;
	} while(slovo != 75 && slovo != 107);
	printf("Ukupno evidentirano %d vozila.\n",br);
	
	/*printf("\nUkupno crnih %d vozila.",brC);
	printf("\nUkupno bijelih %d vozila.",brB);
	printf("\nUkupno sivih %d vozila.",brS);
	printf("\nUkupno crvenih %d vozila.",brV);
	printf("\nUkupno plavih %d vozila.",brP);*/
	if(brC == 0 && brB == 0 && brS == 0 && brV == 0 && brP == 0) printf("Najpopularnija boja je crna (0.00%%).");
	else if(brC > brB && brC > brS && brC > brV && brC > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brB > brC && brB > brS && brB > brV && brB > brP) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brS > brC && brS > brB && brS > brV && brS > brP) printf("Najpopularnija boja je siva (%.2f%%).", ((float)brS/br) * 100);
	else if(brV > brC && brV > brS && brV > brB && brV > brP) printf("Najpopularnija boja je crvena (%.2f%%).", ((float)brV/br) * 100);
	else if(brP > brC && brP > brS && brP > brV && brP > brB) printf("Najpopularnija boja je plava (%.2f%%).", ((float)brP/br) * 100);
	else if(brC == brB && brB == brS && brS == brV && brV == brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brB && brB > brS && brB > brV && brB > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brB && brB == brS && brS > brV && brS > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brB && brB == brS && brS == brV && brV > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brS && brS > brB && brS > brV && brS > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brV && brV > brB && brV > brS && brV > brP) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brC == brP && brP > brB && brP > brV && brP > brS) printf("Najpopularnija boja je crna (%.2f%%).", ((float)brC/br) * 100);
	else if(brB == brS && brS > brC && brS > brV && brS > brP) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brB == brV && brV > brC && brV > brS && brV > brP) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brB == brP && brP > brC && brP > brV && brP > brS) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brB == brS && brS == brV && brV > brC && brV > brP) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brB == brS && brS == brV && brV == brP && brP > brC) printf("Najpopularnija boja je bijela (%.2f%%).", ((float)brB/br) * 100);
	else if(brS == brV && brV > brC && brV > brB && brV > brP) printf("Najpopularnija boja je siva (%.2f%%).", ((float)brS/br) * 100);
	else if(brS == brP && brP > brC && brP > brB && brP > brV) printf("Najpopularnija boja je siva (%.2f%%).", ((float)brS/br) * 100);
	else if(brS == brV && brV == brP && brP > brC && brP > brB) printf("Najpopularnija boja je siva (%.2f%%).", ((float)brS/br) * 100);
	else if(brV == brP && brP > brC && brP > brB && brP > brS) printf("Najpopularnija boja je crvena (%.2f%%).", ((float)brV/br) * 100);


	
				
	return 0;
}
