#include <stdio.h>

int main()
{
	int a,b,c,d,i,j,v1,k1,v2,k2,p;
	int matA[10][10],matB[10][10],matC[10][10];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&k1,&v1);

    printf("Unesite clanove matrice A: ");
	for(a=0; a<v1; a++) {
		for(b=0; b<k1; b++) {
			scanf("%d", &matA[a][b]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&k2,&v2);

printf("Unesite clanove matrice B: ");
	for(c=0; c<v2; c++) {
		for(d=0; d<k2; d++) {
			scanf("%d", &matB[c][d]);
		}
	}

	if (v1!=k2 || v2!=k1)
		{
			printf("NE\n");
		}
		
    else if(v1==k1) {
	
	for(i=0; i<v1; i++) {
		for(j=0; j<k1; j++) {
			matC[j][v1-i-1]=matA[i][j];
		}
	}

	p=1;
	for (i=0; i<v1; i++) {
		for (j=0; j<k1; j++) {
			if (matC[i][j] != matB[i][j]) {
				p=0;
				break;
			}
		}
		if (p==0) {
			break;
		}
	}

	if (p==1) {
		printf ("DA\n");
	} else {
		printf ("NE\n");
	}
	
	}
	
	else {
	
	for(i=0; i<v1; i++) {
		for(j=0; j<k1; j++) {
			matC[j][v1-i-1]=matA[i][j];
		}
	}

	p=1;
	for (i=0; i<k1; i++) {
		for (j=0; j<v1; j++) {
			if (matC[i][j] != matB[i][j]) {
				p=0;
				break;
			}
		}
		if (p==0) {
			break;
		}
	}

	if (p==1) {
		printf ("DA\n");
	} else {
		printf ("NE\n");
	}
	
	}
	
	return 0;
}
