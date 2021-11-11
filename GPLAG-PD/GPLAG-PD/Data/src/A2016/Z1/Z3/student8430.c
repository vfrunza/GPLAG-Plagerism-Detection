#include <stdio.h>

int main() {
	char n;
	int crnib=0, bijelib=0, sivib=0, crvenib=0, plavib=0, ukupno=0, popular=0;
	float posto=0;
	printf("Unesite vozila: ");
	while(2) {
		scanf("%c", &n);
		if(n=='c' || n=='C') crnib++;
		else if(n=='b' || n=='B') bijelib++;
		else if(n=='s' || n=='S') sivib++;
		else if(n=='v' || n=='V') crvenib++;
		else if(n=='p' || n=='P') plavib++;
		else if(n=='k' || n=='K') break;
		else if(n == '\n') continue;
		else printf("Neispravan unos\n");
	}
	ukupno=crnib+bijelib+sivib+crvenib+plavib;
	printf("Ukupno evidentirano %d vozila.", ukupno);
	if(crnib>=bijelib && crnib>=sivib && crnib>=crvenib && crnib>=plavib) popular=crnib;
	else if(bijelib>=crnib && bijelib>=sivib && bijelib>=crvenib && bijelib>=plavib) popular=bijelib;
	else if(sivib>=crnib && sivib>=bijelib && sivib>=crvenib && sivib>=plavib) popular=sivib;
	else if(crvenib>=crnib && crvenib>=bijelib && crvenib>=sivib && crvenib>=plavib) popular=crvenib;
	else popular=plavib;
	if(ukupno == 0) posto = 0;
	else posto=(float)popular/ukupno*100;
	if(crnib==popular) printf("\nNajpopularnija boja je crna (%.2f%%).", posto);
	else if(bijelib==popular) printf("\nNajpopularnija boja je bijela (%.2f%%).", posto);
	else if(sivib==popular) printf("\nNajpopularnija boja je siva (%.2f%%).", posto);
	else if(crvenib==popular) printf("\nNajpopularnija boja je crvena (%.2f%%).", posto);
	else printf("\nNajpopularnija boja je plava (%.2f%%).", posto);
	
	return 0;
}
