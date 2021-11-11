#include <stdio.h>
int main(){
    float a,a1,b,e,c,d,i,j,k,l,o,h,p,w,m,nj,x;
   
   printf("Unesite broj n:");
 
  do{
   scanf("%f", &a);
  
   
    if(a<=0 || a>50){printf(" Pogresan unos"); 
        printf("\nUnesite broj n:");}}while(a<=0 || a>50);
        if(a>=1 && a<=50){
    b=1;
    h=1;
    c=2*a-5;
    d=1;
    x=2*a-5;
    nj=a;
   printf(" ");
   for(a1=1;a1<=h;a1++){printf("*");}
    for(e=1;e<=2*a-3;e++) {printf(" ");} printf("*");
    for(o=0;o<2*a-3;o++){printf(" ");}printf("*");printf("\n");
    
    for(i=0;i<a-2;i++){
        
        for(j=0;j<=i;j++){printf(" ");}
        printf("*");
        for(k=0;k<c;k++){printf(" ");}
        printf("*");c=c-2;
        for(l=0;l<2*i+1;l++){printf(" ");}
        printf("*");
        for(m=0;m<x;m++){
            printf(" ");
        } x=x-2;printf("*");
        
        b++;d++;
        printf("\n");}
      if(a>1){  for(p=1;p<nj;p++){printf(" ");}printf("*");for(w=1;w<=2*a-3;w++){printf(" ");}printf("*");
}
  }return 0;  }
