#include <stdio.h>
#define el 10
int suma_cifara(int broj) {
	int suma=0;
	while (broj!=0) {
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}

void ubaci (int niz[]) {
	int i,j, br_el;
	for (i=0; i<br_el; i++) {
		for(j=br_el+i; j>i++; j--) {
			niz[j] = niz[j-1];
		}
		niz[i+1]=suma_cifara(niz[i]);
		i++;
		br_el++;
	}
}
int main()
{
	int niz[20], i;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++) {
		scanf("%d ", &niz[i]);
	}
	ubaci(niz);
	
	printf("Modificirani niz glasi: ");
	for (i=0; i<el-1; i++)
		{
			printf("%d ", niz[i]);
		}
	printf("%d.", niz[el-1]);
	return 0;
}