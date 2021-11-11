#include <stdio.h>
#include <stdlib.h>

int main() {
	int k=1,n,p,d,razlika=0, novi=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
while(n>=10)
{
	p=n%10;
	d=(n/10)%10;
	
	razlika=abs(p-d);
	
	novi+=razlika*k;
	k*=10;
	n/=10;
}	
	printf("%d", novi);
	return 0;
}
