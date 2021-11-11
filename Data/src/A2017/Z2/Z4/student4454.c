#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100];
	int A1[1000],B1[1000], C1[1000];
	int m,n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m, &n);
	} while (m>100 || m<0 || n>100 || n>100);
	printf("Unesite clanove matrice A: ");
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &B[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &C[i][j]);
		}
	}
	int brojac=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			A1[brojac]=A[i][j];
			brojac++;
		}
	}
	int min,temp;
	for(i=0;i<brojac;i++){
		min=i;
		for(j=i+1;j<brojac;j++){
			if (A1[j]<A1[min]) min=j;
		}
		temp=A1[i];
		A1[i]=A1[min];
		A1[min]=temp;
	}
	brojac=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			B1[brojac]=B[i][j];
			brojac++;
		}
	}
	for(i=0;i<brojac;i++){
		min=i;
		for(j=i+1;j<brojac;j++){
			if(B1[j]<B1[min]) min=j;
		}
		temp=B1[i];
		B1[i]=B1[min];
		B1[min]=temp;
	}
	brojac=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			C1[brojac]=C[i][j];
			brojac++;
		}
	}
	for(i=0;i<brojac;i++){
		min=i;
		for(j=i+1;j<brojac;j++){
			if(C1[j]<C1[min]) min=j;
		}
		temp=C1[i];
		C1[i]=C1[min];
		C1[min]=temp;
	}
	int broj=0;
	for(i=0;i<brojac;i++){
		if(A1[i]==B1[i] && A1[i]==C1[i]) broj++;
		else {
			printf("NE");
			break;
		}
	}
	if(broj==brojac) printf("DA");
	return 0;
}
