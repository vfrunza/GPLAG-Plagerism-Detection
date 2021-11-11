#include <stdio.h>
int main () {
    char a= ' ';
    int cmax=0, bmax=0, pmax=0, vmax=0, smax=0, auk=0;
    float max=0;
    printf ("Unesite vozila: "); 
    while (0==0)
 {
     scanf ("%c", &a);
if (a=='c' || a=='C') {
    cmax++;
    auk++;
 }     
    else if (a=='S' || a=='s') {
    smax++;
    auk++;
 }
else if (a=='B' || a=='b') {
    bmax++;
    auk++;
   }
else if (a=='V' || a=='v') {
    vmax++;
    auk++;
   }
else if (a=='P' || a=='p') {
    pmax++;
    auk++;
    }
else if (a=='K' || a=='k') 
    break;  
else if (a== ' ' ) { printf ("Neispravan unos\n"); }
else { printf ("Neispravan unos\n"); }
}
        printf ("Ukupno evidentirano %d vozila.\n", auk);
    if (cmax==0 && bmax==0 && smax==0 && vmax==0 && pmax==0) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (0.00%%).");
        return 0; }
   else if (cmax>bmax && cmax>smax && cmax>vmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }
   else if (bmax>cmax && bmax>smax && bmax>vmax && bmax>pmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }
   else if (smax>cmax && smax>vmax && smax>bmax && smax>pmax) { 
        max=(smax*100.)/auk;
        printf ("Najpopularnija boja je siva (%.2f%%).", max); }
   else if (vmax>cmax && vmax>smax && vmax>pmax && vmax>bmax) { 
        max=(vmax*100.)/auk;
        printf ("Najpopularnija boja je crvena (%.2f%%).", max); }
   else if (pmax>cmax && pmax>smax && pmax>vmax && pmax>bmax) { 
        max=(pmax*100.)/auk;
        printf ("Najpopularnija boja je plava (%.2f%%).", max); }
        /*Najpopularnija boja: crna*/
   else if (bmax==cmax && cmax>smax && cmax>vmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }
   else if (smax==cmax && cmax>bmax && cmax>vmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }        
   else if (vmax==cmax && cmax>smax && cmax>bmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }      
   else if (pmax==cmax && cmax>smax && cmax>vmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }    
   else if (bmax==cmax && cmax==smax && cmax>vmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }       
   else if (bmax==cmax && cmax==vmax && cmax>smax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }       
   else if (bmax==cmax && cmax==pmax && cmax>vmax && cmax>smax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }       
   else if (cmax==smax && cmax==bmax && cmax>vmax && cmax>pmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }       
   else if (cmax==smax && cmax==pmax && cmax>vmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }               
   else if (cmax==smax && cmax==vmax && cmax>pmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }      
   else if (cmax==vmax && cmax==pmax && cmax>vmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }    
   else if (cmax==vmax && cmax==smax && cmax>vmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }                       
   else if (cmax==vmax && cmax==bmax && cmax>pmax && cmax>smax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); } 
   else if (cmax==vmax && cmax==smax && cmax==pmax && cmax>bmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }    
   else if (cmax==pmax && cmax==smax && cmax==bmax && cmax>vmax) { 
        max=(cmax*100.)/auk;
        printf ("Najpopularnija boja je crna (%.2f%%).", max); }   
        /*Najpopularnija boja: bijela*/
   else if (bmax==smax && bmax>cmax && bmax>vmax && bmax>pmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); } 
   else if (bmax==vmax && bmax>smax && bmax>cmax && bmax>pmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }      
   else if (bmax==pmax && bmax>smax && bmax>vmax && bmax>cmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }    
   else if (bmax==smax && bmax==vmax && bmax>cmax && bmax>pmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }       
   else if (bmax==smax && bmax==pmax && bmax>vmax && bmax>cmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }       
   else if (bmax==smax && bmax==vmax && bmax==pmax && bmax>cmax) { 
        max=(bmax*100.)/auk;
        printf ("Najpopularnija boja je bijela (%.2f%%).", max); }       
        /*Najpopularnija boja: siva*/
   else if (smax==pmax && smax>pmax && smax>bmax && smax>cmax) { 
        max=(smax*100.)/auk;
        printf ("Najpopularnija boja je siva (%.2f%%).", max); } 
   else if (smax==vmax && smax>cmax && smax>vmax && smax>bmax) { 
        max=(smax*100.)/auk;
        printf ("Najpopularnija boja je siva (%.2f%%).", max); }                 
   else if (smax==pmax && smax==vmax && smax>cmax && smax>bmax) { 
        max=(smax*100.)/auk;
        printf ("Najpopularnija boja je siva (%.2f%%).", max); }     
        /*Najpopularnija boja: crvena*/
   else if (vmax==pmax && smax>smax && smax>bmax && smax>cmax) { 
        max=(vmax*100.)/auk;
        printf ("Najpopularnija boja je crvena (%.2f%%).", max); }      
     return 0;   
}