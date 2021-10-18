#include <stdio.h>

int main() {
	char c;
	int C=0,B=0,S=0,V=0,P=0,ub=0,npb;
	printf ("Unesite vozila: ");
	while (1){
		scanf("%c",&c);
		if (c=='k' || c=='K') break;
	    else if (c=='C'|| c=='c'){ C++; ub++;}
	    else if (c=='B' || c=='b') {B++;ub++;}
	    else if (c=='S' || c=='s') {S++;ub++;}
	    else if (c=='V' || c=='v') {V++;ub++;}
	    else if (c=='P' || c== 'p'){P++;ub++;}
	    
	    else {
	    	printf ("Neispravan unos\n");
	    }
	
	}    	
	    printf ("Ukupno evidentirano %d vozila.\n",ub);
	

		if (ub==0)
			printf ("Najpopularnija boja je crna (0.00%%).");
		else if (C>=B && C>=S && C>=V &&C>=P ){
			npb=C;
			printf ("Najpopularnija boja je crna (%.2f%%).",(float)npb/ub*100);
		}
		else if (B>=C && B>=S && B>=V && B>=P) {
			npb=B;
			printf ("Najpopularnija boja je bijela (%.2f%%).",(float)npb/ub*100);
		}
		else if (S>=C && S>=B && S>=V && S>=P){ 
			npb=S;
			printf ("Najpopularnija boja je siva (%.2f%%).",(float)npb/ub*100);
		}
		else if (V>=C && V>=B && V>=S && V>=P) {
			npb=V;
			printf ("Najpopularnija boja je crvena (%.2f%%).",(float)npb/ub*100);
		}
		else if (P>=C && P>=B && P>=S && P>=V) {
			npb=P;
			printf ("Najpopularnija boja je plava (%.2f%%).",(float)npb/ub*100);
		}
		
	    
	return 0;
}
