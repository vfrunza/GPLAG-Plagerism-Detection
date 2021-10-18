#include <stdio.h>

int main() {
	double brc, brb, brs, brv, brp;
	brc=brb=brs=brv=brp=0;
	printf ("Unesite vozila: ");
	char c;
	for (;;){
		scanf ("%c", &c);
		if(c=='c'||c=='C')
		brc++;
		else if (c=='b'|| c=='B')
		brb++;
		else if (c=='s'|| c=='S')
		brs++;
		else if (c=='v'|| c=='V')
		brv++;
		else if (c=='p'|| c=='P')
		brp++;
		else if (c=='k'|| c=='K')
		break;
		else{
			printf ("Neispravan unos\n");
		}
		
	}
	double suma=brc+brb+brs+brv+brp;
	printf ("Ukupno evidentirano %g vozila.\n", suma);
	double maksimum=brc;
	if (brb>maksimum){
		maksimum=brb;
		
	}
	if (brs>maksimum){
		maksimum=brs;
	}
	if (brv>maksimum){
		maksimum=brv;
	}
	if (brp>maksimum){
		maksimum=brp;
	}
	if (suma==0){
		printf ("Najpopularnija boja je crna (0.00%%).\n");
	}
	else if (maksimum==brc){
		printf ("Najpopularnija boja je crna (%.2f%%).\n", brc/suma*100);
		
	}
	else if (maksimum==brb){
		printf ("Najpopularnija boja je bijela (%.2f%%).\n", brb/suma*100);
	}
	else if (maksimum==brs){
		printf ("Najpopularnija boja je siva (%.2f%%).\n", brs/suma*100);
	}
	else if (maksimum==brv){
		printf ("Najpopularnija boja je crvena (%.2f%%).\n", brv/suma*100);
	}
	else if (maksimum==brp){
		printf ("Najpopularnija boja je plava (%.2f%%).\n", brp/suma*100);
	}
	
	
	return 0;
}
