#include <stdio.h>
#include <ctype.h>
int main() {
	char c;
	int brojac, C, B, S, V, P;
	brojac=0;
	C=0;
	B=0;
	S=0;
	V=0;
	P=0;
	
	printf("Unesite vozila: ");
	do{
		scanf("%c",&c);
		if(c=='c' || c=='C'){
			C++;
			brojac++;
		}else if(c=='b'|| c=='B'){
			B++;
			brojac++;
		}else if(c=='s' || c=='S'){
			S++;
			brojac++;
		}else if(c=='v' || c=='V'){
			V++;
			brojac++;
		}else if(c=='p' || c=='P'){
			P++;
			brojac++;
		}else if(c=='k' || c=='K'){
			break;
		}else{
			printf("Neispravan unos\n");
		}
			
	}while(1);
	
	int max=0;
	if(C>max){
		max=C;
	}
	if(B>max){
		max=B;
	}
	if(S>max){
		max=S;
	}
	if(V>max){
		max=V;
	}
	if(P>max){
		max=P;
	}
	
	printf("Ukupno evidentirano %d vozila.\n", brojac);
	
	
	if(C==max){
		printf("Najpopularnija boja je crna ");
	}else if(B==max){
		printf("Najpopularnija boja je bijela ");
	}else if(S==max){
		printf("Najpopularnija boja je siva ");
	}else if(V==max){
		printf("Najpopularnija boja je crvena ");
	}else if(P==max){
		printf("Najpopularnija boja je plava ");
	}
	 double proc;
	 double br;
	 br=brojac;
	 proc=(max/br)*100;
	 if(brojac==0){
	 	printf("(0.00%).");
	 }else
	 printf("(%.2f%).",proc);
	 return 0;
}
