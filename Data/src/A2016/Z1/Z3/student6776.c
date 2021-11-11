#include <stdio.h>

int main() {
	float B=0,S=0,C=0,P=0,V=0,pB=0.0,pS=0.0,pC=0.0,pP=0.0,pV=0.0,ukupno;
	char boja;
	printf("Unesite vozila: ");
	do {
			scanf("%c", &boja);
			while(boja=='\n'){
					scanf("%c", &boja);
			}
			if((boja=='b')||(boja=='B')) {B++; continue;}
			if((boja=='s')||(boja=='S')) {S++; continue;}
			if((boja=='c')||(boja=='C')) {C++; continue;}
			if((boja=='p')||(boja=='P')) {P++; continue;}
			if((boja=='v')||(boja=='V')) {V++; continue;}
			if((boja!='b') && (boja!='B') && (boja!='s') && (boja!='S') && (boja!='c') && (boja!='C') && (boja!='p') && (boja!='P') && (boja!='v') && (boja!='V') && (boja!='k') && (boja!='K')){
					printf("Neispravan unos\n");
					continue;
			}
	} while ((boja!='k') && (boja!='K'));
	ukupno=B+S+C+P+V;
	pB=B*100/ukupno;
	pS=S*100/ukupno;
	pC=C*100/ukupno;
	pP=P*100/ukupno;
	pV=V*100/ukupno;
		printf("Ukupno evidentirano %g vozila. \n", ukupno);
	if(ukupno==0){printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if(C>=B && C>=S && C>=P && C>=V){
		printf("Najpopularnija boja je crna (%.2f%%).",pC);
		return 0;}
	if(B>=S && B>=C && B>=P && B>=V){
		printf("Najpopularnija boja je bijela (%.2f%%).",pB);
		return 0;}
	if(S>=B && S>=C && S>=P && S>=V){
		printf("Najpopularnija boja je siva (%.2f%%).",pS);
		return 0;}
	if(P>=B && P>=S && P>=C && P>=V){
		printf("Najpopularnija boja je plava (%.2f%%).",pP);
		return 0;}
	if(V>=B && V>=S && V>=C && V>=P){
		printf("Najpopularnija boja je crvena (%.2f%%).",pV);
		return 0;}
	
	
	return 0;
}
