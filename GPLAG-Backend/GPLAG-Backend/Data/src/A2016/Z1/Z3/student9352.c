#include <stdio.h>

int main() 
{
	char slovo='a';
	int c=0,b=0,s=0,v=0,p=0,u=0;
	double procenat,max=0;
	printf("Unesite vozila: ");
	while(slovo!='k' && slovo!='K')
	{
		scanf("%c",&slovo);
		if(slovo=='c' || slovo=='C')
		c++;
		else if(slovo=='b' || slovo=='B')
		b++;
		else if(slovo=='s' || slovo=='S')
		s++;
		else if(slovo=='v' || slovo=='V')
		v++;
		else if(slovo=='p' || slovo=='P')
		p++;
		else if(slovo=='k' || slovo=='K')
		break;
		else
		  printf("Neispravan unos\n");
	}
	u=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.",u);
	if(c>max)
	  max=c;
	if(b>max)
	  max=b;
	if(s>max)
	  max=s;
	if(v>max)
	  max=v;
	if(p>max)
	  max=p;
	procenat=(max*100)/u;
	if(max==0)
	  printf("\nNajpopularnija boja je crna (0.00%).");
	else if(max==c)
	  printf("\nNajpopularnija boja je crna (%.2lf%%).",procenat);
	else if(max==b)
	  printf("\nNajpopularnija boja je bijela (%.2lf%%).",procenat);
	else if(max==s)
	  printf("\nNajpopularnija boja je siva (%.2lf%%).",procenat);
	else if(max==v)
	  printf("\nNajpopularnija boja je crvena (%.2lf%%).",procenat);
	else if(max==p)
	  printf("\nNajpopularnija boja je plava (%.2lf%%).",procenat);
	return 0;
}
	   

