#include <stdio.h>

int DaLiJeProst (int a){
	int b=1,i;
	for (i=2;i<a;i++){
		if (a%i==0) { 
			a=0;
			break;
		}
	}
	return a;
}

int daj_prost (){
	static int x=1;
	while (1){
		if (DaLiJeProst(++x)) return x;
	}
}

int main() {
	int a,b,i,suma=0,broj,c,d;
	do{
		printf("Unesite brojeve A i B: ");
		scanf ("%d%d",&a,&b);
		if (a<=0)
			printf ("A nije prirodan broj.\n");
		else if (a>=b)
			printf ("A nije manje od B.\n");
	}while (a<=0 || a>=b);
	
	c=a;
	d=b;
	
	for (;;){
		broj=daj_prost();
		if (broj>=d) break;
		else if (broj>c)
			suma+=broj;
	}
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
