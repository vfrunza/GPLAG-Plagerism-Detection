#include <stdio.h>

int main() {
	int m=0,n=0,i=0,j=0,cirkularna=1,teplicova=1,niz[100],matrica[100][100]={{0}},cirkularna_matrica[100][100],duzina_niza;
	do{
	printf("Unesite M i N: ");
	scanf("%d",&m);
	scanf("%d",&n);
		if(m<1 || n<1 || m>100 || n>100)printf("Pogresan unos!\n");
	}while(m<1 || n<1 || m>100 || n>100);
	duzina_niza=n;
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(j=0;j<n-1;j++){
			if(matrica[i][j]!=matrica[i+1][j+1])teplicova=0;
		}
	}
	for(i=0;i<n;i++){
		niz[i]=matrica[0][i];
	}

	for(i=0;i<n;i++){
		cirkularna_matrica[0][i]=niz[i];
	}
	for(i=1;i<m;i++){
		int x=niz[duzina_niza-1],k;
	   for(k=duzina_niza-1;k>0;k--){
	   	niz[k]=niz[k-1];
	   	
	   }
	   niz[0]=x;
		
		for(j=0;j<n;j++){
			cirkularna_matrica[i][j]=niz[j];
		}
	}
	
	for(i=0;i<m;i++){
		
		for(j=0;j<n;j++){
			if(matrica[i][j]!=cirkularna_matrica[i][j])cirkularna=0;
		}
	}
	if(cirkularna==1)printf("Matrica je cirkularna");
	else if(teplicova==1)printf("Matrica je Teplicova");
	else if(teplicova==0 && cirkularna==0)printf("Matrica nije ni cirkularna ni Teplicova");
	
	return 0;
}
