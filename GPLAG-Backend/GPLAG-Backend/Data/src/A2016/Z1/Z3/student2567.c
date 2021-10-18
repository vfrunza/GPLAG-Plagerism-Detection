#include <stdio.h>

int main() {

   char z; 
   int bc=0, bs=0, bv=0, bb=0, bp=0, bu=0; 
   
     
     printf ("Unesite vozila: "); 
     for (;;) {
        
     
        scanf ("%c", &z); 
        if (((z!='c') && (z!='C')) && ((z!='b') && (z!='B')) && ((z!='s') && (z!='S')) && ((z!='p') && (z!='P')) && ((z!='v') && (z!='V')) && ((z!='k') && (z!='K'))) {
           printf ("Neispravan unos\n"); 
        }
    
           if (z=='c' || z=='C') {
               bc++; bu++; 
           }
               
           if (z=='b' || z=='B') {
               bb++; bu++;
           }
           if (z=='s' || z=='S') {
               bs++; bu++; 
           }
       
           if (z=='v' || z=='V') {
               bv++; bu++; 
           }
           
           if (z=='p' || z=='P') {
              bp++; bu++; 
           }
           else if (z=='k' || z=='K') 
           break; 
         }
   	        printf ("Ukupno evidentirano %d vozila.", bu); 
   	        
   	        if (bc==0 && bb==0 && bv==0 && bs==0 && bp==0) {
   	            printf ("\nNajpopularnija boja je crna (%.2f%%).", (float)bu);
   	        }
   	        
   	        else if (bc>=bb && bc>=bs && bc>=bv && bc>=bp) {
   	            printf ("\nNajpopularnija boja je crna");
   	            printf (" (%.2f%%).", bc*100./bu);
   	        }
   	        else if (bb>=bc && bb>=bv && bb>=bp && bb>=bs) {
   	           printf ("\nNajpopularnija boja je bijela"); 
   	           printf (" (%.2f%%).", bb*100./bu); 
   	        }
   	        else if (bs>=bc && bs>=bb && bs>=bv && bs>=bp) {
   	           printf ("\nNajpopularnija boja je siva");
   	           printf (" (%.2f%%).", bs*100./bu);
   	        }
   	        else if (bv>=bc && bv>=bb && bv>=bp && bv>=bs) {
   	           printf ("\nNajpopularnija boja je crvena"); 
   	           printf (" (%.2f%%).", bv*100./bu);
   	        }
   	        else if (bp>=bc && bp>=bb && bp>=bv && bp>=bs) {
   	           printf ("\nNajpopularnija boja je plava");
   	           printf (" (%.2f%%).", bp*100./bu);
   	        }
   
	return 0;
}
