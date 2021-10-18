#include <stdio.h>

int main() {
 int s=0, crna=0, bijela=0, siva=0, crvena=0, plava=0,nu=0,i;
 float crna1,bijela1,siva1,crvena1,plava1;
 char a;
printf("Unesite vozila: ");
 do{
  scanf("%c",&a);
  
  if(a=='C' || a=='c'){
   crna++;
   s++;
  }else if(a=='B' || a=='b'){
   bijela++;
   s++;
  }else if(a=='S' || a=='s'){
   siva++;
   s++;
  }else if(a=='V' || a=='v'){
   crvena++;
   s++;
  }else if(a=='P' || a=='p'){
   plava++;
   s++;
  }else if((a!='k') && (a!='p') && (a!='P') && (a!='V') && (a!='v') && (a!='S') && (a!='s') && (a!='B') && (a!='b') && (a!='C') && (a!='c')){
   nu++;
  }
 }while(a!='k');
 
   if(nu!=0){
   for (i=0; i<nu; i++){
    printf("Neispravan unos\n");
   }
  }
 
 printf("Ukupno evidentirano %d vozila.\n",s);
 
 if(s!=0){
 
 crna1=100.00*crna/s;
 bijela1=100.00*bijela/s;
 siva1=100.00*siva/s;
 crvena1=100.00*crvena/s;
 plava1=100.00*plava/s;
 }else{
  crna1=0;
  bijela1=0;
  siva1=0;
  crvena1=0;
  plava1=0;
 }
 
 
  if(crna>=bijela && crna>=siva && crna>=crvena && crna>=plava){
 printf("Najpopularnija boja je crna (%.2f%%).",crna1);
}if(bijela>crna && bijela>=siva && bijela>=crvena && bijela>=plava){
 printf("Najpopularnija boja je bijela (%.2f%%).",bijela1);
}if(siva>crna && siva>bijela && siva>=crvena && siva>=plava){
 printf("Najpopularnija boja je siva (%.2f%%).",siva1);
}if(crvena>crna && crvena>siva && crvena>bijela && crvena>=plava){
 printf("Najpopularnija boja je crvena (%.2f%%).",crvena1);
}if(plava>bijela && plava>crna && plava>siva && plava>crvena){
 printf("Najpopularnija boja je plava (%.2f%%).",plava1);
}
	return 0;
}
