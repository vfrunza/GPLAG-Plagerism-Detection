#include <stdio.h>

int main() {
	
	char boja;
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, ukupno=0;
	float c, b, s, v, p;
	
	printf("Unesite vozila: ");
	
	do {
		
		scanf("%c", &boja);
		
		if (boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K'){
			printf("Neispravan unos\n");
			
		} else if (boja=='k' || boja=='K'){
			break;
		} else {
			if (boja=='c' || boja=='C'){
			crna++;
			ukupno++;
		} else if (boja=='b' || boja=='B'){
			bijela++;
			ukupno++;
		} else if (boja=='s' || boja=='S'){
			siva++;
			ukupno++;	
		} else if (boja=='v' || boja=='V'){
			crvena++;
			ukupno++;	
		} else if (boja=='p' || boja=='P'){
			plava++;
			ukupno++;	
		}
		}
	
		
	} while (boja != 'k' && boja != 'K');

		
	printf("Ukupno evidentirano %d vozila.", ukupno);
	
	if (ukupno==0){
		printf("\nNajpopularnija boja je crna (0.00%%).");
		return 0;
	}
	
	c = ((float) crna/ukupno)*100;
	b = ((float) bijela/ukupno)*100;
	s = ((float) siva/ukupno)*100;
	v = ((float) crvena/ukupno)*100;
	p = ((float) plava/ukupno)*100;
	
	if (crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
		
		printf("\nNajpopularnija boja je crna (%.2f%%).", c);
		
	} else if (bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava){
		
		printf("\nNajpopularnija boja je bijela (%.2f%%).", b);
		
	} else if (siva>crna && siva>bijela && siva>=crvena && siva>=plava){
	
		printf("\nNajpopularnija boja je siva (%.2f%%).", s);
		
	} else if (crvena>crna && crvena>bijela && crvena>siva && crvena>=plava){
		
		printf("\nNajpopularnija boja je crvena (%.2f%%).", v);
		
	} else if (plava>crna && plava>bijela && plava>siva && plava>crvena){
		
		printf("\nNajpopularnija boja je plava (%.2f%%).", p);
	}
	
	
	return 0;
}
