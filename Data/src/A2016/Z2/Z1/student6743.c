#include<stdio.h>
#include<stdlib.h>

int main(){
  
  int broj,cifra,novibroj=0,cifra1,novacifra,i=1;
  
  printf("Unesite broj: ");
  scanf("%d",&broj);
  
  if(broj<0) broj=abs(broj);
  
  
  cifra=broj%10;
  broj=broj/10;
  
  while(broj>=1){
    
    cifra1=broj%10;
    novacifra=abs(cifra-cifra1);
    cifra=cifra1;
    broj=broj/10;
    novibroj=novibroj+novacifra*i;
    i=i*10;
    }
  
  printf("%d",novibroj);
  
  return 0;
}