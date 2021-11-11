#include <stdio.h>

int prost (int x){
    int i;
    if(x==1) return 0;
    for(i = 2 ; i < x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int daj_prost(){
    static int n=0;
   while(1){
       n++;
       if(prost(n)) return n;
   }
}

int main() {
  int a, b, suma=0, n, i;
  do {
  	printf("\nUnesite brojeve A i B: ");
  	
  	scanf("%d%d",&a,&b);
  	
  	if( a <= 0 ) printf("A nije prirodan broj.");
  	
  	else if( a >= b) printf("A nije manje od B.");
    
  	
  	 } while(a >= b || a <= 0);
  	 
  	 
  	 
  	 
  	 
  	    n=daj_prost();
  	    while(n<=a) n=daj_prost();
  	        
  	        for(i=a+1  ; i<b ; i++){
  	            if(i==n) {suma+=i;
  	            n=daj_prost();}
  	        }

    printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
  
 
  
  
  return 0;
  
}
