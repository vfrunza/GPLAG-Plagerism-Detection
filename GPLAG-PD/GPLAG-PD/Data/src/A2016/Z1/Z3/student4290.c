#include <stdio.h>

int main() {
	char boja;
	float brojacc=0;
	float brojacb=0;
	float brojacs=0;
	float brojacv=0;
	float brojacp=0;
	float brojac=0;
	float statistika;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&boja);
		if((boja=='c')||(boja=='C')){
			brojacc++;
			brojac++;}
		else if((boja=='b')||(boja=='B')){
			brojacb++;
			brojac++;
		}
		else if((boja=='s')||(boja=='S')){
			brojacs++;
			brojac++;
		}
		else if((boja=='v')||(boja=='V')){
			brojacv++;
			brojac++;
		}
		else if((boja=='p')||(boja=='P')){
			brojacp++;
			brojac++;
		}
		else if(boja!='c' && boja!='C' && boja!='p' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='P' && boja!='b' && boja!='B' && boja!='k' && boja!='K') printf("Neispravan unos\n");
		}while((boja!='k')&&(boja!='K'));
		printf("Ukupno evidentirano %.0f vozila.\n",brojac);
		if((brojacc>brojacp)&&(brojacc>brojacv)&&(brojacc>brojacs)&&(brojacc>brojacb)){
			statistika=(brojacc/brojac)*100;
			printf("Najpopularnija boja je crna (%.2f%%).",statistika);
		}
		else if((brojacp>brojacc)&&(brojacp>brojacv)&&(brojacp>brojacs)&&(brojacp>brojacb)){
			statistika=(brojacp/brojac)*100;
			printf("Najpopularnija boja je plava (%.2f%%).",statistika);
		}
		else if((brojacv>brojacc)&&(brojacv>brojacp)&&(brojacv>brojacs)&&(brojacv>brojacb)){
			statistika=(brojacv/brojac)*100;
			printf("Najpopularnija boja je crvena (%.2f%%).",statistika);
		}
		else if((brojacs>brojacc)&&(brojacs>brojacp)&&(brojacs>brojacv)&&(brojacs>brojacb)){
			statistika=(brojacs/brojac)*100;
			printf("Najpopularnija boja je siva (%.2f%%).",statistika);
		}
		else if((brojacb>brojacc)&&(brojacb>brojacp)&&(brojacb>brojacv)&&(brojacb>brojacs)){
			statistika=(brojacb/brojac)*100;
			printf("Najpopularnija boja je bijela (%.2f%%).",statistika);
		}
	
	return 0;
}
