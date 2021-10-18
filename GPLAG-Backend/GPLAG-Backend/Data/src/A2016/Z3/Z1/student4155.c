#include <stdio.h>

int daj_prost(){
	static int prost=1;
	int i,k=0;
	//prost++;
	for(;;){
		prost++;
		k=0;
		for(i=2;i<prost;i++){
			if(prost%i==0){
				k++;
				break;
			}
		}
		if(k==0){
			break;
		
		}
	}
	return prost; 
}

int main() {
	int A,B,i,suma=0,prost;
	
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A,&B);
	if(A<1)printf("A nije prirodan broj.\n");
	if(A>=B)printf("A nije manje od B.\n");
	}while(A<1 || A>=B);
	
	
	for(;;){
      prost=daj_prost();
	 if(prost>A && prost <B) 			
			suma=suma+prost;
        if(prost>B) break;}
			
			printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
			
			return 0;
			
	}

	
	
	
	
	
