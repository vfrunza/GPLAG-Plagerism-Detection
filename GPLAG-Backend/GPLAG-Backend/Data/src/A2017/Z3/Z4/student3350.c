#include <stdio.h>
void sort(int niz[],int k)
{
	int i,j,pom;
	for(i=0; i<k; i++) {
		for(j=i; j<k; j++) {
			if(niz[j]<niz[i]) {
				pom=niz[i];
				niz[i]=niz[j];
				niz[j]=pom;
			}
		}
	}
}
int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,k=0,niz[100];
	int maxi=0,c=1,broj=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			niz[k]=matrica[i][j];
			k++;
		}
	}
	sort(niz,k);
	for(i=0; i<k; i++) {
		for(j=i+1; j<k; j++) {
			if(niz[j]==niz[i])
				c++;
			else {
				break;
			}
		}
		if(c>maxi) {
			maxi=c;
			broj=niz[i];
		}
		c=1;
	}
	return broj;
}
int izbaci_kolone(int matrica[100][100],int visina,int sirina,int n)
{
	int i,j,b,k=0,p,niz1[100],t,l=0,nova[100],nova_matrica[100][100];
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina; j++) {
			if(matrica[i][j]==n) {
				if(k==0) {
					niz1[k]=j;
					k++;
				} else {
					t=1;
					for(b=0; b<k; b++) {
						if(j==niz1[b]) t=0;
					}
					if(t) {
						niz1[k]=j;
						k++;
					}
				}
			}
		}
	}
	for(i=0; i<visina; i++) {

		for(j=0; j<sirina; j++) {
			p=1;
			for(b=0; b<k; b++) {
				if(j==niz1[b]) {
					p=0;
				}
			}
			if(p) {
				nova[l]=matrica[i][j];
				l++;
			}
		}
	}
	l=0;
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina-k; j++) {
			nova_matrica[i][j]=nova[l];
			l++;
		}
	}
	for(i=0; i<visina; i++) {
		for(j=0; j<sirina-k; j++) {
			matrica[i][j]=nova_matrica[i][j];
		}
	}
	return (sirina-k);
}
int main()
{
	int i,j,t,k=1,mat[100][100],visina=0,sirina=0,broj;
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d",&sirina);
	scanf("%d",&visina);
	for(i=0; i<visina; i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0; j<sirina; j++) {
			scanf("%d",&mat[i][j]);
		}
	}
	broj=1;
	while(broj!=0) {
		t=max(mat,visina,sirina);
		broj=izbaci_kolone(mat,visina,sirina,t);
		if(broj!=0) {
			printf("\nNakon %d. prolaza matrica glasi:\n",k);
			for(i=0; i<visina; i++) {
				printf("   ");
				for(j=0; j<broj; j++) {
					if(mat[i][j]>9)
						printf("%d   ",mat[i][j]);
					else
						printf(" %d   ",mat[i][j]);
				}
				printf("\n");
			}
		}
		if(broj==0) {
			;
			printf("\nNakon %d. prolaza matrica je prazna!",k);
			return 0;
		}
		k++;
		sirina=broj;
	}
	return 0;
}
