#include <stdio.h>

int main() {
 char F;
 int i=0,CB=0,BB=0,SB=0,VB=0,PB=0;
  float cb,bb,sb,vb,pb,tc,tb,ts,tv,tp;
  printf("Unesite vozila: ");
   do{
   scanf("%c", &F);
     if((F=='c' || F=='C')||(F=='b' || F=='B')||(F=='s' || F=='S')||(F=='v' || F=='V')||(F=='p' || F=='P')){
     i=i+1;
  if(F=='c' || F=='C'){
   CB++;
  }if(F=='b' || F=='B'){
   BB++;
  }if(F=='s' || F=='S'){
   SB++;
  }if(F=='v' || F=='V'){
   VB++;
  }if(F=='p' || F=='P'){
   PB++;
    }
     }else if(F=='k'||F=='K'){
     }else if(F=='\n'){
     }else{
    printf("Neispravan unos");
    printf("\n");
     }
  }while (F!='k'&&F!='K');
   printf("Ukupno evidentirano %d vozila.", i);
   if(i==0){
    
    printf("\nNajpopularnija boja je crna (0.00%%).");
   }else{
 tc=CB;
 tb=BB;
 ts=SB;
 tv=VB;
 tp=PB;
 cb=(tc/i)*100;
 bb=(tb/i)*100;
 sb=(ts/i)*100;
 vb=(tv/i)*100;
 pb=(tp/i)*100;
 if((tc>=tb)&&(tc>=ts)&&(tc>=tv)&&(tc>=tp)){
    printf("\nNajpopularnija boja je crna (%.2f%%).", cb);
    
 }else if((tb>tc)&&(tb>=ts)&&(tb>=tv)&&(tb>=tp)){
    printf("\nNajpopularnija boja je bijela (%.2f%%).", bb);
    
 }else if((ts>tc)&&(ts>tb)&&(ts>=tv)&&(ts>=tp)){
    printf("\nNajpopularnija boja je siva (%.2f%%).", sb);
    
 }else if((tv>tc)&&(tv>tb)&&(tv>ts)&&(tv>=tp)){
    printf("\nNajpopularnija boja je crvena (%.2f%%).", vb);
 
 }else if((tp>tc)&&(tp>tb)&&(tp>ts)&&(tp>tv)){
    printf("\nNajpopularnija boja je plava (%.2f%%).", pb);
 }
   }
 return 0;
}
