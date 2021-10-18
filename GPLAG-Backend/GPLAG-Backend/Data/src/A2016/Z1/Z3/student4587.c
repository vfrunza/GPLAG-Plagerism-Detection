#include <stdio.h>

int main() {
      int i, suma=0, bC=0, bB=0, bS=0, bV=0, bP=0;
      float procenat;
      char C='C';
      char B='B';
      char S='S';
      char V='V';
      char P='P';
      char K='K';
      char c='c';
      char b='b';
      char s='s';
      char v='v';
      char p='p';
      char k='k';
      char vozilo;
      for(i=0; i<10000; i++) {
            if(i==0) {
                  printf("Unesite vozila: "); }
                  scanf("%c", &vozilo);
            if(vozilo==C || vozilo==c)
            bC++;
           else  if(vozilo==B || vozilo==b)
            bB++;
          else  if(vozilo==S || vozilo==s)
            bS++;
           else if(vozilo==V || vozilo==v)
            bV++;
          else  if(vozilo==P || vozilo==p)
            bP++;
           else if ((vozilo==K) || (vozilo==k)) {
                  suma=bC+bB+bS+bV+bP;
                  printf("Ukupno evidentirano %d vozila.\n", suma);
           
                  if(bC>bB && bC>bS && bC>bV && bC>bP) {
                   
                  if (!(suma==0)) {
                              procenat=(bC*100.)/suma;
                        printf("Najpopularnija boja je crna (%.2f%%).\n", procenat);
                        }
                        
                        else printf("Najpopularnija boja je crna (0.00%)\n");
                  }
                  else if (bB>bC && bB>bS && bB>bV && bB>bP) {
                        procenat=(bB*100.)/suma;
                        printf("Najpopularnija boja je bijela (%.2f%%).\n", procenat);
                  }
                  
                  else if(bS>bC && bS>bB && bS>bV && bS>bP) {
                        procenat=(bS*100.)/suma;
                        printf("Najpopularnija boja je siva (%.2f%%).\n", procenat);
                  }
                 
                  
                  else if (bV>bC && bV>bB && bV>bS && bV>bP) {
                        procenat=(bV*100.)/suma;
                        printf("Najpopularnija boja je crvena (%.2f%%).\n", procenat);
                  }
                  else if (bP>bC && bP>bB && bP>bS && bP>bV) {
                        procenat=(bP*100.)/suma;
                        printf("Najpopularnija boja je plava (%.2f%%).\n", procenat);
                  }
                  else if (bC==bB || bC==bS || bC==bV || bC==bP) {
                        if (!(suma==0)) {
                        procenat=(bC*100.)/suma;
                        printf("Najpopularnija boja je crna (%.2f%%).\n", procenat); }
                        else printf("Najpopularnija boja je crna (0.00%%).\n");
                        
                  }
                  else if (bB==bS || bB==bV || bB==bP) {
                        procenat=(bB*100.)/suma;
                        printf("Najpopularnija boja je bijela (%.2f%%).\n", procenat);
                  }
                  else if (bS==bV || bS==bP) {
                        procenat=(bS*100.)/suma;
                        if (bS==bC && bS==bP && bS==bV && bS==bB)
                        printf("Najpopularnija boja je siva (%.2f%%).\n", procenat);
                  }
                  else if (bV==bP) {
                        procenat=(bV*100.)/suma;
                        printf("Najpopularnija boja je crvena (%.2f%%).\n", procenat);
                  } 
                  
                  
                 break;
           }
      

            else {
                  printf("Neispravan unos\n");
                  continue;
            }
      }
      
      
      return 0;    
      }