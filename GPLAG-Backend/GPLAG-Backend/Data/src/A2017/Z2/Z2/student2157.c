#include <stdio.h>
#define n 100

int main(){
	int niz[n], A[n*3], finalni[n*3], velicina, i, br=1, j = 0, k=0, temp[10], x=0;
	printf("Unesite velicinu niza: ");
	scanf("%d", &velicina);
	printf("Unesite clanove niza: ");
	for(i = 0; i < velicina; i++) {
		scanf("%d", &niz[i]);
	}
	for(i = 0; i < velicina; i++) {
		j=0;
		if(niz[i]==0){
			temp[j]=0;
		}
		else if(niz[i]!=0){
		while(niz[i] != 0) {
			temp[j] = niz[i] % 10;
			niz[i] =niz[i] / 10;
			j++;
		}
		j--;}
		while(j != -1) {
			A[x]=temp[j];
			x++;
			j--;
		}
	}
	for(i = 0; i < x; i++) {
		finalni[k] = A[i];
		k++;
		br=1;
		while(i+1 != x && A[i] == A[i+1]) {
			br++;
			i++;
			if(i+1 == x) break;
		}
		finalni[k]=br;
		k++;
	}
	printf("Finalni niz glasi: \n");
	for(i = 0; i < k; i++) {
		printf("%d ", finalni[i]);
	}
	return 0;
}