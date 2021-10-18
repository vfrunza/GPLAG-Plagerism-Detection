#include <stdio.h>

int main() {
	char boja;
	int a=0,b=0,c=0,d=0,e=0,x=0;
	float z=0,brojac=0;
	
	printf("Unesite vozila: ");
	do{
		scanf("%c",&boja);
		if(boja!='p' && boja!='P' && boja!='v' && boja!='V' && boja!='s' && boja!='S' && boja!='b' && boja!='B' && boja!='c' && boja!='C' && boja!='k' && boja!='K'){
			printf("Neispravan unos\n");
		}
		else{
			if(boja=='c' || boja=='C'){
				a++;
				brojac++;
			}
			if(boja=='b' || boja=='B'){
				b++;
				brojac++;
			}
			if(boja=='s' || boja=='S'){
				c++;
				brojac++;
			}
			if(boja=='v' || boja=='V'){
				d++;
				brojac++;
			}
			if(boja=='p' || boja=='P'){
				e++;
				brojac++;
			}
			if(boja=='k' || boja=='K')
			break;
			x=a+b+c+d+e;
			
			
		}
		
		
		
		
	}
	while(brojac>-1);
	printf("Ukupno evidentirano %d vozila.",x);
	
	if(a>=b && a>=c && a>=d && a>=e){
		z=(a/brojac)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).",z);
	
	}
	else if(b>=a && b>=c && b>=d && b>=e){
		z=(b/brojac)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",z);
	}
	else if(c>=a && c>=b && c>=d && c>=e){
		z=(c/brojac)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).",z);
	}
	else if(d>=a && d>=b && d>=c && d>=e){
		z=(d/brojac)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",z);
	}
	else{
		z=(e/brojac)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).",z);
	}
	return 0;
}
