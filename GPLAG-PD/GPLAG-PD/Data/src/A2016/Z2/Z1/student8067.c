#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,pr,dr,k=0,d=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n>=1&&n<10) { printf("0 "); return 0;}
	if(n<10) goto modul;
	while(n>=10) 
	{ modul: n=abs(n);
		pr=n%10;
		dr=(n/10)%10;
		k+=abs(pr-dr)*d;
		d*=10;
		n/=10;
	}
	
	printf("%d",k);
	return 0;
}
