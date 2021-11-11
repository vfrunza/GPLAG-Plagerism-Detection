#include <stdio.h>

int dalijeprost(int x){
	int i;
	for(i=2;i<x;i++){
	if(x%i==0) return 0;
}
return 1;
}

int daj_prost() {
	long int static st=1;
	long int i;
	for(i=st;i<100000;i++){
		if(i==st) continue;
		if(i==2){ st=2; return st;
	}
	if(i>st){
	if(dalijeprost(i)){ st=i; return st;}
	}
}
}
	
	


int main() {
	int a,b,i;
	int suma=0;
	unos:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<1) { printf("A nije prirodan broj.\n");
	goto unos;}
	if(a>=b) { printf("A nije manje od B.\n");
	goto unos;}
	
	for(i=0;i<b;i++){
		int prost=daj_prost();
		if(prost>a && prost<b) suma+=prost;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
