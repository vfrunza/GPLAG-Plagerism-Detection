#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0;
	int ukupno=0;
	double proc=0;
	char znak='a';
	printf("Unesite vozila: ");
	for(;;) {
		scanf("%c",&znak);
		if(znak=='c'||znak=='C') 
			crna++;
		else if (znak=='b'||znak=='B')
			bijela++;
		else if(znak=='s'||znak=='S')
			siva++;
		else if(znak=='v'||znak=='V')
			crvena++;
		else if(znak=='p'||znak=='P')
			plava++;
		else if(znak=='k'||znak=='K')
			break;
		else 
			printf("Neispravan unos\n");
	}
	ukupno=crna+bijela+siva+crvena+plava;
	
	printf("Ukupno evidentirano %d vozila.\n",ukupno);
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava) {
		proc=((double)crna/ukupno)*100;
		if(ukupno==0)
		proc=0;
		printf("Najpopularnija boja je crna (%.2lf%%).",proc);
		return 0;
	}
	if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava) {
		proc=((double)bijela/ukupno)*100;
		printf("Najpopularnija boja je bijela (%.2lf%%).",proc);
		return 0;
	}
	if(siva>=crna && siva>=bijela && siva>= crvena && siva>=plava) {
		proc=((double)siva/ukupno)*100;
		printf("Najpopularnija boja je siva (%.2lf%%).",proc);
		return 0;
	}
	if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava) {
		proc=((double)crvena/ukupno)*100;
		printf("Najpopularnija boja je crvena (%.2lf%%).",proc);
		return 0;
	}
	if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena) {
		proc=((double)plava/ukupno)*100;
		printf("Najpopularnija boja je plava (%.2lf%%).",proc);
		return 0;
	}
	return 0;
}
