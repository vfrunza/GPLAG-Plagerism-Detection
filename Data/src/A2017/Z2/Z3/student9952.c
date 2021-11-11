#include <stdio.h>
#include <math.h>
int main()
{
	int r,c,red,kolona,i,j,t=1;
	double a[100][100],b[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&c,&r);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			scanf("%lf",a[i]+j);
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&kolona,&red);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<red; i++) {
		for(j=0; j<kolona; j++) {
			scanf("%lf",b[i]+j);
		}

	}
	/*provjerim da li je uopste mogu ispitati*/
	if(red==r&&kolona==c&&red==c||r==kolona&&red==c) {
		for(i=0; i<r; i++) {
			for(j=0; j<c; j++) {
				/*umjesto da je zarotiram, samo cu koordinate zarotirat i provjeriti tako*/
				if(!(fabs(a[i][j]-b[j][r-1-i])<0.00001)) {
					t=0;
					break;
				}
			}
		}
		if(t==1)printf("DA");
		else
			printf("NE");
	} else
		printf("NE");
	return 0;
}
