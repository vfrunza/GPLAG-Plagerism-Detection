#include <stdio.h>
int prost(int n){
	int pret=1,i;
	for(i=2; i<n; i++){
		if(n%i==0){
			pret=0;
		}
	}
	if(pret)
	return 1;
	return 0;
}
int daj_prost(){
	static int a=1;
	a++;
	while(prost(a)==0)
	a++;
	return a;
}
int saberi(int a, int b){
	int suma=0,i,j;
	for(i=0; i<b; i++){
		j=daj_prost();
		if(j>a && j<b)
		suma+=j;
	}
	return suma;
}


int main() {
	int A,B;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d", &A,&B);
		if(A<=0)
		printf("A nije prirodan broj.\n");
		if(A>=B)
		printf("A nije manje od B.\n");
	}while(A<=0 || A>=B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,saberi(A, B));
	return 0;
}
