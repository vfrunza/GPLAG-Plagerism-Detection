#include <stdio.h>

int main() {
	char a;
	int n=0;
	float v=0,b=0,s=0,c=0,p=0;
	float c1,b1,s1,v1,p1;
	printf("Unesite vozila: ");
	scanf("%c",&a);
	while(a!='k' && a!='K')
	{
		
		if(a=='c' || a=='C')
		{
			c++;
			n++;
			
		}
		else if(a=='b' || a=='B')
		{
			b++;
			n++;
			
		}
		else if(a=='s' || a=='S')
		{
			s++;
			n++;
			
		}
		else if(a=='v' || a=='V')
		{
			v++;
			n++;
			
		}
		else if(a=='p' || a=='P')
		{
			p++;
			n++;
			
		}
		else
		{
		printf("Neispravan unos\n")	;
		}
		scanf("%c",&a);
	}
	if(n!=0)
	{
	c1=(c/(n))*100;
	b1=(b/(n))*100;
	s1=(s/(n))*100;
	v1=(v/(n))*100;
	p1=(p/(n))*100;
	if(c>=b && c>=s && c>=v && c>=p)
	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crna (%.2f%%).",n,c1);
	if(b>c && b>=s && b>=v && b>=p)
	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je bijela (%.2f%%).",n,b1);
	if(s>b && s>c && s>=v && s>=p)
	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je siva (%.2f%%).",n,s1);
	if(v>c && v>b && v>s && v>=p)
	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je crvena (%.2f%%).",n,v1);
	if(p>b && p>s && p>v && p>c)
	printf("Ukupno evidentirano %d vozila.\nNajpopularnija boja je plava (%.2f%%).",n,p1);
}
else
{
	printf("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%%).");
}
	return 0;
}

