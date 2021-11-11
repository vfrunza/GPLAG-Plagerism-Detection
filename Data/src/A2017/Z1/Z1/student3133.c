#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int farey(double niz[],int vel,int n);
	double niz[100]={0};
	int n=0,i,p=0;
	printf("Do kojeg stepena treba traziti elemente farejevog niza: ");
	scanf("%d", &n);
	p=farey(niz,100,n);
		for(i=0;i<p;i++){
			printf("%.5f ",niz[i]);
		}
	return 0;
}
 
 int farey(double niz[],int vel,int n){
	typedef struct { int d, n; } farej;
	farej f1 = {0, 1}, f2 = {1, n}, t;
	int k, brojac=0;
	niz[brojac++]=0;
	niz[brojac++]=1./n;
	printf("%d/%d %d/%d", 0, 1, 1, n);
	while (f2.n > 1&&brojac<vel) {
		k = (n + f1.n) / f2.n;
		t = f1, f1 = f2, f2 = (farej) { f2.d * k - t.d, f2.n * k - t.n };
		printf(" %d/%d", f2.d, f2.n);
		niz[brojac++]=(double)f2.d/f2.n;
	}
 
	putchar('\n');
	niz[brojac]=1;
return brojac;
}

