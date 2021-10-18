#include <stdio.h>
#include <math.h>


int main() 
{
	char boja;
	int brojac=0;
	float postotak_c, postotak_b, postotak_s, postotak_v, postotak_p, brojac_p=0, brojac_v=0, brojac_s=0, brojac_b=0, brojac_c=0;
	printf("Unesite vozila: ");
	
	for(;;)
	{
		scanf("%c", &boja);
		if(boja=='C' || boja=='c')
		brojac_c++;
		else if(boja=='b' || boja=='B')
		brojac_b++;
		else if(boja=='s' || boja=='S')
		brojac_s++;
		else if(boja=='v' || boja=='V')
		brojac_v++;
		else if(boja=='p' || boja=='P')
		brojac_p++;
		else if(boja=='k' || boja=='K')
		break;
		else
		printf("Neispravan unos\n");
	}
	
	brojac=brojac_c+brojac_b+brojac_s+brojac_v+brojac_p;
	printf("Ukupno evidentirano %d vozila.", brojac);
	
	if(brojac_c>=brojac_b && brojac_c>=brojac_s && brojac_c>=brojac_v && brojac_c>=brojac_p)
	{
		postotak_c=(float)(brojac_c*100)/brojac;
		if(brojac_c==0)
		printf("\nNajpopularnija boja je crna (0.00%).");
		else
		printf("\nNajpopularnija boja je crna (%.2f%).", postotak_c);
	}
	else if(brojac_b>brojac_c && brojac_b>=brojac_s && brojac_b>=brojac_v && brojac_b>=brojac_p)
	{
		postotak_b=(float)(brojac_b*100)/brojac;
		printf("\nNajpopularnija boja je bijela (%.2f%).", postotak_b);
	}
	else if(brojac_s>brojac_c && brojac_s>brojac_b && brojac_s>=brojac_v && brojac_s>=brojac_p)
	{
		postotak_s=(float)(brojac_s*100)/brojac;
		printf("\nNajpopularnija boja je siva (%.2f%).", postotak_s);
	}
	else if(brojac_v>brojac_c && brojac_v>brojac_b && brojac_v>brojac_s && brojac_v>=brojac_p)
	{
		postotak_v=(float)(brojac_v*100)/brojac;
		printf("\nNajpopularnija boja je crvena (%.2f%).", postotak_v);
	}
	else if(brojac_p>brojac_c && brojac_p>brojac_b && brojac_p>brojac_s && brojac_p>brojac_v)
	{
		postotak_p=(float)(brojac_p*100)/brojac;
		printf("\nNajpopularnija boja je plava (%.2f%).", postotak_p);
	}
	
	return 0;
}
