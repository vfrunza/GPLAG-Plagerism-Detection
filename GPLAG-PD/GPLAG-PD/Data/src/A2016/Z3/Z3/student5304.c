#include <stdio.h>

int main() {
	int a,b;
	int m[200][200];
	int i,j,i1,j1,k;
	int provjera;
	int br=0;
	pocetak:
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &a,&b);
	if(a<=0 || b<=0 || a>200 || b>200) {
		printf("Brojevi nisu u trazenom opsegu.\n");
		goto pocetak;
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<a; i++) {
		for(j=0; j<b; j++) {
			scanf("%d",&m[i][j]);
		}
	}
	nastavak:
		provjera=1;
		for(i=0;i<a; i++) {
			for(j=1;j<a;j++) {
			if(m[i][0]==m[j][0]) {
				for(k=0;k<b; k++) {
					if(m[j][k]!=m[i][k]) {
						break;
					} else {
					br++;
					}
					if(br==b) {
						i1=i;
						j1=j;
						provjera=1;
					}
				}
			}
			}  
		}
		if(provjera==0) {
			for(i=j1; i<a-1;i++) {
				for(j=0;j<b;j++) {
					m[i][j]=m[i+1][j];
				}
			} 
			provjera=0;
			a--;
			goto nastavak;
		}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0; i<a; i++) {
		for(j=0; j<b; j++) {
			printf("%5d",m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
