#include <stdio.h>

int main() {
	
	char ime[5];
	int i;
	printf("Unesite svoje ime: ");
	
	for(i = 0;i<100;i++) {
		
		scanf("%c", &ime[i]);
	
	}
	

	printf("Dobrodosao: ");
	
	for( i =0;i<100;i++) {
		
		printf("%c", ime[i]);
	}
	
return 0;
}
