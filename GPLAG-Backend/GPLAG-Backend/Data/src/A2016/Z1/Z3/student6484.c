#include <stdio.h>

int main() {
	
	 char x; 
	 int brojac=0, brojacc=0, brojacb=0, brojacs=0, brojacv=0, brojacp=0; 
	 float p1,p2,p3,p4,p5;
	 printf("Unesite vozila: ");
   do {
   
   scanf("%c", &x);
   
   	if( x=='C' || x=='c') brojacc++; 
    else	if(x=='B' || x=='b') brojacb++;
   	else if(x=='S' || x=='s') brojacs++;
   	else if(x=='V' || x=='v') brojacv++;
   else	if(x=='P' || x=='p') brojacp++;
    else if(x=='K' || x=='k') break; 
    else 
    printf("Neispravan unos\n");
   	
   }
   while(x !='K' &&   x != 'k');
   
   brojac=brojacc+brojacb+brojacp+brojacv+brojacs;
   p1=((float)brojacc/brojac)*100; 
   p2=((float)brojacb/brojac)*100; 
    p3=((float)brojacs/brojac)*100; 
     p4=((float)brojacv/brojac)*100; 
      p5=((float)brojacp/brojac)*100; 
  
  printf("Ukupno je evidentirano %d vozila.\n",brojac);
  
  if(x==0){
      
      p1=0; 
      p2=0; 
      p3=0; 
      p4=0; 
      p5=0; 
      
  }
 else {
     if(p1>=p2 && p1>=p3 && p1>=p4 && p1>=p5)
     printf("Najpopularnija boja je crna (%.2f%%")
  
  
  return 0; }
  