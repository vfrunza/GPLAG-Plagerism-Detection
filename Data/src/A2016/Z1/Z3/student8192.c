#include <stdio.h>

int main() 
{
	char a;
	int i=0, c=0, b=0, v=0, s=0, p=0, P; /*P je najpopularnija boja*/
	float proc;
	
	printf("Unesite vozila: ");
	while(1)
	{
		scanf("%c", &a);
		if(a=='c' || a=='C') 	  c++;
		else if(a=='b' || a=='B') b++;
		else if(a=='s' || a=='S') s++;
		else if(a=='v' || a=='V') v++;
		else if(a=='p' || a=='P') p++;
		else if(a=='k' || a=='K') break;
		else printf("Neispravan unos\n");
	}
	
	i = c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.", i);
	
	P=c;
	if(b>c) P=b;
	if(s>P) P=s;
	if(v>P) P=v;
	if(p>P) P=p;
	
	if(i==0) i=1;
	proc = (float)P/i*100;

	if(P==c) 	  printf("\nNajpopularnija boja je crna (%.2f%%).", proc);
	else if(P==b) printf("\nNajpopularnija boja je bijela (%.2f%%).", proc);
	else if(P==s) printf("\nNajpopularnija boja je siva (%.2f%%).", proc);
	else if(P==v) printf("\nNajpopularnija boja je crvena (%.2f%%).", proc);
	else if(P==p) printf("\nNajpopularnija boja je plava (%.2f%%).", proc);
	
	return 0;
}
