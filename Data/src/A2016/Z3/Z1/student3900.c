#include <stdio.h>

int daj_prost (){
	static int prost=2;
	int i, prosti_broj=0;
	for(i=2;i<=prost;i++){
		
		if((prost%i==0)&&(prost==i)){
			prosti_broj=prost;
			break;
		}else if((prost%i==0)&&(prost!=i)){
			prost++;
			i=2;
		}
	}
	prost++;
	return prosti_broj;
}

int main() {
	int a, suma=0, prost=0, b, i;
	
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		
		if(a>=b){
			printf("A nije manje od B.");
			printf("\n");
			
		}else if(a<=0){
			printf("A nije prirodan broj.");
			printf("\n");
			
		}else if(b<=0){
			printf("B nije prirodan broj.");
			printf("\n");
		}
	}while(a>=b || a<=0 || b<=0);

	for(i=0;i<b;i++){
		prost=daj_prost();
		if(prost>a && prost<b){
		suma=suma+prost;
		}else if(prost>b) break;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
