#include <stdio.h>

int main() {
	int i, j, velicina, niz[100]={0}, brojac, noviniz[100]={0}, diobroja;
	

	do{
	printf("Unesite velicinu niza: ");
	scanf("%d", &velicina);
	} while (velicina > 100 || velicina < 0);
	


	printf("Unesite clanove niza: ");
	for(i=0; i<velicina; i++){
		scanf("%d", niz[i]);
		if(niz[i]==0) {
			printf("Neispravna velicina!\n");
			niz[i]--;
			i--;
		}
	}
	
	
	for(i=0; i<velicina; i++){
		if(niz[i] > 9) {
			int(diobroja) = niz[i] % 10;
			noviniz[i] += diobroja;
	}
	
		printf("%d", diobroja);
	}
	
	printf("%d", diobroja);
	
	
	
	
	return 0;
}
