#include <stdio.h>

int main()
{
	int a[100][100];
	int b[100][100];
	int i,j;
	int mm1, mn1, mm2, mn2;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &mn1, &mm1);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<mm1; i++) {
		for(j=0; j<mn1; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &mn2, &mm2);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<mm2; i++) {
		for(j=0; j<mn2; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	int jednakost=1;
	if(mn1!=mm2) jednakost=0;
	else if(mm1!=mn2) jednakost=0;
	else {
		for(i=0; i<mn1; i++) {
			for(j=0; j<mm1; j++) {
				if(a[mm1-j-1][i] != b[i][j]){
					jednakost=0;
					break;
				}
			}
			if(!jednakost) break;
		}
	}
	
	if(jednakost) printf("DA");
	else printf("NE");
	printf("\n");


	return 0;
}
