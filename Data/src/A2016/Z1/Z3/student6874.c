#include <stdio.h>
int najveci(int maxi, int a, int b, int c, int d){
	return maxi>=a && maxi>=b && maxi>=c && maxi>=d;
}
int main() {
	int crna=0,bijela=0,siva=0,crvena=0,plava=0;
	float zbir=0;
	char c;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &c);
		if(c=='C' || c=='c') crna++;
		else if(c=='B' || c=='b') bijela++;
		else if(c=='S' || c=='s') siva++;
		else if(c=='V' || c=='v') crvena++;
		else if(c=='P' || c=='p') plava++;
		else if(c!='K' && c!='k') printf("Neispravan unos\n");
	}while(c!='k' && c!='K');
	zbir=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n", crna+bijela+siva+crvena+plava);
	if(crna+bijela+siva+crvena+plava==0) printf("Najpopularnija boja je crna (%.2f%%).", zbir);
	else if(najveci(crna,bijela,siva,crvena,plava)!=0) printf("Najpopularnija boja je crna (%.2f%%).", crna/zbir*100);
	else if(najveci(bijela,crna,siva,crvena,plava)!=0) printf("Najpopularnija boja je bijela (%.2f%%).",bijela/zbir*100);
	else if(najveci(siva,crna,bijela,crvena,plava)!=0) printf("Najpopularnija boja je siva (%.2f%%).", siva/zbir*100);
	else if(najveci(crvena,crna,bijela,siva,plava)!=0) printf("Najpopularnija boja je crvena (%.2f%%).", crvena/zbir*100);
	else if(najveci(plava,crna,bijela,siva,crvena)!=0) printf("Najpopularnija boja je plava (%.2f%%).", plava/zbir*100);
	return 0;
}
