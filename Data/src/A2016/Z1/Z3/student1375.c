#include <stdio.h>

int main() {
	int i=0, c=0, s=0, b=0, v=0, p=0, ukupno; char n;
	float postotak=0;
	printf("Unesite vozila: ");
	while (i!=3000)
	{
		scanf("%c", &n);
		if (n=='K' || n=='k') break;
		if((n>='A' && n<='Z') || (n>='a' && n<='z'))
		{
			if(n!='c' && n!='C' && n!='b' && n!='B' && n!='s' && n!='S' && n!='v' && n!='V' && n!='p' && n!='P') printf("Neispravan unos\n");
			if (n=='c' || n=='C') c++;
			if (n=='b' || n=='B') b++;
			if (n=='s' || n=='S') s++;
			if (n=='v' || n=='V') v++;
			if (n=='p' || n=='P') p++;
		}
		else printf("Neispravan unos\n");
		i++;
	}
	ukupno=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	if (ukupno == 0) printf("Najpopularnija boja je crna (0.00%%).");
	else {
	if ((c>=b) && (c>=s) && (c>=v) && (c>=p))
	{
		postotak=(c*100.)/ukupno;
		printf("Najpopularnija boja je crna (%.2f%%).", postotak);
	}
	if (b>c && b>=s && b>=v && c>=p)
	{
		postotak=(b*100.)/ukupno;
		printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
	}
	if (s>c && s>b && s>=v && s>=p) 
	{
		postotak=(s*100.)/ukupno;
		printf("Najpopularnija boja je siva (%.2f%%).", postotak);
	}
	if (v>c && v>b && v>s && v>=p)
	{
		postotak=(v*100.)/ukupno;
		printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
	}
	if (p>c && p>b && p>s && p>v)
	{
	    postotak=(p*100.)/ukupno;
		printf("Najpopularnija boja je plava (%.2f%%).", postotak);
	} }
	return 0;
}
