#include <stdio.h>

int main() {
	char b;
	float uk=0, max=0, bc=0, bb=0, bs=0, bv=0, bp=0, naj=1; 
	printf("Unesite vozila: ");
	while (1)
	{
	    scanf ("%c", &b);
	    if(b=='K' || b=='k')
	    {
	        printf("Ukupno evidentirano %g vozila.\n", uk);
	        if (naj==1) printf("Najpopularnija boja je crna ");
	        if (naj==2) printf("Najpopularnija boja je bijela ");
	        if (naj==3) printf("Najpopularnija boja je siva ");
	        if (naj==4) printf("Najpopularnija boja je crvena ");
	        if (naj==5) printf("Najpopularnija boja je plava ");
	        if (uk!=0) printf("(%.2f%%).", (max/uk)*100);
	        else printf("(%.2f%%).", 0.);
	        return 0;
	    }
	    if (b=='C' || b=='c')
	    {
	        bc++;
	        if (bc>max)
	        {
	            max=bc;
	            naj=1;
	        }
	    }
	    if (b=='B' || b=='b')
	    {
	        bb++;
	        if (bb>max)
	        {
	            max=bb;
	            naj=2;
	        }
	    }
	    if (b=='S' || b=='s')
	    {
	        bs++;
	        if (bs>max)
	        {
	            max=bs;
	            naj=3;
	        }
	    }
	    if (b=='V' || b=='v')
	    {
	        bv++;
	        if (bv>max)
	        {
	            max=bv;
	            naj=4;
	        }
	    }
	    if (b=='P' || b=='p')
	    {
	        bp++;
	        if (bp>max)
	        {
	            max=bp;
	            naj=5;
	        }
	    }
	    if (b!='C' && b!='c' && b!='B' && b!='b' && b!='S' && b!='s' && b!='V' && b!='v' && b!='P' && b!='p')
	    {
	        printf("Neispravan unos\n");
	    }
	    else uk++;
	}
	return 0;
}
