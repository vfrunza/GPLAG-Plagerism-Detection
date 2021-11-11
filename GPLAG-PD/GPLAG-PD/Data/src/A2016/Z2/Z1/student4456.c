#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int c,d,n,f;
	int suma=0;
	int br=-1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0)
		n=abs(n);
	while(n!=0){
		c=n%10;
		n=n/10;
		if(n==0)
			break;
		d=n%10;
		br++;
		f=c-d;
		if(f<0)
			f=abs(f);
		suma=suma+pow(10,br)*f;
		
}
	printf("%d",suma);

	return 0;
}
