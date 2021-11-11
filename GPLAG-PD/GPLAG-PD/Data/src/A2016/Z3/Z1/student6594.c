#include <stdio.h>

int prost(int n){
   
int i;

    for(i=2;i<=n/2;i++){
        if(n%i==0)
        return 0;
    }

    return 1;
}

 int daj_prost(){
     static int n=2;
        int m;
        
     while(1){
     if(n==2){
         n++;
         m=n-1;
         return m;
     }
         
         
         if(prost(n)==1)
         return n++;
         else n++;
              
               }
}

int main() {
int sumaProstih=0;
int i=0;
int broj=0;
int a,b;

do {
    printf("Unesite brojeve A i B: ");
scanf("%d %d",&a,&b);

if(a<=0)
printf("A nije prirodan broj.\n");
else if(a>=b)
printf("A nije manje od B.\n");
} while(a<=0 || a>=b);

do{
    broj=daj_prost();
  }
  while (broj<a);
  
  for(i=a;i<b;i++){
    if(broj>a && broj<b)
    sumaProstih+=broj;
        broj=daj_prost();
      
  }



printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,sumaProstih);

	return 0;
}
