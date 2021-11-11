#include <stdio.h>

int main() {
 char n;
 float procenat;
 int brojac=0,brc=0,brb=0,brs=0,brv=0,brp=0;
 
 printf("Unesite vozila: ");
 
 do
 {
     scanf("%c" , &n);
     
     if(n=='k' || n=='K')
     break;
     
     else if(n=='c' || n=='C')
     { brojac++ ; brc++; }
     
     else if(n=='b' || n=='B')
     { brojac++ ; brb++; }
     
     else if(n=='s' || n=='S')
     { brojac++ ; brs++; }
     
     else if(n=='v' || n=='V')
     { brojac++ ; brv++; }
     
     else if(n=='p' || n=='P')
     { brojac++ ; brp++; }
     
     else if(n!='k' && n!='K' && n!='c' && n!='C' && n!='b' && n!='B' && n!='s' && n!='S' && n!='v' && n!='V' && n!='p' && n!='P') 
     {printf("Neispravan unos\n"); }
     
     
 } while(n!='k' && n!='K');
 
 
 printf("Ukupno evidentirano %d vozila.\n", brojac);
 
if(brojac!=0)

 {
  
  
 if(brc>=brb && brc>=brs && brc>=brv && brc>=brp)
{ procenat= (float) brc*100/brojac; 
 printf("Najpopularnija boja je crna (%.2f%)." ,procenat); }
 
else if(brb>=brc && brb>=brs && brb>=brv && brb>=brp)
{ procenat= (float) brb*100/brojac; 
 printf("Najpopularnija boja je bijela (%.2f%)." ,procenat); }
 
 else if(brs>=brc && brs>=brb && brs>=brv && brs>=brp)
{ procenat= (float) brs*100/brojac; 
 printf("Najpopularnija boja je siva (%.2f%)." ,procenat); }
 
 else if(brv>=brc && brv>=brs && brv>=brb && brv>=brp)
{ procenat= (float) brv*100/brojac; 
 printf("Najpopularnija boja je crvena (%.2f%)." ,procenat); }
 
 else if(brp>=brc && brp>=brs && brp>=brv && brp>=brv)
{ procenat= (float) brp*100/brojac; 
 printf("Najpopularnija boja je plava (%.2f%)." ,procenat); }
 

}

else printf("Najpopularnija boja je crna (0.00%).");


 
 
	return 0;
}
