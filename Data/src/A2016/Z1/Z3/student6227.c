#include <stdio.h>

int main() {
	int n=0,c=0,b=0,s=0,v=0,p=0;
	char k=0;
	float procenat=0;
	
	printf ("Unesite vozila: ");
	while (k!='k' && k!='K')
	{
		scanf ("%c", &k);
		if( k=='c'|| k=='C' ) c++;
		else if( k=='b'|| k=='B' ) b++;
		else if( k=='s'|| k=='S' ) s++;
		else if( k=='v'|| k=='V' ) v++;
		else if( k=='p'|| k=='P' ) p++;
		else if (k!='c' && k!='C' && k!='b' && k!='B' && k!='s' && k!='S' && k!='v' && k!='V' && k!='p' && k!='P' && k!='k' && k!='K') printf("Neispravan unos\n");
	}
	n=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.", n);
	if(n==0) n=1;
	
	if(c>=b && c>=s && c>=v && c>=p) { procenat=(float)c/n;  printf("\nNajpopularnija boja je crna (%.2f%%).", procenat*100);}
	if(c<b && b>=s && b>=v && b>=p) {procenat=(float)b/n; printf("\nNajpopularnija boja je bijela (%.2f%%).", procenat*100);}
	if(s>b && c<s && s>=v && s>=p) {procenat=(float)s/n; printf("\nNajpopularnija boja je siva (%.2f%%).", procenat*100);}
	if(v>c && v>b && s<v && v>=p) { procenat=(float)v/n; printf("\nNajpopularnija boja je crvena (%.2f%%).", procenat*100);}
	if(p>c && p>b && p>s && p>v) {procenat=(float)p/n; printf("\nNajpopularnija boja je plava (%.2f%%).", procenat*100);}
	
	return 0;
}
