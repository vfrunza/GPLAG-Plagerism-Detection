#include <stdio.h>
int daj_prost(){
	static int x=2;
	int i;
	for (;;){
	for(i=2;i<x;i++){
 if(x%i==0){
 	x++;
 	break;}
	}
	if(i==x) return x++;
	}
}

int main() {
	int A, B,i;
	unsigned long int sum=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&A,&B);
	if(A<=0) printf("A nije prirodan broj.\n");
	else if (A>=B) printf("A nije manje od B.\n");
	else if(B<=0) printf("B nije prirodan broj.\n"); 
	}while(A<=0 || A>=B || B<=0);
	for (i=0;i<=B;i++){
	int x=daj_prost();
	if(A<x && x<B){
	sum=sum+x;}
}
	printf("Suma prostih brojeva izmedju %d i %d je %lu.",A,B,sum);
	return 0;
}
