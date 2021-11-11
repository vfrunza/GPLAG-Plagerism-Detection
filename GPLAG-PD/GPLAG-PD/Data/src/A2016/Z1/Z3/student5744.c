#include <stdio.h>

int main ()
{
	int c=0,i,b=0,s=0,v=0,p=0;
	float x;
	char a;
	printf("Unesite vozila: ");
	for (i=0;;i++)
	{
		scanf("%c",&a);
		if(a=='C' || a=='c')
		{
			c++;
		} else if(a=='B' || a=='b')
		{
			b++;
		} else if(a=='S' || a=='s')
		{
			s++;
		} else if(a=='V' || a=='v')
		{
			v++;
		} else if(a=='P' || a=='p')
		{
			p++;
		} else if(a=='K' || a=='k')
		{
			break;
		} else
		{
			printf("Neispravan unos\n");
			i--;
		}
	}
	printf("Ukupno evidentirano %d vozila.\n",i);
	if (i==0)
	{
		printf("Najpopularnija boja je crna (0.00%%).",x);
	} else if (c>=b && c>=s && c>=v && c>=p)
	{
		x=(c*100.)/i;
		printf("Najpopularnija boja je crna (%.2f%%).",x);
	} else if (b>=s && b>=v && b>=p)
	{
		x=(b*100.)/i;
		printf("Najpopularnija boja je bijela (%.2f%%).",x);
	} else if (s>=v && s>=p)
	{
		x=(s*100.)/i;
		printf("Najpopularnija boja je siva (%.2f%%).",x);
	} else if (v>=p)
	{
		x=(v*100.)/i;
		printf("Najpopularnija boja je crvena (%.2f%%).",x);
	} else 
	{
		x=(p*100.)/i;
		printf("Najpopularnija boja je plava (%.2f%%).",x);
	}
	return 0;
}	