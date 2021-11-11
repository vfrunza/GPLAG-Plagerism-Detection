#include <stdio.h>
int prost(int x) {
	int i;
	if(x<0) x=x*(-1);
	for(i=2;i<x-1;i++) {
		if(x%i==0) return 0;

	} return 1;
}
int daj_prost() {
	static int a=1;
	int i;
	for(i=a+1;;i++) {
		if(i==2) {
			a=i;
			return a;
		}
		if( i==3 || i==5 || i==7){
			a=i;
			return i;
		}
	else	if(prost(i)==1){
			a=i;
			return a;
		}
	}
}

int main(){
	int A,B,i,Suma=0;
	Linija:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if (A<1){ printf("A nije prirodan broj.\n"); goto Linija;}
	else if(A>=B) { printf("A nije manje od B.\n"); goto Linija;}
	int nova=0;
	for(i=0;nova<B;i++) {
		nova=daj_prost();
		if(nova>A && nova<B)
		Suma=Suma+nova;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,Suma);
	return 0;
}