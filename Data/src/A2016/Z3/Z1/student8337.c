#include <stdio.h>

int daj_prost(){
	static int x=1;
	int i;
	x++;
	for(i=2; i<=x/2; i++){
		if(x%i==0){
			i=2;
			x++;
			continue;
		}
	}
	return x;
}

int main() {
	int a, b, i, suma=0, m;
	
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d", &a);
		scanf("%d", &b);
		if(a>=b){
			printf("A nije manje od B.\n");
		}else{
			if(a<1){
				printf("A nije prirodan broj.\n");
			}else{
				if(b<1){
			    printf("B nije prirodan broj.\n");
			}
			}
		}
	}while(a<1 || b<1 || a>=b);
	
	m=daj_prost();
	for(i=a+1; i<b; i++){
		if(i>m){
			m=daj_prost();
			i--;
		}else if(i==m){
			suma+=m;
			m = daj_prost();
		}else continue;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
