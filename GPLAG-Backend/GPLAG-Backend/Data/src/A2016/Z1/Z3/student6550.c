#include <stdio.h>

int main() {

	int crna=0, bijela=0, siva=0, crvena=0, plava=0, max=-1;
	float ukupno;
	char boja;
	printf("Unesite vozila: ");
	scanf("%c",&boja);
	while(1){
		if(boja=='C' || boja=='c') crna++;
		else if(boja=='B' || boja=='b') bijela++;
		else if(boja=='S' || boja=='s') siva++;
		else if(boja=='V' || boja=='v') crvena++;
		else if(boja=='P' || boja=='p') plava++;
		else if(boja=='K' || boja=='k') break;
		else printf("Neispravan unos\n");
		scanf("%c",&boja);
	}
	ukupno=crna+bijela+plava+crvena+siva;

	if(crna>max) max=crna;
	if(bijela>max) max=bijela;
	if(siva>max) max=siva;
	if(crvena>max) max=crvena;
	if(plava>max) max=plava;

	printf("Ukupno evidentirano %.0f vozila.\n", ukupno);
	if(max==crna && ukupno!=0) printf("Najpopularnija boja je crna (%.2f%%).",max*100/ukupno);
	else if(max==bijela && ukupno!=0) printf("Najpopularnija boja je bijela (%.2f%%).",max*100/ukupno);
	else if(max==siva && ukupno!=0) printf("Najpopularnija boja je siva (%.2f%%).",max*100/ukupno);
	else if(max==crvena && ukupno!=0) printf("Najpopularnija boja je crvena (%.2f%%).",max*100/ukupno);
	else if(max==plava && ukupno!=0) printf("Najpopularnija boja je plava (%.2f%%).",max*100/ukupno);
    else if(ukupno==0) printf("Najpopularnija boja je crna (0.00%%).");
	return 0;
}
