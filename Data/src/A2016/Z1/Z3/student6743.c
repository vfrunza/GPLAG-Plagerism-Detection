#include <stdio.h>

int main() {

 char a;
 int ukupno=0,crna=0,bijela=0,siva=0,crvena=0,plava=0;
 float postotak;
 
 
 printf("Unesite vozila: ");
 
 
do  {
 	
 	scanf("%c",&a);
 	
    if(a=='C' || a=='c' || a=='B' || a=='b'|| a=='S' || a=='s' ||
    a=='V' || a=='v' || a=='P' || a=='p' )
     
     ukupno++;
         
     if(a!='C' && a!='c' && a!='B' && a!='b' && a!='S' && a!='s' && 
     a!='V' && a!='v' && a!='P' && a!='p' && a!='K' && a!='k')
       printf("Neispravan unos\n");
     
     if(a=='C' || a=='c') crna++;
     if(a=='B' || a=='b') bijela++;
     if(a=='S' || a=='s') siva++;
     if(a=='V' || a=='v') crvena++;
     if(a=='P' || a=='p') plava++;
 }
  while(a!='K' && a!='k');
  
   printf("Ukupno evidentirano %d vozila.",ukupno);
   
   
   if(ukupno==0){ printf("\nNajpopularnija boja je crna (0.00%%).");
   return 0;}
   
   if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
   	
    postotak=100.*crna/ukupno;
   	printf("\nNajpopularnija boja je crna (%.2f%%).",postotak);
   	return 0;
   }
 
   if(bijela>=crna && bijela>=siva && bijela>=crvena && bijela>=plava){
   	
   	postotak=100.*bijela/ukupno;
   	printf("\nNajpopularnija boja je bijela (%.2f%%).",postotak);
   	return 0;
   }

  if(siva>=crna && siva>=bijela && siva>=crvena && siva>=plava){
  	
  	postotak=100.*siva/ukupno;
  	printf("\nNajpopularnija boja je siva (%.2f%%).",postotak);
  	return 0;
  }
  
  if(crvena>=crna && crvena>=bijela && crvena>=siva && crvena>=plava){
  	
  	postotak=100.*crvena/ukupno;
  	printf("\nNajpopularnija boja je crvena (%.2f%%).",postotak);
  	return 0;
  }

  if(plava>=crna && plava>=bijela && plava>=siva && plava>=crvena){
  	
  	postotak=100.*plava/ukupno;
  	printf("\nNajpopularnija boja je plava (%.2f%%).",postotak);
  	return 0;
  }


return 0;
}
