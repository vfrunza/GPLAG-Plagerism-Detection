#include <stdio.h>

int main() {
	
	int velicina, niz[10000], i = 0, pomocni_niz[10000], j = 0,cifra, brojac_cifara =  0, finalni[1010], ponavljanje, velicina2 = 0;
	
	// unosenije velicne, koja ne moze biti negativna niti 0
	printf("Unesite velicinu niza: ");
	do{
		scanf("%d", &velicina);
		
	}while(velicina <= 0);
	
	printf("Unesite clanove niza: ");
	
	//ubacivanje elemenata u pocetni niz, samo prirodni brojevi ulaze u obzir
	
	do{ 
		scanf("%d", &niz[i]);
		if( niz[i] < 0 ) i--;
		i++;
	}while ( i < velicina);
	

i = velicina-1;
		do{
			do{
			cifra = niz[i] % 10;
			pomocni_niz[j] = cifra;
			niz[i] = niz[i]/10;
			
			brojac_cifara++;
			
		//	pomocni_niz[j] = cifra;
			j++;
			
			}while(niz[i]!=0);
			i--;

		}while( i >=0);

	//for(i=0; i<brojac_cifara; i++) printf("%d ", pomocni_niz[i]);

i = 0;
j = 0;
		do{
		//	finalni[j] = pomocni_niz[i]; 
		//	j++;
			ponavljanje = 1;
			do{
				if(i==brojac_cifara-1) break;
				if((pomocni_niz[i] == pomocni_niz[i + 1])&& (i < brojac_cifara - 1)){
				ponavljanje++;
				i++;}
				else break;
			}while( i < brojac_cifara);
			i++;
			finalni[j] = ponavljanje;
			j++;
			finalni[j] = pomocni_niz[i - 1];
			j++;
			
			velicina2 = velicina2 + 2;

		//	j++;
			
		}while( i < brojac_cifara);
	
	printf("Finalni niz glasi:\n");
	for (i = velicina2- 1; i >= 0; i--){
			printf("%d ", finalni[i]);
	}

	return 0;
}