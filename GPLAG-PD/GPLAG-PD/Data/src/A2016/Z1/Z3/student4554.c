#include <stdio.h>

int main() {
	int brc, brb, brs, brcr, brp;
	int max=0; 
	int bra=0;
	double postotak;
	char z, maxz;
	brc=brb=brs=brcr=brp=0;
	
	printf("Unesite vozila: ");
	scanf("%c", &z);
	
	while((z!='K') && (z!='k'))
	{
		if(z=='C' || z=='c')
		{ 
			brc++;
			bra++;
		
			if(brc>max) 
			{
				max=brc;
				maxz='C';
			}
		} 
		else if(z=='B' || z=='b')
		    {
		    	brb++;
		    	bra++;
		    
		    	if(brb>max) 
			{
				max=brb;
				maxz='B';
			}
		}
		else if(z=='S' || z=='s')
		    {
		    	brs++;
		    	bra++;
		    
		    	if(brs>max) 
			{
				max=brs;
				maxz='S';
			}
		    }
			else if(z=='V' || z=='v')
		    {
		    	brcr++;
		    	bra++;
		    
		    	if(brcr>max) 
			{
				max=brcr;
				maxz='V';
			}
		    }
			else if(z=='P' || z=='p')
		    {
		    	brp++;
		    	bra++;
		    
		    	if(brp>max) 
			{
				max=brp;
				maxz='P';
			}
		    }
			else if(z=='K' || z=='k')
			break;

		    else printf("Neispravan unos\n");
		    	scanf("%c", &z);
		    }
    printf("Ukupno evidentirano %d vozila.\n", bra);
    postotak=(float)(max*100)/bra;
    
    if(bra==0)
    {
    	printf("Najpopularnija boja je crna (0.00%%).");
    	return 0;
    }
    if(maxz=='C')
    {
    	printf("Najpopularnija boja je crna (%.2f%%).", postotak);
    }
    else if(maxz=='B')
    {
    	printf("Najpopularnija boja je bijela (%.2f%%).", postotak);
    }
    else if(maxz=='S')
    {
    	printf("Najpopularnija boja je siva (%.2f%%).", postotak);
    }
    else if(maxz=='V')
    {
    	printf("Najpopularnija boja je crvena (%.2f%%).", postotak);
    }
    	else if(maxz=='P')
    {
    	printf("Najpopularnija boja je plava (%.2f%%).", postotak);
    }
return 0;
}

