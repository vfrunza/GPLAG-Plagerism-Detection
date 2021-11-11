#include <stdio.h>

int main() {
	int niz[100];
	int n,i,br,vel,j;
	
	printf("Uneiste velicinu niza: ");
	scanf("%d", &n);
	
	printf("Uneiste clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}
	
	for(i=0; i<n; i++) {
		for(j=i; i<n;i++){
		while(niz[i]==niz[j+1]) {
		 br++;
		 n--;
		}
		vel=br;
		
		}
	}
	
	printf("Finalni niz glasi: ");
	for(i=0; i<n; i++) {
		printf("%d %d", niz[i],br);
	}

	return 0;
}
