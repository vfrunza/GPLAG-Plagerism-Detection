#include <stdio.h>

int main() {
	/*C - crna*/
	/*B - bijela*/
	/*S - siva*/
	/*V - crvena*/
	/*P - plava*/
	/*K - kraj unosa*/
	
	char f;
	double c,b,s,v,p,k;
	double m,n,o,r,q;
c=0; b=0; s=0; v=0; p=0; k=0;
	printf("Unesite vozila: ");
	do {
	scanf("%c", &f);
	if( f!='c' && f!='C' && f!='b' && f!='B' && f!='s' && f!='S' && f!='v' && f!='V' && f!='p' && f!='P' && f!='k' && f!='K' )
	{printf("Neispravan unos\n");}
	else {
			 if(f=='c' || f=='C') {c++;k++;}
		else if(f=='b' || f=='B') {b++;k++;}
		else if(f=='s' || f=='S') {s++;k++;}
		else if(f=='v' || f=='V') {v++;k++;}
		else if(f=='p' || f=='P') {p++;k++;} 
		
		}}
		while (f!='k' && f!='K');
		m=(c/k)*100;
		n=(b/k)*100;
		o=(s/k)*100;
		r=(v/k)*100;
		q=(p/k)*100;
		printf("Ukupno evidentirano %g vozila.\n", k);
		if(k==0) {
			printf("Najpopularnija boja je crna (0.00%%).");
		}
		  else if(c>=b && c>=s && c>=v && c>=p) {
			printf("Najpopularnija boja je crna (%.2f%%).", m);
		} else if(b>=c && b>=s && b>=v && b>=p) {
			printf("Najpopularnija boja je bijela (%.2f%%).", n);
		} else if(s>=c && s>=b && s>=v && s>=p) {
			printf("Najpopularnija boja je siva (%.2f%%).", o);
		} else if(v>=c && v>=b && v>=s && v>=p) {
			printf("Najpopularnija boja je crvena (%.2f%%).", r);
		} else if(p>=c && p>=b && p>=s && p>=v) {
			printf("Najpopularnija boja je plava (%.2f%%).", q);
		}
		
	
	return 0;
}
