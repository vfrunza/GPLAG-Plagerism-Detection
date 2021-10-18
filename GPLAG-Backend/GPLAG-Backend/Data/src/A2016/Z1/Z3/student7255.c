#include <stdio.h>

int main() {
	float C=0,B=0,S=0,V=0,P=0,cp=0.0,bp=0.0,sp=0.0,vp=0.0,pp=0.0,Uv=0;
	char unos;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&unos);
		if((unos=='c')||(unos=='C')){C++; }
		else if ((unos=='b')||(unos=='B')){B++; }
		else if ((unos=='s')||(unos=='S')){S++; }
		else if ((unos=='v')||(unos=='V')){V++; }
		else if ((unos=='p')||(unos=='P')){P++; }
		else if ((unos!='k')&&(unos!='K')){printf("Neispravan unos\n");}
		} while ((unos!='k')&&(unos!='K'));
		Uv=C+B+S+V+P;
		cp=(C/Uv)*100;
		bp=(B/Uv)*100;
		sp=(S/Uv)*100;
		vp=(V/Uv)*100;
		pp=(P/Uv)*100;
		printf("Ukupno evidentirano %g vozila.\n",Uv);
		if(Uv==0){
			printf("Najpopularnija boja je crna (0.00%%).");
			return 0;}
		if((C>=B)&&(C>=S)&&(C>=V)&&(C>=P)){
			printf("Najpopularnija boja je crna (%.2f%%).",cp);
			return 0;}
		if((B>=C)&&(B>=S)&&(B>=V)&&(B>=P)){
			printf("Najpopularnija boja je bijela (%.2f%%).",bp);
			return 0;}
		if((S>=C)&&(S>=B)&&(S>=V)&&(S>=P)){
			printf("Najpopularnija boja je siva (%.2f%%).",sp);
			return 0;}
		if((V>=C)&&(V>=B)&&(V>=S)&&(V>=P)){
			printf("Najpopularnija boja je crvena (%.2f%%).",vp);
			return 0;}
		if((P>=C)&&(P>=B)&&(P>=S)&&(P>=V)){
			printf("Najpopularnija boja je plava (%.2f%%).",pp);
			return 0;}
		return 0;

}
