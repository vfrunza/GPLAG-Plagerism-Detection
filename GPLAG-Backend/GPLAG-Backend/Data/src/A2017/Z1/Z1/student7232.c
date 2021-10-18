#include <stdio.h>
#include <string.h>
int main() {
	char H, P, C, tarik, mirza, bojan, novi_red; 
	float ctr,cbr,cmr, sumr, cbf,cmf,ctf,sumf,ctb,cmb,cbb,sumb,sumrp=0,cp;
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &tarik);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &bojan);
	scanf ("%c", &novi_red);
	printf ("Unesite jelo za Mirzu: ");
	scanf ("%c", &mirza);
	scanf ("%c", &novi_red);
    
    if (tarik=='P')
    {
    	ctr=6.80;
    	ctf=8.00;
    	ctb=5.30;
    }
    if (tarik=='H')
    {
    	ctr=3.30;
    	ctf=3.00;
    	ctb=5.00;
    }
    if (tarik=='C')
    {
    	ctr=5.00;
    	ctf=3.90;
    	ctb=6.00;
    }
    
    if (bojan=='P')
    {
    	cbr=6.80;
    	cbf=8.00;
    	cbb=5.30;
    }
    if (bojan=='H')
    {
    	cbr=3.30;
    	cbf=3.00;
    	cbb=5.00;
    }
    if (bojan=='C')
    {
    	cbr=5.00;
    	cbf=3.90;
    	cbb=6.00;
    }
    
    if (mirza=='P')
    {
    	cmr=6.80;
    	cmf=8.00;
    	cmb=5.30;
    }
    if (mirza=='H')
    {
    	cmr=3.30;
    	cmf=3.00;
    	cmb=5.00;
    }
    if (mirza=='C')
    {
    	cmr=5.00;
    	cmf=3.90;
    	cmb=6.00;
    }
    
    sumr=ctr+cmr+cbr;
    sumf=ctf+cmf+cbf;
    sumb=ctb+cmb+cbb;
    
    if (sumr<sumf && sumr<sumb)
    {
    	printf ("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", sumr);
    }
    
    if (sumf<sumr && sumf<sumb)
    {
    	printf ("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", sumf);
    }
    
    if (sumb<sumr && sumb<sumf)
    {
    	printf ("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", sumb);
    }
    
    if (sumr>sumf || sumr>sumb)
    {
        
       if (ctr>cmr && ctr>cbr)
       {
           ctr=ctr*0.9;
           sumrp=cmr+cbr+ctr;
           if (sumrp<sumf && sumrp<sumb)
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
       }
       
       else if (cmr>ctr && cmr>cbr)
       {
           cmr=cmr*0.9;
           sumrp=ctr+cbr+cmr;
           if (sumrp<sumf && sumrp<sumb)
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
       }
       else if (cbr>cmr && cbr>ctr)
       {
           cbr=cbr*0.9;
           sumrp=ctr+cmr+cbr;
            if (sumrp<sumf && sumrp<sumb)
           {
           
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
       }
       
       else if (ctr==cmr && ctr==cbr)
       {
           sumrp=ctr*0.9+cmr*0.9+cbr*0.9;
            if (sumrp<sumf && sumrp<sumb)
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
       }
       else if (ctr==cmr && ctr!=cbr)
       {
           sumrp=ctr*0.9+cmr*0.9+cbr;
           printf ("%f", sumrp);
           if (sumrp<sumf && sumrp<sumb)
           
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f) KM.\n", sumrp);
           }
       }
       else if (ctr==cbr && ctr!=cmr)
       {
           sumrp=ctr*0.9+cbr*0.9+cmr;
           if (sumrp<sumf && sumrp<sumb)
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
       }
       else if (cmr==cbr && cmr!=ctr)
       {
           sumrp=cmr*0.9+cbr*0.9+ctr;
           if (sumrp<sumf && sumrp<sumb)
           {
           printf ("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumrp);
           }
           
       }
       
    }
   

	return 0;
}
