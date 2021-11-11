#include <stdio.h>

int main() {
	int brojac1=0,brojac2=0,brojac3=0,brojac4=0,brojac5=0,i=0;
	float prc;
	char a;
	printf("Unesite vozila: ");
	
	while(2) {
	
	scanf("%c", &a);
	if(a=='K') break;
	if(a!='C' && a!='c' && a!='B' && a!='b' && a!='P' && a!='p' && a!='S' && a!='s' && a!='V' && a!='v' && a!='K' && a!='k') {
	printf("Neispravan unos\n"); continue ;
	}
	
	if(a=='C' || a=='c') brojac1++ ;
	else if (a=='P' || a=='p') brojac5++ ;
	else if(a=='B' || a=='b') brojac2++;
	else if(a=='S' || a=='s') brojac3++;
	else if(a=='V' || a=='v') brojac4++;
	else if(a=='K' || a=='k') break ;
	
	i++;
	
	}
	
	printf("Ukupno evidentirano %d vozila.\n", i);
	
	if(brojac1>=brojac2 && brojac1>=brojac3 && brojac1>=brojac4 && brojac1>=brojac5) {
	prc=brojac1*100./i ;
	if(i!=0)
	printf("Najpopularnija boja je crna (%.2f%%).", prc);
	else if (i==0) printf("Najpopularnija boja je crna (0.00%%).");
		
	}
	
	else if(brojac2>brojac1 && brojac2>=brojac3 && brojac2>=brojac4 && brojac2>=brojac5) {
	prc=brojac2*100./i ;
	printf("Najpopularnija boja je bijela (%.2f%%).", prc);
	}
	
	else if(brojac3>brojac1 && brojac3>brojac2 && brojac3>=brojac4 && brojac3>=brojac5 ) {
	prc=brojac3*100./i;
	printf("Najpopularnija boja je siva (%.2f%%).", prc);
	}
	
	else if(brojac4>brojac1 && brojac4>brojac2 && brojac4>brojac3 && brojac4>=brojac5) {
	prc=brojac4*100./i;
	printf("Najpopularnija boja je crvena (%.2f%%).", prc);
	}
	
	else if(brojac5>brojac1 && brojac5>brojac2 && brojac5>brojac3 && brojac5>brojac4) {
	prc=brojac5*100./i;
	printf("Najpopularnija boja je plava (%.2f%%).", prc);
	}
	
	return 0;
}
