#include <stdio.h>

int main() {
	int i=0, j, c=0, b=0, s=0, v=0, p=0; 
	float u;
	char n;
	printf("Unesite vozila: ");
	for(j=0;;j++) {
		scanf("%c", &n);

	if(n=='K' || n=='k') {break;}
	else if(n=='c' || n=='C') {c++; i++;}
	else if(n=='b' || n=='B') {b++; i++;}
	else if(n=='s' || n=='S') {s++; i++;}
	else if(n=='v' || n=='V') {v++; i++;}
	else if(n=='p' || n=='P') {p++; i++;}
	else if(n!='c' && n!='C' && n!='b' && n!='B' && n!='s' && n!='S' && n!='v' && n!='V' && n!='p' && n!='P' && n!='\n') {printf("Neispravan unos\n");} 
	}
	printf("Ukupno evidentirano %d vozila.", i);
	if (i==0) {
		printf("\nNajpopularnija boja je crna (0.00%%).");
	} else if(c>=b && c>=s && c>=v && c>=p) {
		u=(1./i)*c*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", u);
	} else if(b>c && b>=s && b>=v && b>=p) {
		u=(1./i)*b*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", u);
	} else if(s>c && s>b && s>=v && s>=p) {
		u=(1./i)*s*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).", u);
	} else if(v>c && v>b && v>s && v>=p) {
		u=(1./i)*v*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).", u);
	} else if(p>c && p>b && p>s && p>v) {
		u=(1./i)*p*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).", u);
	} 
	return 0;
}
