#include <stdio.h>

int main() {
	int C=0, B=0, S=0, V=0, P=0, U=0, K;
	double Cp, Bp, Sp, Vp, Pp;
	char x=' ', Naj;
	
	printf("Unesite vozila: ");
	while (x!='k' && x!='K') {
		     scanf("%c", &x);
		     switch(x) {
		     	      case 'c':
		     	              C++;
		     	              break;
		     	      case 'C':
		     	              C++;
		     	              break;
		     	      case 'b':
		     	              B++;
		     	              break;
		     	      case 'B':
		     	              B++;
		     	              break;
		     	      case 's':
		     	              S++;
		     	              break;
		     	      case 'S':
		     	              S++;
		     	              break;
		     	      case 'v':
		     	              V++;
		     	              break;
		     	      case 'V':
		     	              V++;
		     	              break;
		     	      case 'p':
		     	              P++;
		     	              break;
		     	      case 'P':
		     	              P++;
		     	              break;
		     	      case 'k':
		     	              K++;
		     	              break;
		     	      case 'K':
		     	              K++;
		     	              break;
		     	      default:
		     	              printf("Neispravan unos\n");
		     	       }
	}
	
	U=C+B+S+V+P;
	printf("Ukupno evidentirano %d vozila.", U);
	
	if (U>0){
		       Cp=(double)C*100/U;
	           Bp=(double)B*100/U;
 	           Sp=(double)S*100/U;
               Vp=(double)V*100/U;
	           Pp=(double)P*100/U;
	    }
	
	else {
		  printf("\nNajpopularnija boja je crna (0.00%%).");
		  return 0;
	}
	
	Naj='C';
	if(Bp>Cp)
	       Naj='B';
	if(Sp>Bp && Sp>Cp)
	       Naj='S';
	if(Vp>Bp && Vp>Cp && Vp>Sp)
	       Naj='V';
	if(Pp>Bp && Pp>Cp && Pp>Sp && Pp>Vp)
	       Naj='P';
	
	if(Naj=='C'){
	       printf("\nNajpopularnija boja je crna (%.2f%%).", Cp);
	}
	else if(Naj=='B'){
	       printf("\nNajpopularnija boja je bijela (%.2f%%).", Bp);
	}
	else if(Naj=='S'){
	       printf("\nNajpopularnija boja je siva (%.2f%%).", Sp);
	}
	else if(Naj=='V'){
	       printf("\nNajpopularnija boja je crvena (%.2f%%).", Vp);
	}
	else {
	       printf("\nNajpopularnija boja je plava (%.2f%%).", Pp);
    }
	return 0;
}