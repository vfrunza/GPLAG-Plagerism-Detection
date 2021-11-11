#include <stdio.h>
int main() {
	int matA[100][100],matB[100][100],matC[100][100],redovi,kolone,i,j,m,n,element;
	int nizB[100],nizC[100],k=0,t=0,velB=0,velC=0;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&redovi,&kolone);
	} while(redovi<0 || redovi>100 || kolone<0 || kolone>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			scanf("%d",&matA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			scanf("%d",&matB[i][j]);
		}
	}
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			nizB[k]=matB[i][j];
			k++;
			velB++;
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			scanf("%d",&matC[i][j]);
		}
	}
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			nizC[t]=matC[i][j];
			t++;
			velC++;
		}
	}
	for(i=0;i<redovi;i++) { 
		for(j=0;j<kolone;j++) {
			element=matA[i][j];
			for(m=0;m<velB;m++) {
				if(element==nizB[m]) {
					for(n=m;n<(velB-1);n++) nizB[n]=nizB[n+1];
					velB--;
					m=velB;
				}
			}
		}
	}
	for(i=0;i<redovi;i++) {
		for(j=0;j<kolone;j++) {
			element=matA[i][j];
			for(m=0;m<velC;m++) {
				if(element==nizC[m]) {
					for(n=m;n<(velC-1);n++) nizC[n]=nizC[n+1];
					velC--;
					m=velC;
				}
			}
		}
	}
	if(velB==0 && velC==0) printf("DA\n");
	else printf("NE\n");
	return 0;
}
