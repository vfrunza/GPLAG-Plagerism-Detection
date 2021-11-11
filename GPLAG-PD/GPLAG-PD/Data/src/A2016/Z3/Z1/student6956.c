#include <stdio.h>
#include <math.h>
int daj_prost() {
	int flag,i=2,x;
	static int n=2;
	do{
		flag=1;
		for(i=2;i<=sqrt(n);i++) {
			if(n%i==0) flag=0;
		}
		if(flag==1) {
			x=n;
			n++;
			return x;
		}
		n++;
	}while(flag==0);
}
int main() {
	int A,B,suma=0,i,x;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<=0) printf("A nije prirodan broj.\n");
		else if(A>=B) printf("A nije manje od B.\n");
	}while(A>=B || A<=0);
	for(i=0;i<B;i++) {
		x=daj_prost();
		if(x>A && x<B)
			suma+=x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
