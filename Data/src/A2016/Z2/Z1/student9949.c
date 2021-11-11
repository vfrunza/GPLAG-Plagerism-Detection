#include <stdio.h>
#include <math.h>
int main() {
	float c1, c2;
	int n, S=0, b=1;
	printf("Unesite broj: ");
	scanf("%d", &n);
	c1=n%10;
	n=n/10; 
	while (n!=0)
    {c2=n%10;
    S=S+b*fabs(c1-c2);
    c1=c2;
    b*=10;
    n/=10;} 
    printf("%d", S);
    return 0;
}
	