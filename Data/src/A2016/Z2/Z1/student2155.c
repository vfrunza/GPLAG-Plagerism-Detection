#include <stdio.h>
#include <stdlib.h>
int main() {
	int a,b,c,d,cifra,suma,r,i,j;
	suma = 0;
	cifra = 0;
	i = 1;
	j = 1;
	printf("Unesite broj: ");
	scanf("%d" , &a);
	r = a;
	do{
		r/=10;
		cifra++;
	}while(r);
	while(i < cifra){
		i++;
		b = a%10;
		a = a/10;
		c = a%10;
		d = abs(b - c);
		d  = j*d;
		j*=10;
		suma+=d;
		}
		printf("%d",suma);
	return 0;
}
