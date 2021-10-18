#include <stdio.h>
#include <stdlib.h>

int main() {
int x,k,prva_c,druga_c,razlika,novi_br=0;
	printf("Unesite broj: ");
	scanf("%d", &x);
	if (x<0)
	x=abs(x);

    k=1;
    while(x>=10) {
	prva_c=x%10;
	druga_c=(x/10)%10;
	razlika=(abs(prva_c-druga_c))*k;
	k=k*10;
	x=x/10;
	novi_br+=razlika;
	}
	
	printf("%d", novi_br);

	return 0;
}
