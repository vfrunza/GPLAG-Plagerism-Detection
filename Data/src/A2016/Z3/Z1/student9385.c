#include <stdio.h>
int daj_prost() {
	static int a=1;
	int i=0;
	a++;
	for(i=2; i<a; i++)
	{
		
		
		if(a%i==0)
		{
			a++;
			i=1;
		}
		
	}
		
	    
	return a;
	
}


int main() {
	int A, B,i, suma=0,random;
	
	 do { 
	 	printf("Unesite brojeve A i B: ");
	 	scanf("%d", &A);
	 	scanf("%d", &B);
	 	
	 	if(A<=0 ){
		printf("A nije prirodan broj.\n");
         	}
	   else	if(A>=B)
		{
	
		printf("A nije manje od B.\n");}
		
		
		
		 }  while(A<=0 || A>=B || B<=0);
    
	for(i=A+1; i<B; i++)
	{
		random=daj_prost();
		if(random>A && random<B)
		{
			suma+=random;
		}
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B, suma);
   	return 0;
}













