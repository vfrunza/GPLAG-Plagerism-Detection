#include <stdio.h>
#include <math.h>
int main() {
    
    char c;
    int brojac_unesenih=0,bc=0,bb=0,bs=0,bv=0,bp=0;
    float  UC,UB,US,UV,UP;
    
   
   printf("Unesite vozila: ");
   
    for(;;){

    scanf("%c",&c); 
   if(c=='K' || c=='k') { break;}
  

if((c=='C') || (c=='c') || (c=='B') || (c=='b') || (c=='S') || (c=='s')|| (c=='V')|| (c=='v')|| (c=='P')||( c=='p')) {
     
     
     brojac_unesenih++; }
     
     
  else {  printf ("Neispravan unos\n"); }
 


if (c=='C' || c=='c') bc++;
if (c=='B' || c=='b') bb++;
if (c=='S' || c=='s') bs++;
if (c=='V' || c=='v') bv++;
if (c=='P' || c=='p') bp++;


}
  if(brojac_unesenih==0) {printf("\nUkupno evidentirano 0 vozila."); 
                      printf("\nNajpopularnija boja je crna (0.00%%)."); 
  return 0;
  }
  
  
  else {
printf("Ukupno evidentirano %d vozila.",brojac_unesenih);
}


UC= bc*100.00/brojac_unesenih;
UB= bb*100.00/brojac_unesenih;
US= bs*100.00/brojac_unesenih;
UV= bv*100.00/brojac_unesenih;
UP= bp*100.00/brojac_unesenih;



if(bc>=bb && bc>=bs && bc>=bv && bc>=bp ) printf("\nNajpopularnija boja je crna (%.2f%%).",UC); 
else if(bb>bc && bb>=bs && bb>=bv && bb>=bp) printf("\nNajpopularnija boja je bijela (%.2f%%).",UB);
else if(bs>bc && bs>bb && bs>=bv && bs>=bp) printf("\nNajpopularnija boja je siva (%.2f%%).",US);
else if(bv>bc && bv>bb && bv>bs && bv>=bp)printf("\nNajpopularnija boja je crvena (%.2f%%).",UV);
else printf("\nNajpopularnija boja je plava (%.2f%%).",UP);







     
    return 0;
    
     
 }
    