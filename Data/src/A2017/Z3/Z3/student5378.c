#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre(int *p1, int x, int *p2, int y) {
	int niz[10];
	int i,j,k,t,broj,vel,stepen=1,indeks;
	
	for (j=0;j<y;j++) {
			if (p2[j]<0 || p2[j]>9) return 0;
			for (k=j+1;k<y;k++) {
				if (p2[j]==p2[k]) return 0;
		}
	}

	for(i=0;i<x;i++) {
		broj=p1[i];
		/* rastavljam broj na cifre i slazem u niz[10] */
		j=0;
		while (broj!=0) {
			niz[j]=broj%10;
			broj/=10;
			j++;
		}
		vel=j;
		/* izbacivanje clanova (koji se nalaze u nizu p2[]) iz niza niz[] */
		
		for (j=0;j<vel;j++) {
			for (t=0;t<y;t++) {
				if (abs(niz[j])==p2[t]) {
					indeks=j;
					while (indeks<vel-1) {
						niz[indeks]=niz[indeks+1];
						indeks++;
					}
					vel--;
					j--;
					break;
				}
			}
			
		}
		/* niz p1[] sa novim clanovima gdje su izbacene odgovarajuce cifre */
		stepen=1;
		p1[i]=0;
		for (t=0;t<vel;t++) {
			p1[i]+=niz[t]*stepen;
			stepen*=10;
		}
	}
	return 1;
}
int main() {
	return 0;
}
