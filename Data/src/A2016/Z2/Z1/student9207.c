#include <stdio.h>
#include <math.h>


int main() {
int k=1,n,prva,druga,broj=0;

printf("Unesite broj: ");

scanf("%d",&n);
while (fabs(n)>=10){
	prva=n%10;
	
	druga=(n/10)%10;
	broj+=(fabs(prva-druga)*k);
	k*=10;
	n/=10;
	
}

printf("%d",broj);


return 0;
}
