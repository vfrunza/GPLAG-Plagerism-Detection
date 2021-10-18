#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, z, i, m=0, j=1,brojac=0,brojac1=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	z=n;
	while(z!=0)
	{
		brojac++;
		z=z/10;
	}
	if(brojac==1) {printf("0"); return 0;}
	while(n!=0)
	{
		i=abs(n%10-(n/10)%10);
		m=m+i*j;
		j=j*10;
		brojac1++;
		if(brojac1==brojac-1) break;
		n=n/10;
	}
	printf("%d", m);
	return 0;
}
