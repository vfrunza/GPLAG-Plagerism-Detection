#include <stdio.h>

int daj_prost () {
	int i, j, prost=1;
	static int a=0, izl=1, slucaj=-1;
	i=++izl;
	while(i>0) {
		prost=1;
		for(j=i-1;j>1;j--) 
		if(i%j==0) prost=0;
		if(prost==1) slucaj++;
		if(a==slucaj) {
			izl=i;
			a++;
			break;
		}
		i++;
	}
	return izl;
}

int main(){
	int A, B, i, suma=0, niz[10000];
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while (A<=0 || B<=0 || B<=A) {
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(B<=A) printf("A nije manje od B.\n");
	else if(B<=0) printf("B nije prirodan broj.\n");
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	}
	for(i=0;i<1000;i++) {
		niz[i]=daj_prost();
		if(niz[i]>=B) break;
		else if(niz[i]<=A) continue;
		suma+=niz[i];

	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
	
}



