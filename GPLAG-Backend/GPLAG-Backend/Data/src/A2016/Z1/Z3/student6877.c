#include <stdio.h>
#include <math.h>
int main () {
	char c;
	int brvo=0, brc=0, brv=0, brs=0, brb=0, brp=0;
	float p;
	
	printf("Unesite vozila: ");
    do
	   {
            scanf("%c",&c);
            while (c=='\n')
            scanf("%c",&c);
           
            if (c=='c' || c=='C'){ brc++; continue;}
	    	if (c=='b' || c=='B'){ brb++; continue;}
	    	if (c=='s' || c=='S'){ brs++; continue;}
	    	if (c=='v' || c=='V'){ brv++; continue;}
	    	if (c=='p' || c=='P'){ brp++; continue;}
	    	if ((c != 'c') && (c != 'C') && (c != 'B') && (c !='b')&&(c != 's') && (c !='S')&&(c != 'V') && (c !='v')&&(c != 'p') && (c !='P')&&(c!='k')&&(c!='K')){
			printf ("Neispravan unos\n");
			continue;
	    	}
            
	    }
	    while(c!='k' && c!='K');
	    
	   
	brvo=brc+brb+brv+brp+brs;
	printf("Ukupno evidentirano %d vozila. \n",brvo);
	if (brvo==0) {
		printf("Najpopularnija boja je crna (0.00%%).");
	    return 0;
	}
	if (brc>=brb && brc>=brs && brc>=brv && brc>=brp)
	    {
	    	p=100.*brc/brvo;
	    	printf("Najpopularnija boja je crna (%.2f%).",p);
	    	return 0;
	    }
    if (brb>=brc && brb>=brs && brb>=brv && brb>=brp)
	    {
	    	p=100.*brb/brvo;
	    	printf("Najpopularnija boja je bijela (%.2f%).",p);
	    	return 0;
	    }
	if (brs>=brb && brs>=brc && brs>=brv && brs>=brp)
	    {
	    	p=100.*brs/brvo;
	    	printf("Najpopularnija boja je siva (%.2f%).",p);
	    	return 0;
	    }
	if (brv>=brb && brv>=brs && brv>=brc && brv>=brp)
	    {
	    	p=100.*brv/brvo;
	    	printf("Najpopularnija boja je crvena (%.2f%).",p);
	    	return 0;
	    }
	if (brp>=brb && brp>=brs && brp>=brv && brp>=brc)
	    {
	    	p=100.*brp/brvo;
	    	printf("Najpopularnija boja je plava (%.2f%).",p);
	    	return 0;
	    }    
	
	
	return 0;
}
