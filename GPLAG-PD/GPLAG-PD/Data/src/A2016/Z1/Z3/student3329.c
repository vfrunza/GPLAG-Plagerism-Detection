#include <stdio.h>

int main() {
	/*Varijable za brojace*/
	int brojacvozila=0, bC=0, bB=0, bS=0, bV=0, bP=0, k;
	float procentC,procentB,procentS,procentV,procentP;
	/*Varijable za poredak*/
	int porC=0, porB=0, porS=0, porV=0, porP=0, por=1;
	char u;
	
	printf("Unesite vozila: ");
	scanf("%c",&u);
	
	while (u!='k'&&u!='K'){
		if (u=='c'||u=='C'||u=='b'||u=='B'||u=='s'||u=='S'||u=='v'||u=='V'||u=='p'||u=='P'){
			brojacvozila++;
			if (u=='c'||u=='C'){ bC++; if (porC==0){porC=por;}}
			if (u=='b'||u=='B'){ bB++; if (porB==0){porB=por;}}
			if (u=='s'||u=='S'){ bS++; if (porS==0){porS=por;}}
			if (u=='v'||u=='V'){ bV++; if (porV==0){porV=por;}}
			if (u=='p'||u=='P'){ bP++; if (porP==0){porP=por;}}
		}else{
			printf("Neispravan unos\n");
		}
		scanf("%c",&u);
		por++;
	}

	printf("Ukupno evidentirano %d vozila.",brojacvozila);
	procentC=(float)bC/brojacvozila*100;
	procentB=(float)bB/brojacvozila*100;
	procentS=(float)bS/brojacvozila*100;
	procentV=(float)bV/brojacvozila*100;
	procentP=(float)bP/brojacvozila*100;
	/*Ako je broj neke boje strogo veci od ostalih*/
	
	if (bC>bB&&bC>bS&&bC>bV&&bC>bP){printf("\nNajpopularnija boja je crna (%.2f%).", procentC);k=1;}
	if (bB>bC&&bB>bS&&bB>bV&&bB>bP){printf("\nNajpopularnija boja je bijela (%.2f%).", procentB);k=1;}
	if (bS>bB&&bS>bC&&bS>bV&&bS>bP){printf("\nNajpopularnija boja je siva (%.2f%).", procentS);k=1;}
	if (bV>bB&&bV>bS&&bV>bC&&bV>bP){printf("\nNajpopularnija boja je crvena (%.2f%).", procentV);k=1;}
	if (bP>bB&&bP>bS&&bP>bV&&bP>bC){printf("\nNajpopularnija boja je plava (%.2f%).", procentP);k=1;}
	
	/*Ako su svih 5 isti*/
	
	if (bC==bB && bB==bS && bS==bV && bV==bP && k==0){
		k=1;
		if (porC<porB && porC<porS && porC<porV && porC<porP){printf("\nNajpopularnija boja je crna (%.2f%).", procentC);}
		if (porB<porC && porB<porS && porB<porV && porB<porP){printf("\nNajpopularnija boja je bijela (%.2f%).", procentB);}
		if (porS<porC && porS<porB && porS<porV && porS<porP){printf("\nNajpopularnija boja je siva (%.2f%).", procentS);}
		if (porV<porC && porV<porB && porV<porS && porV<porP){printf("\nNajpopularnija boja je crvena (%.2f%).", procentV);}
		if (porP<porC && porP<porB && porP<porS && porP<porV){printf("\nNajpopularnija boja je plava (%.2f%).", procentP);}
	}
		
	if (bC==bB && bB==bS && bS==bV && k==0){
		k=1;
		if (porC<porB && porC<porS && porC<porV){printf("\nNajpopularnija boja je crna (%.2f%).", procentC);}
		if (porB<porC && porB<porS && porB<porV){printf("\nNajpopularnija boja je bijela (%.2f%).", procentB);}
		if (porS<porC && porS<porB && porS<porV){printf("\nNajpopularnija boja je siva (%.2f%).", procentS);}
		if (porV<porC && porV<porB && porV<porS){printf("\nNajpopularnija boja je crvena (%.2f%).", procentV);}
	}
		
	if (bC==bB && bB==bS && k==0){
		if (porC<porB && porC<porS){printf("\nNajpopularnija boja je crna (%.2f%).", procentC);}
		if (porB<porC && porB<porS){printf("\nNajpopularnija boja je bijela (%.2f%).", procentB);}
		if (porS<porC && porS<porB){printf("\nNajpopularnija boja je siva (%.2f%).", procentS);}
	}
	return 0;
}