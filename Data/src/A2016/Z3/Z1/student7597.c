#include <stdio.h>



int DaLiJeProst(int t){
	int brojac=0;
	int i;
	for(i=1; i<t; i++){
		if(t%i==0) brojac++;
	}
	if(brojac==1) return 1;
	else return 0;
}

int daj_prost(){
	static int x=2;
	while(1){
		if(DaLiJeProst(x)==1){
			return x++;
		}
		x++;
	}
}


int main() {
	int a,b,i,suma=0;
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &a, &b);
		if(a<=0){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(a>=b){
			printf("A nije manje od B.\n");
			continue;
		}
		break;
	}
	
	while(1){
		i=daj_prost();
		if(i>a && i<b) suma+=i;
		if(i>b) break;
	}	
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	
	
	
	return 0;
}
