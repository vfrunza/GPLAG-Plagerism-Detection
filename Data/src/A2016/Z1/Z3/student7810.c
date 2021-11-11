#include <stdio.h>

int main() {
	char boja;
	int br=0,brc=0,brs=0,brv=0,brb=0,brp=0;
	float prc,prs,prv,prb,prp;
	printf("Unesite vozila: ");
	do {
		
		scanf("%c" ,&boja);
		if (boja=='C' || boja=='c' || boja=='B' || boja=='b' || boja=='S' || boja=='s' || boja=='V' || boja=='v' || boja=='P' || boja=='p' ) {
			br++;
			if (boja=='C' || boja=='c') brc++;
			else if (boja=='B' || boja=='b') brb++;
			else if (boja=='S' || boja=='s') brs++;
			else if (boja=='V' || boja=='v') brv++;
			else if (boja=='P' || boja=='p') brp++;
			
			
		}  else if ((boja!='k' && boja!='K') || boja==' ')printf("Neispravan unos\n");
	}   while (boja!='k' && boja!='K');
	printf("Ukupno evidentirano %d vozila.\n" ,br);
	if (br==0) {printf("Najpopularnija boja je crna (0.00%%)."); return 0;}
	if (brc>=brb && brc>=brs && brc >= brv && brc>=brp) { prc=(brc*100.00) / br ; printf("Najpopularnija boja je crna (%.2f%%)." ,prc);}
	else if (brb>brc && brb>=brs && brb >= brv && brb>=brp) { prb=(brb*100.00) / br ; printf("Najpopularnija boja je bijela (%.2f%%)." ,prb);}
	else if (brs>brb && brs>brc && brs >= brv && brs>=brp) { prs=(brs*100.00) / br ; printf("Najpopularnija boja je siva (%.2f%%)." ,prs);}
	else if (brv>brb && brv>brs && brv > brc && brv>=brp) { prv=(brv*100.00) / br ; printf("Najpopularnija boja je crvena (%.2f%%)." ,prv);}
	else if (brp>brb && brp>brs && brp > brv && brp>brc) { prp=(brp*100.00) / br ; printf("Najpopularnija boja je plava (%.2f%%)." ,prp);}
	
	
	return 0;
}
