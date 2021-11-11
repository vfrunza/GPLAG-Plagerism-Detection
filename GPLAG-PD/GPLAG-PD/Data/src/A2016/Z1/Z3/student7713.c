#include <stdio.h>
#include <ctype.h>

int main() {
	
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, max=0;
	char autic;
	float P, uk;
	printf("Unesite vozila: ");
	for(;;) {
		scanf("%c", &autic);
		
		if(autic=='\n') continue;
		if(autic=='k' || autic=='K') break;
		
		else if(autic=='C' || autic=='c') crna++;
		else if(autic=='B' || autic=='b') bijela++;
		else if(autic=='S' || autic=='s') siva++;
		else if(autic=='V' || autic=='v') crvena++;
		else if(autic=='P' || autic=='p') plava++;
		else {
			printf("Neispravan unos\n");
		}
		
	}
	if(crna > max) max=crna;
	if(bijela > max) max=bijela;
	if(siva > max) max=siva;
	if(crvena > max) max=crvena;
	if(plava > max) max=plava;
	
	uk = crna+bijela+siva+crvena+plava;
	printf("Ukupno evidentirano %.f vozila.\n", uk);
	
	P = (max/uk)*100;
	
	if(max==0) printf("Najpopularnija boja je crna (0.00%%).");

	else if(max==crna) printf("Najpopularnija boja je crna (%.2f%%).", P);
	else if(max==bijela) printf("Najpopularnija boja je bijela (%.2f%%).", P);
	else if(max==siva) printf("Najpopularnija boja je siva (%.2f%%).", P);
	else if(max==crvena) printf("Najpopularnija boja je crvena (%.2f%%).", P);
	else if(max==plava) printf("Najpopularnija boja je plava (%.2f%%).", P);

	return 0;
}
