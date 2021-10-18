#include <stdio.h>

int main(){



    char slovo ;
    int brojac=0;
    
    int z=0;
    int y=0;
    int x=0;
    int w=0;
    int j=0;
    
    
    
    printf("Unesite vozila: ");
    
    for(;;) {
    	
    	
    	brojac++ ;
    	scanf("%c",&slovo);
    	if ((slovo=='C') || (slovo=='c')) z++ ;
    	if ((slovo=='B') || (slovo=='b')) y++ ;
    	if ((slovo=='S') || (slovo=='s')) x++ ;
    	if ((slovo=='V') || (slovo=='v')) w++ ;
    	if ((slovo=='P') || (slovo=='p')) j++ ;
  
    	
    	if ((slovo!='C') || (slovo!='c') || (slovo!='B') || (slovo!='b') || (slovo!='S') || (slovo!='s') || (slovo!='V') || (slovo!='v') 
    	|| (slovo!='P') || (slovo!='p')) { printf("Neispravan unos");}
    	
    	if ((slovo=='K') || (slovo=='k')) break;
   
    }
    
    
   printf("Ukupno evidentirano %d vozila.\n",brojac);
   
   if ((z>y) && (z>x) && (z>w) && (z>j)) {printf("Najpopularnija boja je crna (%.2f%%).",(brojac/z)*100);}
   
   if ((y>z) && (y>x) && (y>w) && (y>j)) {printf("Najpopularnija boja je bijela (%.2f%%).",(brojac/y)*100);}
   
   if ((x>z) && (x>y) && (x>w) && (x>j)) {printf("Najpopularnija boja je siva (%.2f%%).",(brojac/x)*100);}
   
   if ((w>z) && (w>y) && (w>x) && (w>j)) {printf("Najpopularnija boja je crvena (%.2f%%)",(brojac/w)*100);}
   
   if ((j>z) && (j>y) && (j>x) && (j>w)) {printf("Najpopularnija boja je plava (%.2f%%)",(brojac/j)*100);}
    
  
    
    
    
	return 0;
}