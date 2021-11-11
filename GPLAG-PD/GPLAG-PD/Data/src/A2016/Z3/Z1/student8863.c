#include <stdio.h>

int daj_prost(){
	int i, prost=1;
	static int n=2;
	if(n==2){
		n++;
		return n-1;
	}
	else{
		for(i=2; i<n; i++){
			if(n%i==0){
				prost=0;
				break;
			}
		}
		while(prost==0){
				n++;
				prost=1;
				for(i=2; i<n; i++){
					if(n%i==0){
						prost=0;
						break;
					}
				}
		}
		n++;
		return n-1;
	}
}
int main() {
	int i, a, b, suma=0, x;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a<1)
			printf("A nije prirodan broj.\n");
		else if(b<=a)
			printf("A nije manje od B.\n");
	}while(a<1 || a>=b);
	
	for(i=0; i<b; i++){
		x=daj_prost();
		if(x>a && x<b){
			suma+=x;
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	return 0;
}
