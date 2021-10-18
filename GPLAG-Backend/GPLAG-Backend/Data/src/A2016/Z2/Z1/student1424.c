#include <stdio.h>
#include <math.h>

int main() {
	int n, cifra,c1,rez,nb=0,k=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=-9 && n<=9){
		printf("0");
		return 0;
	}
	if(n<0){
		n=(-1)*n;
	}
	while (n/10>0){
		cifra=n%10;
		n=n/10;
		c1=n%10;
		rez=cifra-c1;
		if (rez<0){
			rez=(-1)*rez;
		}
		nb=rez*pow(10,k)+nb;
		k++;
	}
	printf("%d",nb);
	return 0;
}
