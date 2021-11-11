#include <stdio.h>
#include <math.h>
	 int  daj_prost(){
	
		
		int i=2;
		static int  a=1;
	ponovo:
					a++;
			for(i=2;i<=sqrt(a);i++)	{
				if(a%i==0){
				goto ponovo;	
				}
			}
		return a;
	}
int main() {
	int i;
	int A,B,suma=0;
	int x;
	do		
		{
				printf("\nUnesite brojeve A i B:");
					scanf("%d %d", &A,&B);
				
			if(A>B)	{
				printf(" A nije manje od B.");
				continue;
			}	
			
			if(A<=0) {
				printf(" A nije prirodan broj.");
				continue;
			}
			
			if(A==B) {
				printf(" A nije manje od B.");
				continue;
			}
			
		}while(A>B || A<=0 || A==B);
			
	for(i=0; i<B; i++)	{
		
				x= daj_prost();
			if(x<A+1) {
				continue;
				
			}
			
			if(x>=A+1 && x<B){
				suma+=x;
			}
		
		
	}
			printf(" Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);

	
	
	
	return 0;
}