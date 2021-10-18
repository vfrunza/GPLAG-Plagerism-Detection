#include <stdio.h>
#include <math.h>
int main() {
	int n,C1,C2,S,k;
    printf("Unesite broj: ");
    scanf("%d",&n);
    C1=n%10;
	n=n/10;
	k=1;
	S=0;
	while(n!=0){
		C2=n%10;
		S=S+k*fabs(C1-C2);
		k*=10;
		n/=10;
		C1=C2;
	} printf("%d",S);
	return 0;
}
