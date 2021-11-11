#include <stdio.h>

int main() {
	char w;
	int c=0, b=0,s=0,v=0,p=0,suma, brojac=0,z,max;
	float postotak;
 printf("Unesite vozila: ");
for(z=1; z<=10000000; z++)
{  scanf("%c", &w);
   
   if (w=='c' || w=='C')
{      c++;
brojac++;
	
}
 if (w=='b' || w=='B') 
{        b++; 
brojac++;
}
    if (w=='s' || w=='S')
{         s++;
brojac++;
    	
 }
 if (w=='v' || w=='V')
{
    	v++;
    	brojac++;
    	
}
if (w=='p' || w=='P') 
{         p++;
brojac++;
   	
 }
 
 if (w=='k' || w=='K') { break;
     
 }
 
    if (w!='c' && w!='C' && w!='b' && w!='B' && w!='s' && w!='S' && w!='V' && w!='v' && w!='p' && w!='P')
    
{ printf("Neispravan unos \n");}


}
 
 printf("Ukupno evidentirano %d vozila.\n", brojac);
 
 max=c;
 if (s>max) {max=s; }
 if (b>max) {max=b;}
 if (v>max) { max=v; }
 if (p>max) { max=p; }
 
 
   
   postotak=((float)max/brojac)*100;
   
   if (brojac==0) { printf("Najpopularnija boja je crna (0.00%).");
   return 0;
   }
   
   
  if (c>=s && c>=b && c>=v && c>=p ) {  printf("Najpopularnija boja je crna (%0.2f%).", postotak);
      
  }
  
   else if (b>c && b>=s && b>=v && b>=p ) {   printf("Najpopularnija boja je bijela (%0.2f%).", postotak);
      
  }
   else if (s>c && s>b && s>=v && s>=p) {    printf("Najpopularnija boja je siva (%0.2f%).", postotak);
       
   }
   else if (v>c && v>b && v>s && v>=p) {    printf("Najpopularnija boja je crvena (%0.2f%).", postotak);
       
   }
   else if (p>c && p>s && p>v && p>b) {        printf("Najpopularnija boja je plava (%0.2f%).", postotak);
   }
   
   
   
   
   
   
   
	

	return 0;
}
