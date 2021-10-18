#include <stdio.h>
#include <stdlib.h>
int main() {
int n, br1, br2, m=0, d_jedinica=1;

printf("Unesite broj: ");
scanf("%d", &n);

do{
	if(n<0)
	n=abs(n);
	
	if(n<10)
	break;
	
	br1=n%10;
	n=n/10;
	br2=n%10;
	m=m+abs(br1-br2)*d_jedinica;
	d_jedinica*=10;

}while(n>=10);

printf("%d",m);

	return 0;
}
