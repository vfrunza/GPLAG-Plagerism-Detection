#include <stdio.h>
#include <math.h>

int main() {
	char a='a';
	double c=0;
	float b=0;
	float s=0;
	float v=0;
	float p=0;
	int br=0;
	double c1=0;
	float b1,s1,v1,p1;
	printf("Unesite vozila: ");
	while(a!='K' && a!='k') {
		pocetak:
	scanf("%c", &a);
	if(a=='c' || a=='C' || a=='B' || a=='b' || a=='s' || a=='S' || a=='v' || a=='V' || a=='p' || a=='P' || a=='k' || a=='K') {
	br++;
	}
	else {
		printf("Neispravan unos\n");
		goto pocetak;
	}
	
	if(a=='c' || a=='C') {
	c++;
	}
	if(a=='b' || a=='B') {
		b++;
	}
	if(a=='s' || a=='S') {
		s++;
	}
	if(a=='v' || a=='V') {
		v++;
	}
	if(a=='p' || a=='P') {
		p++;
	}
}
	c1=fabs((c*100)/fabs(br-1));
	b1=(b*100)/fabs(br-1);
	s1=(s*100)/fabs(br-1);
	v1=(v*100)/fabs(br-1);
	p1=(p*100)/fabs(br-1);
	
	printf("Ukupno evidentirano %d vozila.", br-1);
	if(br==1) {
		c1=0.00;
	}
	
	if(c>=b && c>=s && c>=v && c>=p) {
		printf("\nNajpopularnija boja je crna (%.2f%%).",c1);
	} else 
	if(b>=c && b>=s && b>=v && b>=p) {
		printf("\nNajpopularnija boja je bijela (%.2f%%).",b1);
	} else
	if(s>=b && s>=c && s>=v && s>=p) {
		printf("\nNajpopularnija boja je siva (%.2f%%).", s1);
	} else
	if(v>=b && v>=s && v>=c && v>=p) {
		printf("\nNajpopularnija boja je crvena (%.2f%%).", v1);
	} else
	if(p>=b && p>=s && p>=v && p>=c) {
		printf("\nNajpopularnija boja je plava (%.2f%%).", p1);
	}
	
	return 0;
}
