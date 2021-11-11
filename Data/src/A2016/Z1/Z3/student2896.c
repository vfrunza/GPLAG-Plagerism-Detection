#include <stdio.h>

int main() {
	char n;
	int c=0; int b=0; int s=0; int p=0; int v=0;
	int unosk = 0; int max = 0;
	printf("Unesite vozila: ");
	while(unosk <= 0)
	{
		scanf("%c", &n);
		if(n == 'c' || n == 'C')
		{
			c++;
		}
		else if(n == 'b' || n == 'B')
		{
			b++;
		}
		else if(n == 's' || n == 'S')
		{
			s++;
		}
		else if(n == 'p' || n == 'P')
		{
			p++;
		}
		else if(n == 'v' || n == 'V')
		{
			v++;
		}
		else if(n == 'k' || n == 'K')
		{
			unosk = 1;
			printf("Ukupno evidentirano %d vozila.\n", c+b+s+p+v);
		}
		else 
		{
			printf("Neispravan unos\n");
		}
	}
	max = c;
	if(b > max) max = b;
	if(s > max) max = s;
	if(v > max) max = v;
	if(p > max) max = p;
	if(max != 0)
	{
		if(c==max) printf("Najpopularnija boja je crna (%.2f%%).",(c/(c+b+s+p+v+0.0))*100.);
		else if(b==max) printf("Najpopularnija boja je bijela (%.2f%%).",b/(c+b+s+v+p+0.0)*100.);
		else if(s==max) printf("Najpopularnija boja je siva (%.2f%%).",s/(c+b+s+p+v+0.0)*100.);
		else if(v==max) printf("Najpopularnija boja je crvena (%.2f%%).",v/(c+b+s+p+v+0.0)*100.);
		else if(p==max) printf("Najpopularnija boja je plava (%.2f%%).",p/(c+b+s+v+p+0.0)*100.);
	}
	else printf("Najpopularnija boja je crna (0.00%%).");
	return 0;
}
