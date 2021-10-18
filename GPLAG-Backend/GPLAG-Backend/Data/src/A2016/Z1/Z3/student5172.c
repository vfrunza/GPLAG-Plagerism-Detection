
#include <stdio.h>
	
	int main()
		{
		
		char boja;
		int crvena=0,bijela=0,siva=0,plava=0,crna=0,UBV;
		
		printf("Unesite vozila: ");
	    
	    while(16)
	    {
	    scanf("%c",&boja);
	    if(boja == 'c' || boja == 'C')
	    {
	    	crna++;
	    }
	    else if(boja == 'b' || boja == 'B')
	    {
	    	bijela++;
	    }
	    else if(boja == 's' || boja == 'S')
	    {
	    	siva++;
	    }
	    else if(boja == 'v' || boja == 'V')
	    {
	    	crvena++;
	    }
	    else if(boja == 'p' || boja == 'P')
	    {
	    	plava++;
	    }
	    else if(boja == 'K' || boja == 'k' || boja == '\n')
	    {
	    	break;
	    }
	    else
	    {
	         printf("Neispravan unos\n");
	    }
	    }
	    
	    UBV = crvena+bijela+crna+siva+plava;
	    
	    printf("Ukupno evidentirano %d vozila.\n",UBV);
	    
	    if(crna >= plava && crna >= bijela && crna >= siva && crna >= crvena)
	    { 
	    	printf("Najpopularnija boja je crna (%.2f%%).",UBV == 0 ?0: (crna/(double)UBV) * 100);
	    }
	     else if(bijela >= plava && bijela >= crna && bijela >= siva && bijela >= crvena)
	    {
	    	printf("Najpopularnija boja je bijela (%.2f%%).",(bijela/(double)UBV) * 100);
	    }
	       else if(siva >= bijela && siva >= crna && siva >= plava && siva >= crvena)
	    {
	    	printf("Najpopularnija boja je siva (%.2f%%).", (siva/(double)UBV) * 100);
	    }
	    else if(crvena >= bijela && crvena >= crna && crvena >= siva && crvena >= plava)
	    {
	    	printf("Najpopularnija boja je crvena (%.2f%%).",(crvena/(double)UBV) * 100);
	    }
	     else if(plava >= bijela && plava >= crna && plava >= siva && plava >= crvena)
	    {
	    	printf("Najpopularnija boja je plava (%.2f%%).",(plava/(double)UBV) * 100);
	    }
	    return 0;
	}
