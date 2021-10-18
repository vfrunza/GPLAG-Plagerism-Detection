#include <stdio.h>




int main() {
	
	int i, a, j;
	int velicina1;
	int niz1[1000];
	
	printf("Unesi velicinu niza: ");
	scanf("%d", &velicina1);
	
	
	for(i = 0; i < velicina1; i++){
		scanf("%d", &niz1[i]);
	
	
	
	for(j = 0; j < niz1[i]; j++){
		
		 do{
		a= j % 10;
		j/= 10;
		
		printf(j);
		}while(j > 0);
}
}
}
