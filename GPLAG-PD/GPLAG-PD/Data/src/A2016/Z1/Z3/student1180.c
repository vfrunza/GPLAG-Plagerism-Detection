#include <stdio.h>
#include <math.h>
#define epsilon 0.000000001

int main() {
	char a='a';
	double m,x;
	double bc=0,bb=0,bs=0,bv=0,bp=0;
    printf("Unesite vozila: ");
	while(a!='k' && a!='K'){ 
		
		scanf("%c", &a);
		if(a=='c' || a=='C') bc++;
		else if(a=='b' || a=='B') bb++;
		else if(a=='s' || a=='S') bs++;
		else if(a=='v' || a=='V') bv++;
		else if(a=='p' || a=='P') bp++;
		else if(a=='k' || a=='K') break;
		else printf("Neispravan unos\n");
	
			
	}
	m=bc+bb+bs+bv+bp;
	printf("Ukupno evidentirano %g vozila.", m);
		
	if(fabs(m)<epsilon) printf("\nNajpopularnija boja je crna (0.00%%).");
	else {
		if(bc>=bb && bc>=bs && bc>=bv && bc>=bp){
			x=(bc/m)*100;
			printf("\nNajpopularnija boja je crna (%.2f%%).",x);
		}
		else if(bb>=bc && bb>=bs && bb>=bv && bb>=bp){
	 		x=(bb/m)*100;
			printf("\nNajpopularnija boja je bijela (%.2f%%).",x);
		}
		else if(bs>=bc && bs>=bb && bs>=bv && bs>=bp){ 
			x=(bs/m)*100;
			printf("\nNajpopularnija boja je siva (%.2f%%).",x);
		}
		else if(bv>=bc && bv>=bb && bv>=bs && bv>=bp){
			x=(bv/m)*100;
			printf("\nNajpopularnija boja je crvena (%.2f%%).",x);
		}
		else if(bp>=bc && bp>=bb && bp>=bs && bp>=bv){
			x=(bp/m)*100;
			printf("\nNajpopularnija boja je plava (%.2f%%).",x);
		}
	
	}

	
	
	
	return 0;
}
