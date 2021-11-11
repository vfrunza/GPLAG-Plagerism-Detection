#include <stdio.h>
#define STO 100

int main() {
	char n;
	int C=0, B=0, S=0, V=0, P=0;
	float g, o, m, z, y, l;
	printf("Unesite vozila: ");
	while(1) {
		scanf("%c",&n);
		if(n=='K' || n=='k'){
			break;
			
		}
		else if(n=='C' || n=='c'){
			C+=1;
			continue;
		}
		else if(n=='V' || n=='v'){
			V+=1;
			continue;
		}
		else if(n=='B' || n=='b'){
			B+=1;
			continue;
		}
		else if(n=='P' || n=='p'){
			P+=1;
			continue;
		}
		else if(n=='S' || n=='s'){
			S+=1;
			continue;
		}
			else {
			printf("Neispravan unos \n");
			continue;
		}
		
		}
		l=C+V+S+P+B;
		printf("Ukupno evidentirano %g vozila.\n", l);
		if(l==0){
			printf("Najpopularnija boja je crna (0.00%%).\n");
			return 0;
		}
		
		g=(C*STO)/l;
		o=(V*STO)/l;
		m=(B*STO)/l;
		z=(P*STO)/l;
		y=(S*STO)/l;
		if(C>=B && C>=S && C>=V && C>=P){
			printf("Najpopularnija boja je crna (%.2f%%).", g);
		}
		else if(B>=S && B>=V && B>=P){
			printf("Najpopularnija boja je bijela (%.2f%%).", m);
		}
		else if(S>=V && S>=P){
			printf("Najpopularnija boja je siva (%.2f%%).", y);
		}
		else if(V>=P){
			printf("Najpopularnija boja je crvena (%.2f%%).", o);
		}
		else {
			printf("Najpopularnija boja je plava (%.2f%%).", z);
		}
	return 0;
}
