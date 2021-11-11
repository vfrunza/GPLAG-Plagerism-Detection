#include <stdio.h>

int main() 
{
	int br=0,c=0,b=0,s=0,v=0,p=0,k=0;
	char boja;
	
	printf("Unesite vozila: ");
	while(k==0)
	{
		scanf("%c", &boja);
		if(boja == 'K' || boja == 'k')
		{
			k++;
		}
		else if(boja == 'C' || boja == 'c')
		{
			c++;
		}
		else if(boja == 'B' || boja == 'b')
		{
			b++;
		}
		else if(boja == 'S' || boja == 's')
		{
			s++;
		}
		else if(boja == 'V' || boja == 'v')
		{
			v++;
		}
		else if(boja == 'P' || boja == 'p')
		{
			p++;
		}
		else
		{
			printf("Neispravan unos\n");
		}
	}
		
	printf("Ukupno evidentirano %d vozila.", c+b+s+v+p);
	
	if(br < c) br = c;
	if(br < b) br = b;
	if(br < s) br = s;
	if(br < v) br = v;
	if(br < p) br = p;
	
	if(br == 0)
	{
		printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	else if(br == c)
	{
		printf("\nNajpopularnija boja je crna (%.2f%%).", br*100./(c+b+s+v+p));
	}
	else if(br == b)
	{
		printf("\nNajpopularnija boja je bijela (%.2f%%).", br*100./(c+b+s+v+p));	
	}
	else if(br == s)
	{
		printf("\nNajpopularnija boja je siva (%.2f%%).", br*100./(c+b+s+v+p));
	}
	else if(br == v)
	{
		printf("\nNajpopularnija boja je crvena (%.2f%%).", br*100./(c+b+s+v+p));
	}
	else if(br == p)
	{
		printf("\nNajpopularnija boja je plava (%.2f%%).", br*100./(c+b+s+v+p));
	}
	return 0;
}
