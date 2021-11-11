#include <stdio.h>

int main() {
	int br=0;
	float brc=0, brb=0, brv=0, brs=0, brp=0, proc;
    char boja=0;
    printf("Unesite vozila: ");
	while (boja!='k' && boja!='K'){
	    scanf("%c", &boja);
	  if(boja!='c' && boja!='C' && boja!='v' && boja!='V' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='p' && boja!='P' && boja!='k' && boja!='K'){
	  	printf("Neispravan unos\n");
	  }  
	    if ((boja=='c') || (boja=='C')) {brc++; br++;}
	else if ((boja=='v') || (boja=='V')) {brv++; br++;}
	else if ((boja=='b') || (boja=='B')) {brb++; br++;}
	else if ((boja=='s') ||(boja=='S')) {brs++; br++;}
	else if ((boja=='p') || (boja=='P')) {brp++; br++;}
	}

	printf("Ukupno evidentirano %d vozila.", br);
	
	if ((brc>=brv) && (brc>=brb) && (brc>=brs) && (brc>=brp) && (br!=0)){
		proc=(brc/br)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", proc);
	}
	else if ((brv>brc) && (brv>brb) && (brv>brs) && (brv>=brp) && (br!=0)){
		proc=(brv/br)*100;
			printf("\nNajpopularnija boja je crvena (%.2f%%).", proc);
	}
	else if((brb>brc) && (brb>=brv) && (brb>=brs) && (brb>=brp) && (br!=0)){
		proc=(brb/br)*100;
			printf("\nNajpopularnija boja je bijela (%.2f%%).", proc);
	}
	else if((brs>brc) && (brs>=brv) && (brs>brb) && (brs>=brp) && (br!=0)){
		proc=(brs/br)*100;
			printf("\nNajpopularnija boja je siva (%.2f%%).", proc);
	}
	else if ((brp>brv) && (brp>brc) && (brp>brb) && (brp>brs) && (br!=0)){
		proc=(brp/br)*100;
			printf("\nNajpopularnija boja je plava (%.2f%%).", proc);
	
	}

	else if (br==0) {
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	return 0;
}
