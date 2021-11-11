#include <stdio.h>
int daj_prost(){
	static int prost=1;
	int i,slozen;

	do{
		prost++;
		slozen=0;
		for (i=2;i<prost;i++){
			if (prost%i==0){
				slozen=1;
				break;
			}
		}
	} while(slozen);
	return prost;
}

int main(){
	int A,B,suma=0,novi_prost;
	do{
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if (A<1) {printf("A nije prirodan broj.");
		continue;}
		if (A>=B) printf("A nije manje od B.");
	} while(A<1 || A>=B);
	
	do{
		novi_prost=daj_prost();
		if (novi_prost>A && novi_prost<B) {suma=suma+novi_prost;}
		
	} while(novi_prost<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	
	return 0;
}