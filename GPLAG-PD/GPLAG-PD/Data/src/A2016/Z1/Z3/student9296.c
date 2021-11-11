#include <stdio.h>

int main() {
	
	char slovo;
	int c=0, b=0, s=0, v=0, p=0, br_A;
	float npboja, proc;
	
	printf("Unesite vozila: ");
	
	do
		{
			scanf("%c", &slovo);		
			
			if(slovo=='c' || slovo=='C')
			{
				c++;
			}
			else if(slovo=='b' || slovo=='B')
			{
				b++;
				
			}
			else if(slovo=='s' || slovo=='S')
			{
				s++;
			}
			else if(slovo=='v' || slovo=='V')
			{
				v++;
			}
			else if(slovo=='p' || slovo=='P')
			{
				p++;
			}
			else if(slovo=='K' || slovo=='k')
			{
				break;
			}
			else
			{
				printf("Neispravan unos\n");
				continue;
			}
			
		}
		
	while(slovo!='K' || slovo!='k');
	
	br_A = c+b+s+v+p;
	
	printf("Ukupno evidentirano %i vozila.", br_A);
	
	if(c>=b && c>=s && c>=v && c>=v && c>=p)
	{
		npboja = c;
	}
	else if(b>=c && b>=s && b>=v && b>=p)
	{
		npboja = b;
	}
	else if(s>=c && s>=b && s>=v && s>=p)
	{
		npboja = s;
	}
	else if(v>=c && v>=b && v>=s && v>=p)
	{
		npboja = v;
	}
	else if(p>=c && p>=b && p>=s && p>=v)
	{
		npboja = p;
	}
	
	if(br_A==0)
	{
		proc=0.0;
	}
	else
	{
		proc = (npboja/br_A)*100;
	}
	
	if(npboja==c)
	{
		printf("\nNajpopularnija boja je crna (%.2f%%).", proc);
	}
	else if(npboja==b)
	{
		printf("\nNajpopularnija boja je bijela (%.2f%%).", proc);
	}
	else if(npboja==s)
	{
		printf("\nNajpopularnija boja je siva (%.2f%%).", proc);
	}
	else if(npboja==v)
	{
		printf("\nNajpopularnija boja je crvena (%.2f%%).", proc);
	}
	else if(npboja==p)
	{
		printf("\nNajpopularnija boja je plava (%.2f%%).", proc);
	}
	
	return 0;
}
