#include <stdio.h>
#include <math.h>
#define E 0.00001
int main() {
	char boja;
	int B,C,S,V,P,max;
	float postotak,q=0;
	C=0;
	B=0;
	S=0;
	V=0;
	P=0;
	/*unos boja vozila*/
	printf("Unesite vozila: ");
	do{
		scanf("%c", &boja);
		if(boja=='B' || boja=='b'){
			B++;
			q++;
		}
		else if(boja=='C' || boja=='c'){
			C++;
			q++;
		}
		else if(boja=='V' || boja=='v'){
			V++;
			q++;
		}
		else if(boja=='S' || boja=='s'){
			S++;
			q++;
		}
		else if(boja=='P' || boja=='p'){
			P++;
			q++;
		}
	    else if(boja!='C' && boja!='c' && boja!='P' && boja!='p' && boja!='S' && boja!='s' && boja!='V' && boja!='v' && boja!='B' && boja!='b'){
		printf("Neispravan unos\n");
	     }
	}
	while(boja!='k' && boja!='K');
	max=C;
	if(B>max){
		max=B;
	}
	if(S>max){
		max=S;
	}
	if(V>max){
		max=V;
	}
	if(C>max){
		max=C;
	}
	if(P>max){
		max=P;
	}
	if(fabs(q-0)>E)
		postotak=(max*100)/q;
		else if(fabs(q-0)<E) 
			postotak=0; 
			printf("Ukupno evidentirano %.0f vozila. \n",q); 
			if(max==B){
				printf("Najpopularnija boja je bijela (%.2f%%).",postotak);
			} else if(max==S){
				printf("Najpopularnija boja je siva (%.2f%%).",postotak);
			} else if(max==V){
				printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
			} else if(max==C){
				printf("Najpopularnija boja je crna (%.2f%%).",postotak);
			} else if(max==P){
				printf("Najpopularnija boja je plava (%.2f%%).",postotak);
			}
		
	
	
	return 0;
}
