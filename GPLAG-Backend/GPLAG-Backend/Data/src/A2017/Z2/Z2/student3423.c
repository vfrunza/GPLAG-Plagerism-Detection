#include <stdio.h>

int main() {
	
	double A[100];
	double brclanova;
	int i;
	

	do{
		printf("Unesite velicinu niza: ");
	scanf("%lf", &brclanova);
	
	}while(brclanova<0 && brclanova>100);
	
	if (brclanova<100) 
	printf("Unesite clanove niza: ");
	for (i=0; i<brclanova; i++){
	    scanf("%lf", &A[i]);
	}
	
	
	return 0;
	
}
