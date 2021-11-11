#include <stdio.h>
#include <math.h>

int main() {
	int n , Nr1, Nr2d, rezultat=0, k=0;
	
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n < 0){
		
		n = fabs(n);
	} else if (n <= 0 && n > 10){
		rezultat = 0;
	}
	
	while(n >= 10){
		
		Nr1 = n % 10;
		
		Nr2d = (n/10) % 10;
		
		rezultat = fabs(Nr1 - Nr2d)*pow(10, k) + rezultat;
		
		
		k = k+1;
		
		n = n/10;
		
	}
	
	printf("%d", rezultat);
		
	return 0;
}
