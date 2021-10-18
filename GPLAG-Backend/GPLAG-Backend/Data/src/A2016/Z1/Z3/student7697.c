#include <stdio.h>

int main() {
	int C=0,B=0,S=0,V=0,P=0,K=0,Ukupno,max;
	double procenat=0;
	char slovo='a';
	C=0;
	B=0;
	S=0;
	V=0;
	P=0;
	max=0;
	printf("Unesite vozila: ");
	
	while(1) {
		scanf("%c",&slovo);
		   if(slovo=='C' || slovo=='c') {
			   C++;
			   if (C>max) {
			   max=C;
		       }
		   } else if(slovo=='B' || slovo=='b') {
			    B++;
			    if (B>max) {
			    max=B;
	     	    }
		   } else if (slovo=='S' || slovo=='s') {
		        S++;
			    if (S>max) {
			    max=S;
			    }
		   } else if(slovo=='V' || slovo=='v') {
			    V++;
			    if (V>max) {
			    max=V;
			    }
		   } else if(slovo=='P' || slovo=='p') {
			    P++;
			    if (P>max) {
			    max=P;
		     	}
		   } else if(slovo == 'k' ||slovo == 'K') 
		   	break;
		   
          else 
              printf("Neispravan unos\n");
          } 
          
		Ukupno=C+B+S+V+P;
		
		printf("Ukupno evidentirano %d vozila.\n", Ukupno);
		
		if (Ukupno==0) {
			procenat=0;
		} else {
			procenat=(max*100.)/Ukupno;
		}
		
		if (max==C) {
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
		} else if (max==B) {
		printf("Najpopularnija boja je bijela (%.2f%%).",procenat);
		} else if (max==S) {
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
		} else if (max==V) {
		printf("Najpopularnija boja je crvena (%.2f%%).",procenat);
		} else if (max==P) {
		printf("Najpopularnija boja je plava (%.2f%%).",procenat);
	}
	
	return 0;
}
