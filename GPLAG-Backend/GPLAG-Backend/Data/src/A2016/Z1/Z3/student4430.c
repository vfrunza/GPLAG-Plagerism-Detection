#include <stdio.h>

int main() {
	
	int crna=0, bijela=0, siva=0, crvena=0, plava=0, brojac=0, kraj=0;
	float udio_crne, udio_bijele, udio_sive, udio_crvene, udio_plave;
	char c;
	printf("Unesite vozila: ");
	 
	 
	labela:
	for(;;){
		scanf("%c", &c);
		if(c=='k' || c=='K'){
			kraj++;
			break;
		}
	
		if(c=='c' || c=='C') {
			crna++;
			brojac++;
		}
		else if(c=='b' || c=='B'){
			bijela++;
			brojac++;
		}
		else if(c=='s' || c=='S'){
			siva++;
			brojac++;
		}
		else if(c=='v' || c=='V'){
			crvena++;
			brojac++;
		}
		else if(c=='p' || c=='P'){
			plava++;
			brojac++;
		}
		else printf("Neispravan unos\n");
	}
	if(kraj==0){
		printf("Neispravan unos\n");
		goto labela;
	}
	
	udio_crne=((float)crna/brojac)*100;
	udio_bijele=((float)bijela/brojac)*100;
	udio_sive=((float)siva/brojac)*100;
	udio_crvene=((float)crvena/brojac)*100;
	udio_plave=((float)plava/brojac)*100;

	printf("Ukupno evidentirano %d vozila.", brojac);
	printf("\nNajpopularnija boja je ");
	if(crna==0 && bijela==0 && siva==0 && crvena==0 && plava==0){
		printf("crna (0.00%%).");
		return 0;
	}
	
	if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
		printf("crna (%.2f%%).", udio_crne);
		return 0;
	}
	if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava){
		printf("bijela (%.2f%%).", udio_bijele);
		return 0;
	}
	if(siva>crna && siva>bijela && siva>=crvena && siva>=plava){
		printf("siva (%.2f%%).", udio_sive);
		return 0;
	}
	if(crvena>crna && crvena>bijela && crvena>siva && crvena>=plava){
		printf("crvena (%.2f%%).", udio_crvene);
		return 0;
	}
	if(plava>crna && plava>bijela && plava>siva && plava>crvena){
		printf("plava (%.2f%%).", udio_plave);
		return 0;
	}
return 0;
}
