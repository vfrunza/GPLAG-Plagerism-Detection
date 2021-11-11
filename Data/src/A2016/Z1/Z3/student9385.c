#include <stdio.h>

int main() {
	int c=0, s=0, v=0, b=0, p=0, u=0;
	double c1, s1, v1, b1, p1, u1;
	char sl;
	double m;
	int crni=0, sivi=0, crveni=0, bijeli=0, plavi=0;
	printf("Unesite vozila: ");
	for(;;)
	{
		scanf("%c", &sl);
		if(sl=='K' || sl=='k') break;
		else if(sl=='S' || sl=='s') {s++;}
		else if(sl=='V' || sl=='v') {v++;}
		else if(sl=='B' || sl=='b') {b++;}
		else if(sl=='P' || sl=='p') {p++;}
		else if(sl=='C' || sl=='c'){ c++;}
		else printf("Neispravan unos\n");
	}
	
	u=s+c+v+b+p;
	
	c1=c;
	s1=s;
	v1=v;
	b1=b;
	p1=p;
	u1=u;
	
	crni=1; m=(c1/u1)*100;
	if(s>c && s>=v && s>b && s>=p) {crni=0; sivi=1; m=(s1/u1)*100;}
	if(v>c && v>s && v>b && v>=p) {crni=0; crveni=1; m=(v1/u1)*100;}
	if(b>c && b>=v && b>=s && b>=p) {crni=0; bijeli=1; m=(b1/u1)*100;}
	if(p>c && p>v && p>s && p>b) {crni=0; bijeli=1; m=(p1/u1)*100;}
	
	printf("Ukupno evidentirano %d vozila.\n", u);
	
	if(u==0)
	{
		if(crni==1) printf("Najpopularnija boja je crna (0.00%%).");
		if(crveni==1) printf("Najpopularnija boja je crvena (0.00%%).");
		if(sivi==1) printf("Najpopularnija boja je siva (0.00%%).");
		if(bijeli==1) printf("Najpopularnija boja je bijela (0.00%%).");
		if(plavi==1) printf("Najpopularnija boja je plava (0.00%%).");
	}
	else
	{
		if(crni==1) printf("Najpopularnija boja je crna (%.2f%%).", m);
		if(crveni==1) printf("Najpopularnija boja je crvena (%.2f%%).", m);
		if(sivi==1) printf("Najpopularnija boja je siva (%.2f%%).", m);
		if(bijeli==1) printf("Najpopularnija boja je bijela (%.2f%%).", m);
		if(plavi==1) printf("Najpopularnija boja je plava (%.2f%%).", m);
	}
	return 0;
}
