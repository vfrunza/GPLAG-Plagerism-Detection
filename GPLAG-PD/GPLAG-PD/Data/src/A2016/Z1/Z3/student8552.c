#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	int br=0,brC=0,brB=0,brS=0,brV=0,brP=0;
	float proc_C,proc_B,proc_S,proc_V,proc_P;
	printf("Unesite vozila: ");
	scanf("%c",&c);
	if(c=='C' || c=='c') brC++;
	else if(c=='B' || c=='b') brB++;
	else if(c=='S' || c=='s') brS++;		
	else if(c=='V' || c=='v') brV++;
	else if(c=='P' || c=='p') brP++;
	
	while(c!='K' && c!='k') {
		if(c!='C' && c!='c' && c!='B' && c!='b' && c!='S' && c!='s' && c!='V' && c!='v' && c!='P' && c!='p' && c!='K' && c!='k') {
			printf("Neispravan unos\n");
		}
		scanf("%c",&c);
		if(c=='C' || c=='c') brC++;
		else if(c=='B' || c=='b') brB++;
		else if(c=='S' || c=='s') brS++;
		else if(c=='V' || c=='v') brV++;
		else if(c=='P' || c=='p') brP++;
	}
	br=brC+brB+brS+brV+brP;
	printf("Ukupno evidentirano %d vozila.\n",br);
	
	proc_C=(float)brC/br*100;
	proc_B=(float)brB/br*100;
	proc_S=(float)brS/br*100;
	proc_V=(float)brV/br*100;
	proc_P=(float)brP/br*100;
	
	if(br==0)
		printf("Najpopularnija boja je crna (0.00%%).");
	else {
		if(brC>=brB && brC>=brS && brC>=brV && brC>=brP)
			printf("Najpopularnija boja je crna (%.2f%%).",proc_C);
		else if(brB>brC && brB>=brS && brB>=brV && brB>=brP)
			printf("Najpopularnija boja je bijela (%.2f%%).",proc_B);
		else if(brS>brC && brS>brB && brS>=brV && brS>=brP)
			printf("Najpopularnija boja je siva (%.2f%%).",proc_S);
		else if(brV>brC && brV>brB && brV>brS && brV>=brP)
			printf("Najpopularnija boja je crvena (%.2f%%).",proc_V);
		else if(brP>brC && brP>brB && brP>brS && brP>brV)
			printf("Najpopularnija boja je plava (%.2f%%).",proc_P);
	}
	return 0;
}
