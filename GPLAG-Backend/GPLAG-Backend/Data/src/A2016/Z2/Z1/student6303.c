#include <stdio.h>
#include <stdlib.h>
int main() {
	int x, pom, novi_broj=0, brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	pom=x/10;
	if(x%10==pom%10 && x%10!=0) brojac++;
	while(x!=0 && pom!=0) {
		novi_broj=abs(x%10-pom%10)+novi_broj*10;
		x=x/10;
		pom=pom/10;
	}
	pom=novi_broj;
	novi_broj=0;
	while(pom!=0) {
		novi_broj=novi_broj*10+pom%10;
		pom=pom/10;
	}
	if(brojac>0) {
		while(brojac!=0) {
			novi_broj=novi_broj*10;
			brojac--;
		}
	}
	printf("%d", novi_broj);
	return 0;
}
