#include <stdio.h>
#include <math.h>
#define BR_EL 100
#define MAX 1000
int main() {
	int niz[BR_EL], ispis[MAX] = {0}, br_cifara[BR_EL] = {0}, i, m, a, velicina = 0;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &m);
	}while(m < 1 || m > 100);
	printf("Unesite clanove niza: ");
	for(i = 0; i < m; i++){
		scanf("%d", &niz[i]);
		do{
			br_cifara[i]++;
		}while((int)(niz[i] / pow(10,br_cifara[i])));
	}
	for(i = 0; i < m; i++){
		 a = niz[i];		
		 do{
		 	if(velicina > 0 && a/(int)(pow(10, br_cifara[i] - 1)) == ispis[velicina - 2]) ispis[velicina - 1]++;
		 	else{
		 		velicina += 2;
		 		ispis[velicina - 2] = a/(int)(pow(10, br_cifara[i] - 1));
		 		ispis[velicina - 1]++;
		 	}
		 	a %= (int)(pow(10, br_cifara[i] - 1));
		 	br_cifara[i]--;
		 }while(br_cifara[i] > 0);
	}
	printf("Finalni niz glasi:\n");
	for(i = 0; i < velicina; i += 2)
			 	printf("%d %d ", ispis[i], ispis[i+1]);
	return 0;
}
