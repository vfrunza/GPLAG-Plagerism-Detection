#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 4");*/
	int a[100][100], b[100][100], c[100][100];
	int niza[10000], nizb[10000], nizc[10000];
	int m, n, i, j, brojac=0, duzinaNiza, maxa, maxb, maxc, tempa, tempb, tempc; 
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n);
	} while(m>100 || m<0 || n<0 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<m; i++) { 
		for(j=0; j<n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			niza[brojac]=a[i][j];
			nizb[brojac]=b[i][j];
			nizc[brojac]=c[i][j];
			brojac++;
		}
	}
	duzinaNiza=m*n;
	for(i=0; i<duzinaNiza; i++) {
		maxa=i;
		maxb=i;
		maxc=i;
		for(j=i+1; j<duzinaNiza; j++) {
			if(niza[j]>niza[maxa]) {
				maxa=j;
			}
			if(nizb[j]>nizb[maxb]) {
				maxb=j;
			}
			if(nizc[j]>nizc[maxc]) {
				maxc=j;
			}
		}
		tempa=niza[i];
		niza[i]=niza[maxa];
		niza[maxa]=tempa;
		
		tempb=nizb[i];
		nizb[i]=nizb[maxb];
		nizb[maxb]=tempb;
		
		tempc=nizc[i];
		nizc[i]=nizc[maxc];
		nizc[maxc]=tempc;
	}
	for(i=duzinaNiza; i>0; i--) {
		if(niza[i-1]!=nizc[i-1] || niza[i-1]!=nizb[i-1]) {
			printf("NE\n");
			return 0;
		}
	}
	printf("DA\n");
	return 0;
}
