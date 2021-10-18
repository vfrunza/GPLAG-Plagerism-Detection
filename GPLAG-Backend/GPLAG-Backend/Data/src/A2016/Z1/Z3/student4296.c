#include <stdio.h>
#include <math.h>
#define epsilon 0.00001
int main() {
	char A;
	int sumaC,sumaB,sumaS,sumaV,sumaP,sumaA;
	float PC,PB,PS,PV,PP;
	sumaA=0;
	sumaB=0;
	sumaC=0;
	sumaS=0;
	sumaV=0;
	sumaP=0;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&A);
		if (A=='C' || A=='c')
			sumaC=sumaC+1;
		else if (A=='B'||A=='b')
			sumaB=sumaB+1;
		else if(A=='S'|| A=='s')
			sumaS=sumaS+1;
		else if(A=='V' || A=='v')
			sumaV=sumaV+1;
		else if(A=='P' || A=='p')
			sumaP=sumaP+1;
		else if(A!='C' && A!='c' && A!='B' && A!='b' && A!='S' && A!='s' && A!='V' && A!='v' && A!='P' && A!='p' && A!='K' && A!='k')
		printf("Neispravan unos\n");
		
	}while (A!='k' && A!='K');
	sumaA=sumaC+sumaB+sumaS+sumaV+sumaP;
	printf("Ukupno evidentirano %d vozila.",sumaA);
	if (sumaA==0)
		printf("\nNajpopularnija boja je crna (0.00%%).");
	else{
		PC=(float)(sumaC*100)/sumaA;
		PB=(float)(sumaB*100)/sumaA;
		PS=(float)(sumaS*100)/sumaA;
		PV=(float)(sumaV*100)/sumaA;
		PP=(float)(sumaP*100)/sumaA;
		if((fabs(PC-PB)<epsilon || PC>PB) && (fabs(PC-PS)<epsilon || PC>PS) && (fabs(PC-PV)<epsilon || PC>PV) && (fabs(PC-PP)<epsilon || PC>PP))
			printf("\nNajpopularnija boja je crna (%.2f%%).",PC);
		else if(PB>PC && (fabs(PB-PS)<epsilon || PB>PS) && (fabs(PB-PV)<epsilon || PB>PV) && (fabs(PB-PP)<epsilon || PB>PP))
			printf("\nNajpopularnija boja je bijela (%.2f%%).",PB);
		else if(PS>PC && PS>PB && (fabs(PS-PV)<epsilon || PS>PV) && (fabs(PS-PP)<epsilon || PS>PP))
			printf("\nNajpopularnija boja je siva (%.2f%%).",PS);
		else if(PV>PC && PV>PB && PV>PS && (fabs(PV-PP)<epsilon || PV>PP))
			printf("\nNajpopularnija boja je crvena (%.2f%%).",PV);
		else printf("\nNajpopularnija boja je plava (%.2f%%).",PP);
 	}
	return 0;
}
