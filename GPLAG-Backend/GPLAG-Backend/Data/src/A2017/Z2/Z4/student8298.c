#include <stdio.h>

int main()
{			
	int matA[100][100], matB[100][100], matC[100][100], A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, Am1, Am2, Am3, Am4, Am5, Am6, Am7, Am8, Am9, Am10;
	int  B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10, Bm1, Bm2, Bm3, Bm4, Bm5,  Bm6, Bm7, Bm8, Bm9, Bm10, C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, Cm1, Cm2, Cm3, Cm4, Cm5, Cm6, Cm7, Cm8, Cm9, Cm10;
	int i, j, M, N;
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M, &N);
	} while (M<0 || N<0);


	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++){
			
				scanf("%d", &matA[i][j]);
			
		
			if (matA[i]==0) {
				A0++;
			}
			if (matA[i]==1) {
				A1++;
			}
			if (matA[i]==2) {
				A2++;
			}
			if (matA[i]==3) {
				A3++;
			}
			if (matA[i]==4) {
				A4++;
			}
			if (matA[i]==5) {
				A5++;
			}
			if (matA[i]==6) {
				A6++;
			}
			if (matA[i]==7) {
				A7++;
			}
			if (matA[i]==8) {
				A8++;
			}
			if (matA[i]==9) {
				A9++;
			}
			if (matA[i]==10){
				A10++;
			}
			if (matA[i]==-1) {
				Am1++;
			}
			if (matA[i]==-2) {
				Am2++;
			}
			if (matA[i]==-3) {
				Am3++;
			}
			if (matA[i]==-4) {
				Am4++;
			}
			if (matA[i]==-5) {
				Am5++;
			}
			if (matA[i]==-6) {
				Am6++;
			}
			if (matA[i]==-7) {
				Am7++;
			}
			if (matA[i]==-8) {
				Am8++;
			}
			if (matA[i]==-9) {
				Am9++;
			}
			if (matA[i]==-10){
				Am10++;
			}
		}
	}

	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			
				scanf("%d", &matB[i][j]);
			
			if (matB[i]==0) {
				B0++;
			}
			if (matB[i]==1) {
				B1++;
			}
			if (matB[i]==2) {
				B2++;
			}
			if (matB[i]==3) {
				B3++;
			}
			if (matB[i]==4) {
				B4++;
			}
			if (matB[i]==5) {
				B5++;
			}
			if (matB[i]==6) {
				B6++;
			}
			if (matB[i]==7) {
				B7++;
			}
			if (matB[i]==8) {
				B8++;
			}
			if (matB[i]==9) {
				B9++;
			}
			if (matB[i]==10) {
				B10++;
			}
			if (matB[i]==-1) {
				Bm1++;
			}
			if (matB[i]==-2) {
				Bm2++;
			}
			if (matB[i]==-3) {
				Bm3++;
			}
			if (matB[i]==-4) {
				Bm4++;
			}
			if (matB[i]==-5) {
				Bm5++;
			}
			if (matB[i]==-6) {
				Bm6++;
			}
			if (matB[i]==-7) {
				Bm7++;
			}
			if (matB[i]==-8) {
				Bm8++;
			}
			if (matB[i]==-9) {
				Bm9++;
			}
			if (matB[i]==-10) {
				Bm10++;
			}
		}
	}
	printf("Unesite clanove matrice C:");
	for(i=0; i<M; i++) {
		for(j=0; j<N; j++) {
			
				scanf("%d", &matC[i][j]);
			
			if (matC[i]==0) {
				C0++;
			}
			if (matC[i]==1) {
				C1++;
			}
			if (matC[i]==2) {
				C2++;
			}
			if (matC[i]==3) {
				C3++;
			}
			if (matC[i]==4) {
				C4++;
			}
			if (matC[i]==5) {
				C5++;
			}
			if (matC[i]==6) {
				C6++;
			}
			if (matC[i]==7) {
				C7++;
			}
			if (matC[i]==8) {
				C8++;
			}
			if (matC[i]==9) {
				C9++;
			}
			if (matC[i]==10) {
				C10++;
			}
			if (matC[i]==-1) {
				Cm1++;
			}
			if (matC[i]==-2) {
				Cm2++;
			}
			if (matC[i]==-3) {
				Cm3++;
			}
			if (matC[i]==-4) {
				Cm4++;
			}
			if (matC[i]==-5) {
				Cm5++;
			}
			if (matC[i]==-6) {
				Cm6++;
			}
			if (matC[i]==-7) {
				Cm7++;
			}
			if (matC[i]==-8) {
				Cm8++;
			}
			if (matC[i]==-9) {
				Cm9++;
			}
			if (matC[i]==-10) {
				Cm10++;
			}
		}
	}
	if(B0==A0 && C0==A0 && B1==A1 && C1==A1 && B2==A2 && C2==A2 && B3==A3 && C3==A3 && B4==A4 && C4==A4 && B5==A5 && C5==A5 && B6==A6 && C6==A6 && B7==A7 && C7==A7 && B8==A8 && C8==A8 && B9==A9 && C9==A9 && B10==A10 && C10==A10 && Bm1==Am1 && Cm1==Am1 && Bm2==Am2 && Cm2==Am2 && Bm3==Am3 && Cm3==Am3 && Bm4==Am4 && Cm4==Am4 && Bm5==Am5 && Cm5==Am5 && Bm6==Am6 && Cm6==Am6 && Bm7==Am7 && Cm7==Am7 && Bm8==Am8 && Cm8==Am8 && Bm9==Am9 && Cm9==Am9 && Bm10==Am10 && Cm10==Am10) {
		printf("DA\n");
	} else printf("NE\n");

	return 0;
}
