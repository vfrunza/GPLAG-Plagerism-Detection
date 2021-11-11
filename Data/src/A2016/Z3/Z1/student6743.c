#include <stdio.h>

int daj_prost(){
	
 int i,kaunter;
 static  int x=2;
       
      for(;;){ 
      	kaunter=0;
      	for(i=1;i<x;i++)
      		if(x%i==0) kaunter++;
      		if(kaunter==1) return x++;
      		
      		else if(kaunter!=1)x++;
      	
      }   
   
    
}

int main() {
	
	int A,B,suma=0,i,f;
	
	do{
	
	printf("\nUnesite brojeve A i B: ");
	
	scanf("%d %d",&A,&B);
	
	if(A<=0) printf("A nije prirodan broj.");
	if(A>=B) printf("A nije manje od B.");
	
	} while(A>=B || A<=0 );
	
	for(i=0;i<B;i++){
		 f=daj_prost();
		
		 if(f>A && f<B) suma+=f;
		}
		
		printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
		

	return 0;
}

	


