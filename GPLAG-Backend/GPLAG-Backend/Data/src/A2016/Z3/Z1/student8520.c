#include <stdio.h>

int prost(int x){
	int i;
	
	for(i=2; i<x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}

int daj_prost(){
	
	static int broj = 1;
	int i;
	
	for(i=broj+1;;i++){
		if(prost(i)){
			broj = i;
			return broj;
		}
	}
}
 
int main() {
	int a,b;
	int suma = 0;
	int br = 0;
	
	while(1){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		
		if(a>0 && b>0 && a<b)break;
		else if(a<=0) printf("A nije prirodan broj.\n");
		else if(a>=b) printf("A nije manje od B.\n");
	}
	
	br = daj_prost();
	
	while(br < b){
		if(br>a) suma += br;
		br=daj_prost();
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.\n",a,b,suma);
	return 0;
}
