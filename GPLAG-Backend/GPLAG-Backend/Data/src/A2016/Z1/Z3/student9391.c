#include <stdio.h>

int main() {
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, br=0;
	float PROScrna=0.0, PROSbijela=0.0, PROSsiva=0.0, PROScrvena=0.0, PROSplava=0.0;
	char c;
		printf("Unesite vozila: ");
	while(1) {
		scanf("%c", &c);
		br++;
		if (c=='k' || c=='K') 
		{
			br--;
			break;
		}
 	    else if(c=='c' || c=='C') crna++;
		else if(c=='b' || c=='B') bijela++;
		else if(c=='s' || c=='S') siva++;
		else if(c=='v' || c=='V') crvena++;
		else if(c=='p' || c=='P') plava++;
		else
		{
			printf ("Neispravan unos\n");
			br--;
		}
	} 
	printf("Ukupno evidentirano %d vozila.\n", br);
	if (br==0) goto dalje;
	PROScrna=(100.0*crna/br);
	PROSbijela=(100.0*bijela/br);
	PROSsiva=(100.0*siva/br);
	PROScrvena=(100.0*crvena/br);
	PROSplava=(100.0*plava/br);
	dalje:
	if(PROScrna>=PROSbijela && PROScrna>=PROSsiva && PROScrna>=PROScrvena && PROScrna>=PROSplava) {
		printf("Najpopularnija boja je crna (%.2f%%).", PROScrna);
	} else if (PROSbijela>PROScrna && PROSbijela>=PROSsiva && PROSbijela>=PROScrvena && PROSbijela>=PROSplava) {
		printf("Najpopularnija boja je bijela (%.2f%%).",PROSbijela);
	} else if(PROSsiva>PROScrna && PROSsiva>PROSbijela && PROSsiva>=PROScrvena && PROSsiva>=PROSplava) {
		printf("Najpopularnija boja je siva (%.2f%%).", PROSsiva);
	} else if(PROScrvena>PROScrna && PROScrvena>PROSbijela && PROScrvena>PROSsiva && PROScrvena>=PROSplava) {
		printf("Najpopularnija boja je crvena (%.2f%%).", PROScrvena);
	} else if(PROSplava>PROScrna && PROSplava>PROSbijela && PROSplava>PROSsiva && PROSplava>PROScrvena) {
		printf("Najpopularnija boja je plava (%.2f%%).",PROSplava);
	}
	
	/*printf("Zadaća 1, Zadatak 3");*/
	return 0;
}
