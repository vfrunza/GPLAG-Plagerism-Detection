#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, m ,w, a = 0, i = 0, j = 0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	w = abs(n);
	if(abs(n) <= 9)
	 printf("0");
	else if (abs(n) > 9){
		n = abs(n);
		while(n != 0){
			n = n / 10;
			i++;
		}
		for(j = 0; j < i - 1; j++){
			m = w % 10;
			w = w / 10;
			m = abs((m - (w % 10))) * pow(10, j);
			a += m;
		}
		printf("%d", a);
	}
	
	return 0;
}
