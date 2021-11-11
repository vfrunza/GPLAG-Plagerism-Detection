#include <stdio.h>

int daj_prost(){
	 static int a=2;
	 int prost=1,i;
	  for(i=2;i<a;i++){
	  	if(a%i==0) prost=0;
	  }
	  if(prost==1)return a++;
	  else{
	  	
	  	while(prost==0){
	  		a++;
	  		prost=1;
	  		for(i=2;i<a;i++){
	  			if(a%i==0)prost=0;
	  		}
	  		
	  	}
	  	if(prost==1)return a++;
	  }
	  return 0;
}


int main() {
	
	int A,B;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d",&A);
	scanf("%d",&B);
	if(A>=B)printf("A nije manje od B.\n");
	else if(A<1)printf("A nije prirodan broj.\n");
	else if (B<1) printf("B nije prirodan broj.\n");
	}while(A<1 || B<1 || A>=B);
	
	int b,i;
	int suma=0;
    for(i=A;i<B;i++){
    	b=daj_prost();
    if(b>A && b<B)suma+=b;
    }
   
    printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	
	return 0;
}
