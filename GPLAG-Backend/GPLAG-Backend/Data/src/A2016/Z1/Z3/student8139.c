#include <stdio.h>

int main() {
	
	int br=0, crna=0, siva=0, crvena=0, plava=0, bijela=0;
	printf("Unesite vozila: ");
	for(;;){
		char c;
		scanf("%c", &c);
		if(c!='c' && c!='C' && c!='b' && c!='B' && c!='s' && c!='S' && c!='v' && c!='V' && c!='p' && c!='P' && c!='k' && c!='K'){
			printf("Neispravan unos\n");
			continue;
		}
		if(c=='k' || c=='K') break;
		br++;
		if(c=='c' || c=='C') crna++;
		else if(c=='b' || c=='B') bijela++;
		else if(c=='s' || c=='S') siva++;
		else if(c=='v' || c=='V') crvena++;
		else if(c=='p' || c=='P') plava++;
	}
	printf("Ukupno evidentirano %d vozila.\n", br);
	//printf("Boje: %d %d %d %d %d\n", crna, bijela, siva, crvena, plava);
	if(br==0) printf("Najpopularnija boja je crna (0.00%%).");
	else{
		int max=0;
		if(plava>max) max=plava;
		if(crvena>max) max=crvena;
		if(siva>max) max=siva;
		if(bijela>max) max=bijela;
		if(crna>max) max=crna;
		//printf("MAX: %d", max);
		if (max==crna){ printf("Najpopularnija boja je crna (%.2f%%).", ((float)crna/br*100)); return 0;}
		if (max==bijela){ printf("Najpopularnija boja je bijela (%.2f%%).", ((float)bijela/br*100)); return 0;}
		if (max==siva){ printf("Najpopularnija boja je siva (%.2f%%).", ((float)siva/br*100)); return 0;}
		if (max==crvena){ printf("Najpopularnija boja je crvena (%.2f%%).", ((float)crvena/br*100)); return 0;}
		if (max==plava){ printf("Najpopularnija boja je plava (%.2f%%).", ((float)plava/br*100)); return 0;}
	}
	return 0;
}