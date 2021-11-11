#include <stdio.h>

int main() {
	
	int i=0;
	float postotci;
	char n;
	int bc=0, bb=0, bs=0, bv=0, bp=0, bu=0;
	int maxbr=0;
	printf("Unesite vozila: ");
	for(;i<1;i+0)
	{
		n=getchar();
		if(n!='C' && n!='c' && n!='B' && n!='b' && n!='S' && n!='s' && n!='V' && n!='v' && n!='P' && n!='p' && n!='K' && n!='k')
		{
			printf("Neispravan unos\n");
			continue;
		}
		if(n=='C' || n=='c')
		{
			bc++;
			bu++;
		}
		else if(n=='B' || n=='b')
		{
			bb++;
			bu++;
		}
		else if(n=='S' || n=='s')
		{
			bs++;
			bu++;
		}
		else if(n=='V' || n=='v')
		{
			bv++;
			bu++;
		}
		else if(n=='P' || n=='p')
		{
			bp++;
			bu++;
		}
	    if(n=='K' || n=='k')
	    {
	    	printf("Ukupno evidentirano %d vozila.\n", bu);
	    	if(bc>maxbr)
	    	{
	    		maxbr=bc;
	    	}
	    	if(bb>maxbr)
	    	{
	    		maxbr=bb;
	    	}
	    	if(bs>maxbr)
	    	{
	    		maxbr=bs;
	    	}
	    	if(bv>maxbr)
	    	{
	    		maxbr=bv;
	    	}
	    	if(bp>maxbr)
	        {
	        	maxbr=bp;
	        }
	        if(maxbr == 0) postotci=0;
	        else
	        {
	            postotci = ((float) maxbr/bu)*100;
	        }
	        if(maxbr == bc)
	        {
	        	printf("Najpopularnija boja je crna (%.2f%%).", postotci);
	        }
	        else if(maxbr == bb)
	        {
	        	printf("Najpopularnija boja je bijela (%.2f%%).", postotci);
	        }
	        else if(maxbr == bs)
	        {
	        	printf("Najpopularnija boja je siva (%.2f%%).", postotci);
	        }
	        else if (maxbr == bv)
	        {
	        	printf("Najpopularnija boja je crvena (%.2f%%).", postotci);
	        }
	        else if(maxbr == bp)
	        {
	        	printf("Najpopularnija boja je plava (%.2f%%).", postotci);
	        }
	        break;
	    }
	}
	return 0;
}
