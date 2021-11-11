#include <stdio.h>

int main() {
	int brc=0,brb=0,brs=0,brv=0,brp=0,bra=0;
	int max=0;
	char znak;double postotak, z;
	
	printf("Unesite vozila: ");
		while (1==1){
	scanf ("%c", &znak);

	if(znak=='C'|| znak=='c')
	{brc++;bra++;
		
	if (brc>max){ max=brc;}
	}
	else if (znak=='b' || znak=='B')
	{ brb++;bra++;
		if (brb>max) {max=brb;}
	}
	else if (znak=='s' || znak=='S')
	{brs++;bra++;
		if (brs>max) {max=brs; }
	}
	else if (znak=='V'|| znak=='v')
	{brv++;bra++;
		if (brv>max) {max=brv;}
	}
	else if (znak=='P' || znak=='p')
	{brp++;bra++;
		if(brp>max) { max=brp;}
	}
	else if (znak=='K' || znak=='k')
	{ 
		break;
	}
	else 
{	
	printf ("Neispravan unos\n");
	}
			
		}
	
	printf("Ukupno evidentirano %d vozila.", bra);
	if (max==0)
	{ z=0.0;}

	else { 
	 postotak=max;
		z=(postotak*100)/bra;
		
	}
	if (max==brc)
	{printf ("\nNajpopularnija boja je crna (%.2f%%).", z  );
	}
	else if (max==brb)
	{printf (" \nNajpopularnija boja je bijela (%.2f%%).", z );
	}else if (max==brs)
	{printf(" \nNajpopularnija boja je siva (%.2f%%).",z);
	}
	else if (max==brv)
	{printf (" \nNajpopularnija boja je crvena (%.2f%%).", z);
	}
	else if (max==brp)
	{printf(" \nNajpopularnija boja je plava (%.2f%%).", z);
	}
	return 0;
}
