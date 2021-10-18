#include <stdio.h>

int main() {
	int pocetni[100],n,br_cifre=0,cifre[1000],okrenut[30],duz_okrenut, b;
	int ponavljanje, trenutna_cifra;
	int i;
	int j;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
		
	}while(n < 0 || n > 100);
	printf("Unesite clanove niza: ");
	for (i=0; i<n; i++){
		br_cifre=0;
		do{
			scanf("%d", &b);
		}while(b<0);
		
		
		pocetni[i]=b;
	
	}
	
	for( i = 0; i < n; i++){
		if(pocetni[i] == 0){
			cifre[br_cifre] = 0;
			br_cifre ++;
		}else{
			duz_okrenut = 0;
			while(pocetni[i] != 0){
				okrenut[duz_okrenut] = pocetni[i] % 10;
				pocetni[i] /= 10;
				duz_okrenut ++;
			}
			for(j = duz_okrenut-1; j > -1; j --){
				cifre[br_cifre] = okrenut[j];
				br_cifre++;
			}
		}
	}
	printf("Finalni niz glasi:\n");
	i = 0;
	trenutna_cifra = cifre[0];
	ponavljanje = 1;
	while(i < br_cifre){
		trenutna_cifra = cifre[i];
		ponavljanje = 1;
		j = i + 1;
		while(j < br_cifre){
			if(cifre[j] != cifre[j-1]) break;
			ponavljanje++;
			j++;
		}
		i = j;
		printf("%d %d ", trenutna_cifra, ponavljanje);
	}
	
	
	
	return 0;
}
