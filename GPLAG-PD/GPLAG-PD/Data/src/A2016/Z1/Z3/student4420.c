#include <stdio.h>

int main() {
	int c=0,p=0,b=0,s=0,v=0,uk=0;
	float postotak;
	char boja=' ';
	printf("Unesite vozila: ");
//	scanf("%c",&boja);
	while(boja!='k' || boja!='K')
	{
		scanf("%c",&boja);
		if(boja=='k' || boja=='K')
		{
			goto l1;
		}
		if(boja=='v' || boja=='V')
		{
			v++;
			uk++;
		}
		if(boja=='p' || boja=='P')
		{
			p++;
			uk++;
		}
		if(boja=='c' || boja=='C')
		{
			c++;
			uk++;
		}
		if(boja=='b' || boja=='B')
		{
			b++;
			uk++;
		}
		if(boja=='s' || boja=='S')
		{
			s++;
			uk++;
		}
		if(boja!='c' && boja!='s' && boja!='v' && boja!='p' && boja!='b' && boja!='C' && boja!='S' && boja!='V' && boja!='P' && boja!='B' && boja!='k' && boja!='K')
		{
			printf("Neispravan unos\n");
		}
	}
	l1:
	printf("Ukupno evidentirano %d vozila.\n",uk);
	if(uk==0)
	{
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	if(c>s && c>v && c>p && c>b)
	{
		postotak=((float)c/uk)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",postotak);
		return 0;
	}
	if(s>c && s>v && s>p && s>b)
	{ 
		postotak=((float)s/uk)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",postotak);
		return 0;
	}
	if(v>s && v>c && v>p && v>b)
	{
		postotak=((float)v/uk)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",postotak);
		return 0;
	}
	if(p>s && p>v && p>c && p>b)
	{
		postotak=((float)p/uk)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",postotak);
		return 0;
	}
	if(b>s && b>v && b>p && b>c)
	{
		postotak=((float) b/uk)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",postotak);
		return 0;
	}
	if(c==s)
	{
	postotak=((float)c/uk)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",postotak);	
	}

	if(s==v && v==p)
	{
	postotak=((float)s/uk)*100;
	printf("Najpopularnija boja je siva (%.2f%%).",postotak);	
	}
	
	return 0;
}