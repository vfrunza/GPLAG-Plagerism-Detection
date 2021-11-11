#include <stdio.h>

int main() {
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int pomocniA[10010];
	int pomocniB[10010];
	int pomocniC[10010];
	int M,N;
	int i,j,temp;
	
	do {
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
		
	}while(M<0 || M>100 || N<0 || N>100 );
	
	/* Unos matrice A */
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d",&A[i][j]);
		}
	}
	/* Unos matrice B */
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d",&B[i][j]);
		}
	}
	/* Unos matrice C */
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			scanf("%d",&C[i][j]);
		}
	}
	
			/* UBACUJEM MATRICE U NIZOVE */
	
	int brojac = 0;
	
	for(i=0;i<M;i++) {
		for(j=0;j<N;j++) {
			pomocniA[brojac] = A[i][j];
			pomocniB[brojac] = B[i][j];
			pomocniC[brojac] = C[i][j];
			brojac++;
		}
	}
		/* SORTIRANJE NIZOVA */
				
	int min;
	
	/* NIZ A */
	for(i=0;i<brojac;i++) {
		min = i;
		for(j=i+1;j<brojac;j++) {
			if(pomocniA[j]<pomocniA[min])
				min = j;
		}
		temp = pomocniA[i];
		pomocniA[i] = pomocniA[min];
		pomocniA[min] = temp;
	}
	/* NIZ B */
	for(i=0;i<brojac;i++) {
		min = i;
		for(j=i+1;j<brojac;j++) {
			if(pomocniB[j]<pomocniB[min])
				min = j;
		}
		temp = pomocniB[i];
		pomocniB[i] = pomocniB[min];
		pomocniB[min] = temp;
	}
	/* NIZ C */
	for(i=0;i<brojac;i++) {
		min = i;
		for(j=i+1;j<brojac;j++) {
			if(pomocniC[j]<pomocniC[min])
				min = j;
		}
		temp = pomocniC[i];
		pomocniC[i] = pomocniC[min];
		pomocniC[min] = temp;
	}
	
	/* Poređenje nizova */
	
	int isti = 1;
	for(i=0;i<brojac;i++) {
		if(pomocniA[i]!=pomocniC[i] || pomocniA[i]!=pomocniB[i]) {
			isti=0;
			break;
		}
	}
	
	if(isti==1) 
		printf("DA");
	else
		printf("NE");
	return 0;
}
