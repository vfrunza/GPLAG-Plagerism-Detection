#include <stdio.h>
#include <math.h>

int main() {
	double brc=0, brb=0, brs=0, brv=0, brp=0, brauta=0;
	double proc1=0, proc2=0, proc3=0, proc4=0, proc5=0;
	char z;
	printf("Unesite vozila: ");
	for(;;){
		scanf("%c", &z);
		if(z=='C' || z=='c'){
			brc++;
			brauta++;
		} else if(z=='B' || z=='b'){
			brb++;
			brauta++;
		} else if(z=='S' || z=='s'){
			brs++;
			brauta++;
		} else if(z=='V' || z=='v'){
			brv++;
			brauta++;
		} else if(z=='P' || z=='p'){
			brp++;
			brauta++;
		} else if(z=='K' || z=='k'){
			break;
		} else {
			printf("Neispravan unos\n");
		}
	}
	printf("Ukupno evidentirano %.lf vozila.", brauta);
	
	if(brc>=brb && brc>=brs && brc>=brv && brc>=brp){
		if(brc==0)
		printf("\nNajpopularnija boja je crna (0.00%%).");
		else {
		proc1=(brc/brauta)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", proc1);
	}
	}
	if(brb>brc && brb>=brs && brb>=brv && brb>=brp){
		proc2=(brb/brauta)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", proc2);
	}
	if(brs>brc && brs>brb && brs>=brv && brs>=brp){
		proc3=(brs/brauta)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).", proc3);
	}
	if(brv>brc && brv>brb && brv>brs && brv>=brp){
		proc4=(brv/brauta)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).", proc4);
	}
	if(brp>brc && brp>brb && brp>brs && brp>brv){
		proc5=(brp/brauta)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).", proc5);
	}
	return 0;
}
