#include <stdio.h>

int main() {
	char aut, boja;
	int brojacC=0, brojacB=0, brojacS=0, brojacV=0, brojacP=0, brojacU=0, max=0;
	float postotak;
	printf("Unesite vozila: ");
	while(1==1)
	{scanf("%c",&aut);
	if(aut=='c' ||aut=='C') {brojacC++; brojacU++;
		if(brojacC>max) {max=brojacC; boja='c';}
	}
	else if(aut=='b'||aut=='B'){brojacB++; brojacU++;
		if(brojacB>max) {max=brojacB; boja='b';}
	}
	else if(aut=='s' ||aut=='S') {brojacS++; brojacU++;
		if(brojacS>max) {max=brojacS; boja='s';}
	}
	else if(aut=='v' ||aut=='V') {brojacV++; brojacU++;
		if(brojacV>max) {max=brojacV; boja='v';}
	}
	else if(aut=='p' ||aut=='P') {brojacP++; brojacU++;
		if(brojacP>max) {max=brojacP; boja='p';}
	}
    else if(aut=='k' ||aut=='K'){break;}
	else {printf("Neispravan unos\n"); continue;}	
	}
	printf("Ukupno evidentirano %d vozila.\n", brojacU);
	if(brojacU==0) printf("Najpopularnija boja je crna (0.00%).");
	else { postotak=(max*100.)/brojacU;
	if(boja=='c') printf("Najpopularnija boja je crna (%.2f%).", postotak);
	else if(boja=='b') printf("Najpopularnija boja je bijela (%.2f%).",postotak);
	else if(boja=='v') printf("Najpopularnija boja je crvena (%.2f%).", postotak);
	else if(boja=='s') printf("Najpopularnija boja je siva (%.2f%).", postotak); 
	else if(boja='p') printf("Najpopularnija boja je plava (%.2f%).", postotak);
}
	
	return 0;
		
	}
