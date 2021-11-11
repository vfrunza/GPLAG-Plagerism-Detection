#include <stdio.h>
#include <math.h>
int main() {
	char x='0';
	const double Eps=1e-10;
	double crna=0,bijela=0,siva=0,crvena=0,plava=0, ukupno=0,pr=0;
	printf("Unesite vozila: ");
	for(;;){
		scanf("%c",&x);
		if(x == 'C' || x == 'c'){
			crna++;
		}
		if(x=='B' || x=='b'){
			bijela++;
		}
		if(x=='S' || x=='s'){
			siva++;
		}
		if(x=='V' || x=='v'){
			crvena++;
		}
		if(x=='P' || x=='p'){
			plava++;
		}
		if(x=='K' || x=='k'){
			ukupno=crna+bijela+siva+crvena+plava;
			printf("Ukupno evidentirano %.0f vozila.\n",ukupno);
			if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
				if(fabs(ukupno-0)<=Eps*(fabs(ukupno)-fabs(0))){
					printf("Najpopularnija boja je crna (0.00%%).");
				}
				else{
				pr=crna/ukupno*100;
				printf("Najpopularnija boja je crna (%.2f%%).",pr);
				}
			}
			else if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava){
				pr=bijela/ukupno*100;
				printf("Najpopularnija boja je bijela (%.2f%%).",pr);
			}
			else if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
				pr=siva/ukupno*100;
				printf("Najpopularnija boja je siva (%.2f%%).",pr);
			}
			else if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava){
				pr=crvena/ukupno*100;
				printf("Najpopularnija boja je crvena (%.2f%%).",pr);
			}
			else{
				pr=plava/ukupno*100;
				printf("Najpopularnija boja je plava (%.2f%%).",pr);
			}
			return 0;
		}
		if(x!='c' && x!='C' && x!='B' && x!='b' && x!='S' && x!='s' && x!='v' && x!='V' && x!='p' && x!='P' && x!='K' && x!='k'){
			printf("Neispravan unos\n");
		}
	}
	return 0;
}
