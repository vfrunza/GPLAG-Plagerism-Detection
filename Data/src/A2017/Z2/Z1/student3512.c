#include <stdio.h>

int main() {
	
	int n;
	
	do {
		
		scanf("%d", &n);
		if ((n%4==0) && (n>=8)) {
			printf("Pogresan unos. ");
		}
	}
	
	while ((n%4!=0) || (n<8));
	
	
	return 0;
}
