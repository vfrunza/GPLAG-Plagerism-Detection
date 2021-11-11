#include <stdio.h>
int main() {
	char c;
	int crna, bijela, siva, crvena, plava;
	crna=bijela=siva=crvena=plava=0;
	printf("Unesite vozila: ");
	int done=0;
	while(!done) {
		scanf("%c", &c);
		switch(c) {
			case'C':
			case 'c':
			crna++;
			break;
			case 'B' :
			case 'b' :
			bijela++;
			break;
			case 'S' :
			case 's':
			siva++;
			break;
			case 'V' :
			case 'v' :
			crvena++;
			break;
			case 'P':
			case 'p' :
			plava++;
			break;
			case 'K' :
			case 'k' :
			done=1;
			break;
			default: 
			printf("Neispravan unos\n");
			break; 
		}
	}
	int ukupno=crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	int max=crna;
	if(bijela>max) max=bijela;
	if(siva>max) max=siva;
	if(crvena>max) max=crvena;
	if(plava>max) max=plava;
	float postotak=max*100.0/ukupno;
	if(postotak!=postotak) printf("Najpopularnija boja je crna (0.00%).");
	else {
	printf("Najpopularnija boja je");
	if(max==crna) printf(" crna");
	else if(max==bijela) printf(" bijela");
	else if(max==siva) printf(" siva");
	else if(max==crvena) printf(" crvena");
	else printf(" plava");
	printf(" (%.2f%%).\n", postotak); }
	return 0;
}
