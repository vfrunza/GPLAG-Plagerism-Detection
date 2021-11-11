#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Unesite broj: ");
	scanf("%d", &n);
if(n<0) n=abs(n);
int zadnja,predzadnja;
zadnja=n%10;
n/=10;
if(n==0){ printf("0"); return 0; }
predzadnja=n%10;
int k=10;
int novi=fabs(zadnja-predzadnja);
while (n>0)
{
	zadnja=n%10;
	n/=10;
	if(n==0) break;
	predzadnja=n%10;
	novi=novi+(fabs(zadnja-predzadnja))*k;
	k*=10;
	
}
printf("%d",novi);
	return 0;
}
