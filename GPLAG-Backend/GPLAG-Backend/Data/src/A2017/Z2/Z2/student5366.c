#include <stdio.h>

int main() {
	int C[100];
	int niz[1000], pomocni[100];
	int novi[1000];
	int N, i, j, k;
	int c, vel;
	int brojac=1;
	
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &N);
	} while(N<0);
	printf("Unesite clanove niza: ");
	for(i=0; i<N; i++){
		scanf("%d", &C[i]);
	}
	j=0;
	k=0;
	for(i=0; i<N; i++){
		c=C[i];
		j=0;
		do{
			pomocni[j] = c%10;
			j++;
			c/=10;
		} while(c!=0);

		vel=j;
		for(j=vel-1; j>=0; j--){
			niz[k]=pomocni[j];
			k++;
		}
	}
	vel=k;
	k=0;
	for(i=0; i<vel; i++){
		brojac=1;
		for(j=i+1; j<vel; j++){
			if(niz[i]==niz[j]) {
				brojac++;
				
			}
			else break;
		}
		novi[k]=niz[i];
		k++;
		novi[k]=brojac;
		k++;
		i=j-1;
	}
	printf("Finalni niz glasi:\n");
	for(i=0; i<k; i++){
		printf("%d ", novi[i]);
	}
	
	return 0;
}
