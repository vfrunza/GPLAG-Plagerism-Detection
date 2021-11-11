#include <stdio.h>
#include <stdlib.h>
int main() {
	int x, n, m=0, b=1;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if(x<0) x=abs(x);
	if(x>9) while(x>9){
		n=abs((x%10)-((x/10)%10));
		m=b*n+m;
		x=x/10;
		b=b*10;
	}
	printf("%d", m);
	return 0;
}
