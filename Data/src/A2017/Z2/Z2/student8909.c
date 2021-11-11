#include<stdio.h>

int main(){
	int niz[100];
	int izlazni[200];
	int n;
	
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	int i,j;
	for(i = 0; i < n; i++){
		scanf("%d", &(niz[i]));
	}
	int izlazniEl = 0; int k;
	for(i = 0; i < n; i++){
		int vecSeNalazi = 0;
		for(k = 0; k < izlazniEl; k+=2)
					if(izlazni[k] == niz[i])
						vecSeNalazi = 1;
		if(!vecSeNalazi){
					izlazni[izlazniEl++] = niz[i];
					int brojPonavljanja = 0;
					for( j = 0; j <n ; j++){
						if(niz[i] == niz[j]) 
							brojPonavljanja++;
					}
					izlazni[izlazniEl++] = brojPonavljanja;
		}
	}
	
	printf("Vas uneseni niz glasi: ");
	for(i = 0; i < izlazniEl; i++){
		printf("%d ",izlazni[i]);
	}
	return 0;
}