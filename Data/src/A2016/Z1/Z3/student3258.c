#include <stdio.h>

int main() {
	float crveni,crni,plavi,sivi,bijeli;
	char slovo;
	int s;
	int ukupno;
	float proc;
	crveni=crni=plavi=sivi=bijeli=0;
	int i;
	printf("Unesite vozila: ");
	for(i=0;i<1;i--){
		scanf("%c",&slovo);
		s=(int) slovo;
		if(s==67 || s==99) crni++;
		else if(s==66 || s==98)bijeli++;
		else if(s==83 || s==115) sivi++;
		else if(s==86 || s==118) crveni++;
		else if(s==80 || s==112) plavi++;
		else if(s==75 || s==107) i=3;
		else{
			printf("Neispravan unos\n"); i--;}
	}
	ukupno=bijeli+crveni+crni+sivi+plavi;
	printf("Ukupno evidentirano %d vozila.",ukupno);
	if(ukupno==0)	printf("\nNajpopularnija boja je crna (0.00%%).");
	else if(crveni>bijeli && crveni>sivi && crveni>=plavi && crveni>crni) {proc=100*crveni/ukupno;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",proc);}
	else if(crni>=crveni && crni>=bijeli && crni>=sivi && crni>=plavi){
		proc=100*crni/ukupno;
		printf("\nNajpopularnija boja je crna (%.2f%%).",proc);
	}
	else if(bijeli>crni && bijeli>=sivi && bijeli>=crveni && bijeli>=plavi){
		proc=100*bijeli/ukupno;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",proc);
	}
	else if(sivi>crni && sivi>bijeli && sivi>=crveni && sivi>=plavi){
		proc=100*sivi/ukupno;
		printf("\nNajpopularnija boja je siva (%.2f%%).",proc);
	}
	else{
		proc=100*plavi/ukupno;
		printf("\nNajpopularnija boja je plava (%.2f%%).",proc);
	}
	return 0;
}
