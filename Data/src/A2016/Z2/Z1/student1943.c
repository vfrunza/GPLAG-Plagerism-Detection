#include <stdio.h>
#include<math.h>
int main() {
	int n,cifra=0,br=0,zamjena=0,rezultat=0,k=1,cifra2=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n*=-1;
	zamjena=n;
	while(n!=0) {
		n/=10;
		br++;
	}
	if(br==1) { printf("%d",0); return 0; }
	n=zamjena;
	while(n!=0) {
		cifra=n%10;
		n/=10;
		if(n==0) break;
		cifra2=cifra-n%10;
		if(cifra2<0) cifra2*=-1;
		rezultat=rezultat+cifra2*k;
		k*=10;
		
	}
	
	printf("%d",rezultat);
	return 0;
}
