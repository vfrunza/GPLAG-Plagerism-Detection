#include <stdio.h>

int main() {
	int niz1[100],niz2[1000],i,n;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	do{
		
	for(i=0;i<n;i++){
		scanf("%d",&niz1[i]);
		
	}
		
	} while(niz1[i]>=0);
	for(i=0;i<n;i++){
		printf("Niz[i]:%d ",&niz1[i]);
		
	}
	
	return 0;
}
