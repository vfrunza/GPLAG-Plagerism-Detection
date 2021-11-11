#include <stdio.h>
int main() {
	char A;
	int C=0,B=0,S=0,V=0,P=0,UEV=0;
	float UC,UB,US,UV,UP;
	      printf("Unesite vozila: ");
	 do {
	 	  scanf("%c", &A);
	 if(A!='C' && A!='c' && A!='B' && A!='b' && A!='S' && A!='s' && A!='V' && A!='v' && A!='P' && A!='p' && A!='K' && A!='k'){
	 	  printf("Neispravan unos\n");}
	 else if(A=='C' || A=='c' || A=='B'|| A=='b'|| A=='S' || A=='s' || A=='V' || A=='v' || A=='P' || A=='p')
	{UEV++;}
	
	if(A=='C' || A=='c'){C++;}
	if(A=='B' || A=='b'){B++;}
	if(A=='S' || A=='s'){S++;}
	if(A=='V' || A=='v'){V++;}
	if(A=='P' || A=='p'){P++;} }
	while (A!='K' && A!='k');
	printf("Ukupno evidentirano %d vozila.\n", UEV);
	
	if(UEV!=0){
		if(C>=B && C>=S && C>=V && C>=P){
			UC=(C*100.0/UEV);
			printf("Najpopularnija boja je crna (%.2f%%).", UC);}
		else if(B>=S && B>=V && B>=P && B>=C){
			UB=(B*100.0/UEV);
			printf("Najpopularnija boja je bijela (%.2f%%).", UB);}
		else if(S>=V && S>=P && S>=C && S>=B){
			US=(S*100.0/UEV);
			printf("Najpopularnija boja je siva (%.2f%%).", US);}
		else if(V>=P && V>=C && V>=B && V>=S){
			UV=(V*100.0/UEV);
			printf("Najpopularnija boja je crvena (%.2f%%).", UV);}
		else if(P>=C && P>=B && P>=S && P>=V){
			UP=(P*100.0/UEV);
			printf("Najpopularnija boja je plava (%.2f%%).", UP);}}
		else {
			printf("Najpopularnija boja je crna (0.00%%).");
		}
		 return 0;
	}
	