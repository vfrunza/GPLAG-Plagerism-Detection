#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, i=1, pc, dc, nb=0;
	printf("Unesite broj: ");
	scanf("%d", &a);
	if (a<0){ 
	 	a=abs(a);
	}
	while (a >= 10) { 
		pc=a%10;
		dc=(a/10)%10;
		nb=nb+abs(dc-pc)*i;
		i=i*10;
		a=a/10;
	}
	
	printf("%d", nb);
	return 0;
}
