#include <stdio.h>
int main() {
	printf("Unesite vozila: ");
	char x;
	int a,c,b,s,v,p,j;
	float m,k;
	a = 0;
	c = 0;
	b = 0;
	s = 0;
	v = 0;
	p = 0;
	do 
	{ 
		scanf("%c",&x);
		if (x!='k' && x!='K'){a = a +1;}
		if (x=='c' || x =='C'){c = c+1;}
		if (x=='B' || x =='b'){b = b+1;}
		if (x=='S' || x =='s'){s = s+1;}
		if (x=='v' || x =='V'){v = v+1;}
		if (x=='p' || x =='P'){p = p+1;}
		if (x!='k' && x!='K' && x!='c' && x!='C' && x!='B' && x!='b' && x!='S' && x!='s' && x!='v' && x!='V' && x!='p' && x!='P'){
			printf("Neispravan unos\n");
			a = a -1 ;
		}
	}
	while (x!='k' && x!='K');
	printf("Ukupno evidentirano %d vozila.\n",a);
	m=c;
	j =5;
	if (b>m){m=b; j =4;}
	if (s>m){m=s; j =3;}
	if (v>m){m=v; j =2;}
	if (p>m){m=p; j =1;}
	if (a == 0) {k =0;} else {k=(m/a)*100;}
	if (j ==5)	{printf("Najpopularnija boja je crna (%.2f%%).",k); return 0;}
	if (j ==4) 	{printf("Najpopularnija boja je bijela (%.2f%%).",k); return 0; }
	if (j ==3) {printf("Najpopularnija boja je siva (%.2f%%).",k); return 0;}
	if (j ==2) {printf("Najpopularnija boja je crvena (%.2f%%).",k); return 0;}
	if (j ==1) {printf("Najpopularnija boja je plava (%.2f%%).",k); return 0;}
	return 0;
}
