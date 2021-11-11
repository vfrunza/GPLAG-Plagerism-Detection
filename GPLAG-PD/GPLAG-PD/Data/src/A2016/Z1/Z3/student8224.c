#include <stdio.h>

int main() {
	char n;
	int C=0, B=0, S=0, V=0, P=0, m;
	float t;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &n);
		if(n=='C' || n=='c'){
			C++;
		}
		else if(n=='B' || n=='b'){
			B++;
		}
		else if(n=='S' || n=='s'){
			S++;
		}
		else if(n=='V' || n=='v'){
			V++;
		}
		else if(n=='P' || n=='p'){
			P++;
		}
		else if(n=='k' || n=='K'){
			break;
		}
		else{
			printf("Neispravan unos\n");
		}
	}
	while(n!='k' && n!='K');
	m=C+B+S+V+P;
		printf("Ukupno evidentirano %d vozila.\n", m);
	if(m==0){
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;

	}	
	if(C>=B && C>=S && C>=V && C>=P){
		t=((float)(C)/m)*100;
		printf("Najpopularnija boja je crna (%.2f%%).", t);
	}
	if(C<B && B>=S && B>=V && B>=P){
		t=((float)(B)/m)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).", t);
	}
	if(S>B && C<S && S>=V && S>=P){
		t=((float)(S)/m)*100;
		printf("Najpopularnija boja je siva (%.2f%%).", t);
	}
	if(V>B && V>S && C<V && V>=P){
		t=((float)(V)/m)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).", t);
	}
	if(P>B && P>S && P>V && C<P){
		t=((float)(P)/m)*100;
		printf("Najpopularnija boja je plava (%.2f%%).", t);
	}
	return 0;
}
