#include <stdio.h>

int main() {
	int n, i, j=0, niz1[10], niz2[10], k=0;
	char matrica[20][20];
	while(2>1){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>0 && n<11)
		break;
		if(n<=0 || n>10)
			printf("Pogresan unos\n");
	}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			matrica[i][j]=' ';
		}
	}
	j=0;
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d%d", &niz1[i], &niz2[j]);
		
		
		if((niz1[i]<0 || niz1[i]>19) || (niz2[j]<0 || niz2[j]>19)){
			printf("Pogresan unos\n");
			i--;
			j--;
		}
		j++;
	}
	for(i=0; i<n; i++){
		for(j=0; j<20; j++){
			for(k=0; k<20; k++){
				if(j==niz2[i] && k==niz1[i])
					matrica[j][k]='*';
			}
		}
	}
	for(j=0; j<20; j++){
		for(k=0; k<20; k++){
			printf("%c", matrica[j][k]);
		}
		printf("\n");
	}
	
	return 0;
}
