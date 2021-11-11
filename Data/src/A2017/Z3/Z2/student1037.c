#include <stdio.h>
#include <math.h>
float zaokruzi1(float zaokruzi, int niz[]){
	int i;
	int n;
	for(i=0; i<n; i++){
	
	zaokruzi = round(niz[i]*10) / 10;
	
	return zaokruzi;
	}
}

int main() {
	
	int i;
	int n;
	int niz[1000];
	int zaokruzi;
	
	printf("Unesi broj n\n");
	scanf("%d", &n);
	printf("\nUnesi niz \n");
	for(i=0; i<n; i++){
		scanf("%f", &niz[i]);
	}
	printf(zaokruzi);
	
	
}
