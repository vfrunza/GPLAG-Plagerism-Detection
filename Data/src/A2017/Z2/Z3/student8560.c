#include <stdio.h>
int main() {
	double matA[10][10],matB[10][10],rotirana[10][10],pomocna;
	int i,j,koloneA,koloneB,redoviA,redoviB,redoviRotirane,koloneRotirane,iste=1;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&koloneA,&redoviA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<redoviA;i++) {
		for(j=0;j<koloneA;j++) {
			scanf("%lf",&matA[i][j]);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&koloneB,&redoviB);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<redoviB;i++) {
		for(j=0;j<koloneB;j++) {
			scanf("%lf",&matB[i][j]);
		}
	}
	redoviRotirane=koloneA;
	koloneRotirane=redoviA;
	/* Da bi matrice bile jednake moraju imati isti broj redova i isti broj kolona */ 
	if(redoviRotirane!=redoviB || koloneRotirane!=koloneB) {
		printf("NE\n");
		return 0;
	}
	/* Da bi dobili rotiranu matricu prvo pravimo transponovanu */
	for(i=0;i<redoviRotirane;i++) {
		for(j=0;j<koloneRotirane;j++) {
			rotirana[i][j]=matA[j][i];
		}
	}
	/* a zatim transponovanoj obrnemo kolone */ 
	for(i=0;i<redoviRotirane;i++) {
		for(j=0;j<koloneRotirane/2;j++) {
			pomocna=rotirana[i][j];
			rotirana[i][j]=rotirana[i][koloneRotirane-1-j];
			rotirana[i][koloneRotirane-1-j]=pomocna;
		}
	}
	for(i=0;i<redoviRotirane;i++) {
		for(j=0;j<koloneRotirane;j++) {
			if(rotirana[i][j]!=matB[i][j]) {
				iste=0;
				break;
			}
		}
	}
	if(iste==1) printf("DA\n");
	else printf("NE\n");
	return 0;
}
