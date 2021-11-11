#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, br1, brojac=0, rezultat=0, x=1, i;
    printf("Unesite broj: ");
    scanf("%d", &n);
    br1=n;
    while(br1!=0) {
    	br1=br1/10;
    	brojac++;
    }
   for(i=0; i<brojac-1; i++) {
   	rezultat=rezultat+x*(abs((n%10)-((n/10)%10)));
   	x=10*x;
   	n=n/10;
   }
	printf("%d", rezultat);

	return 0;
}