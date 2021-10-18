#include <stdio.h>
#define duzina 20

int main() {
	int mat[duzina][duzina];
	int i, j, y[duzina], x[duzina], a, k, br=12;
	
	
	printf ("Unesite broj tacaka: ");
	scanf ("%d", &a);
	
	while (a>10 || a<=0){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf ("%d", &a);
	}
	
	for (i=0;i<a;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &y[i], &x[i]);
		if (x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19){
		printf("Pogresan unos\n");
		i--;
		} 
	}
	
	for(i=0;i<duzina;i++){
		for(j=0;j<duzina;j++){
			for(k=0;k<a;k++){
						
			if (i==x[k] && j==y[k]) {printf ("*"); br=142; break;}
			}
			if (br==12) printf(" ");
			br=12;
		}
			printf("\n");
		}
	
	return 0;
}
