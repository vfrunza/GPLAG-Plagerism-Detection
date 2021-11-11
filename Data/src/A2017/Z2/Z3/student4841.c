#include <stdio.h>

int main() {
	int v1,s1,v2,s2, a[100][100], b[100][100], ar[100][100];
	int i=0, j=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &s1, &v1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<v1; i++){
		for(j=0; j<s1; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &s2, &v2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<v2; i++){
		for(j=0; j<s2; j++){
			scanf("%d", &b[i][j]);
		}
	}
	for(i=0; i<v1; i++){
		for(j=0; j<s1; j++){
			ar[j][v1-1-i]=a[i][j];
		}
	}
	if(v1==s2 && v2==s1){
		for(i=0; i<s1; i++){
			for(j=0; j<v1; j++){
				if(b[i][j]!=ar[i][j]){
					printf("NE");
					return 0;
				}
			}
		}
		printf("DA");
	}
	else{
		printf("NE");
	}
	return 0;
}
