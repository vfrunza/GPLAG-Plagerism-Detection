#include <stdio.h>

int max(int mat[100][100],int visina, int sirina) {
	int i,j,element=0,maxelement=0,max=0,k,l,brojac=0;
	for(i=0;i<visina;i++) {
		for(j=0;j<sirina;j++) {
			brojac=0;
			element=mat[i][j];
			for(k=0;k<visina;k++) {
				for(l=0;l<sirina;l++) {
					if(mat[k][l]==element) {
						brojac++;
					}
				}
			}
			if(brojac>max) {
				maxelement=element;
				max=brojac;
			}
			else if(brojac==max) {
				if(element<maxelement) {
					maxelement=element;
					max=brojac;
				}
			}
		}
	}
	return maxelement;
	return 0;
}

int izbaci_kolone(int mat[100][100],int visina,int sirina,int N) {
	int a,b;
	int brojkolona1=sirina;
	int(*pok1)[100],(*pok2)[100];
	pok1=mat;
	while (pok1!=mat+visina) {
 	for(b=0;b<brojkolona1;b++) {
		if((*pok1)[b]==N) {
			if(b==brojkolona1-1);
			else {
				pok2=mat;
				while(pok2!=mat+visina) {
					for(a=b;a<brojkolona1;a++) {
						(*pok2)[a]=(*pok2)[a+1];
					}
				pok2++;
				}
				b--;
			}
			brojkolona1--;
			}
		}
	pok1++;
	}
	return brojkolona1;
}
int main() {
	int v,s,i,j,matrica[100][100],N,a=0,brojkolona,temp;
	do {
		printf("Unesite sirinu i visinu matrice: ");
		scanf("%d%d",&s,&v);
	} while (v<0 || v>100 || s<0 || s>100);
	brojkolona=s;
	for(i=0;i<v;i++) {
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<s;j++) {
			scanf("%d",&matrica[i][j]);
		}
	}
	while(brojkolona!=0) {
		a++;
		N=max(matrica,v,brojkolona);
		brojkolona=izbaci_kolone(matrica,v,brojkolona,max);
		if(brojkolona==0) printf("\nNakon %d. prolaza matrica je prazna!",a);
		else printf("\nNakon %d. prolaza matrica glasi: \n",a);
		for(i=0;i<v;i++) {
			for(j=0;j<brojkolona;j++){
				printf("\n%5d",matrica[i][j]);
			}
		}
	} 
	return 0;
}
