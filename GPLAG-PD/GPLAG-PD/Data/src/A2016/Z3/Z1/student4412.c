#include <stdio.h>

int DaLiJeProst(int n){
	int i;
	if(n==2) return 1;
	if(n==1) return 0;
	for(i=2; i<n; i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int daj_prost(){
	static int c=1;
	do{
		c++;
	}
	while(DaLiJeProst(c)==0);
	return c;
}

int main() {
	int A, B, i;
	int uslov=0;
	int suma=0;
	while(uslov==0){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<1){
			printf("A nije prirodan broj.\n");
			continue;
		}
		else if(A>=B){
			printf("A nije manje od B.\n");
			continue;
		}
		uslov=1;
	}
	for(i=0; i<B; i++){ 
		int pom=daj_prost();
		if(pom>A && pom<B) suma+=pom;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
