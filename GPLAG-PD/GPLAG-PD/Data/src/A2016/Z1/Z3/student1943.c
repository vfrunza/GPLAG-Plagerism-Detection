#include <stdio.h>

int main() {
	int brojac=0,br1=0,br2=0,br3=0,br4=0,br5=0;
	char a;
	float prosjek;
	int max=0;
	printf("Unesite vozila: ");
	do {
	    a=getchar();
	    
	    if(a=='C' || a=='c') {br1++; brojac++; }
	    else if(a=='B' || a=='b') {br2++; brojac++; }
	    else if(a=='S' || a=='s') {br3++; brojac++; }
 	    else if(a=='V' || a=='v') {br4++; brojac++; }
	    else if(a=='P' || a=='p') {br5++; brojac++; }
	    else { if(a!='K' && a!='k') printf("Neispravan unos\n"); }
	    
	}while(a!='K' && a!='k');
	
	printf("Ukupno evidentirano %d vozila.",brojac);

	max=br1;
	if(br2>max) max=br2;
	if(br3>max) max=br3;
	if(br4>max) max=br4;
	if(br5>max) max=br5;
	
	
  if(brojac!=0) {
  	
             if (br1==max) { prosjek=(float)br1*100/brojac;
                                                      printf("\nNajpopularnija boja je crna (%.2f%%).",prosjek); }
             else if(br2==max) { prosjek=(float)br2*100/brojac;
                                                      printf("\nNajpopularnija boja je bijela (%.2f%%).",prosjek); }
             else if(br3==max) { prosjek=(float)br3*100/brojac;
                                                      printf("\nNajpopularnija boja je siva (%.2f%%).",prosjek); }   
             else if(br4==max) { prosjek=(float)br4*100/brojac;
                                                      printf("\nNajpopularnija boja je crvena (%.2f%%).",prosjek); }
             else if(br5==max) { prosjek=(float)br5*100/brojac;
                                                      printf("\nNajpopularnija boja je plava (%.2f%%).",prosjek); }
  }
  else { 
  	   prosjek=0; printf("\nNajpopularnija boja je crna (%.2f%%).",prosjek);
  }
                                                 
    return 0;
}


