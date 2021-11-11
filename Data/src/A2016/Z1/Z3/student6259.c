#include <stdio.h>

int main() {
	int bra=0, brc=0, brb=0, brs=0, brv=0, brp=0, max=0;
	char x, boja=0;
	
	printf("Unesite vozila: ");
	
	for(;;){
		scanf("%c", &x);
		/*c==C ...*/
		if(x>='a' && x<='z') x-='a'-'A';
		if(x!='C' && x!='B' && x!='S' && x!='V' && x!='P' && x!='K') printf("Neispravan unos\n");
		if(x=='C'){
		brc++; bra++;
			if(brc>max) {
			max=brc; boja = 'C';
			}
		}
		else if(x=='B') {
			brb++; bra++;
			if(brb>max) {
				max=brb; boja = 'B';
			}
		}
		else if(x=='S') {
			brs++; bra++;
			if(brs>max) {
				max=brs; boja ='S';
			}
		}
		else if(x=='V') {
			brv++; bra++;
			if(brv>max) {
				max=brv; boja='V';
			}
		}
		else if(x=='P') {
			brp++; bra++;
			if(brp>max) {
				max=brp; boja='P';
			}
		}
		else if(x=='K') break;
		
	}
	

	printf("Ukupno evidentirano %d vozila.\n", bra);
		if(boja=='C') {
			printf("Najpopularnija boja je crna (%.2f%%).", ((brc+0.0)/bra)*100);
		}
		else if(boja==0) {
			printf("Najpopularnija boja je crna (%.2f%%).", bra+0.0);
		}
		else if(boja=='B') {
			printf("Najpopularnija boja je bijela (%.2f%%).", ((brb+0.0)/bra)*100);
		}
		else if(boja=='S') {
			printf("Najpopularnija boja je siva (%.2f%%).", ((brs+0.0)/bra)*100);
		}
		else if(boja=='V') {
			printf("Najpopularnija boja je crvena (%.2f%%).", ((brv+0.0)/bra)*100);
		}
		else if(boja=='P') {
			printf("Najpopularnija boja je plava (%.2f%%).", ((brp+0.0)/bra)*100);
		}

	return 0;
}
