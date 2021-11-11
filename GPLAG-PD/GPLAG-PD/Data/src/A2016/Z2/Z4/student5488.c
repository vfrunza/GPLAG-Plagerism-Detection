#include <stdio.h>

int main() {
	/*printf("Zadaća 2, Zadatak 4");*/
	
	double matrica [100][100];
	int m,n,i,j,k;
	int cirkularna,teplicova;
	double red[200];
	double kolona [100];
	cirkularna=1; teplicova=1;
	int broj,brojac,index;
	brojac=0;broj=0;
	int a;
	double f;
	
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!\n");
	}while(m>100 || m<=0 || n>100 || n<=0);
	
	 printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		scanf("%lf",&matrica[i][j]);
	/*if( n==1 || m==1){ 	printf("Matrica je cirkularna");return 0;}	*/
		
		for(i=0;i<n;i++)
		red[i]=matrica[0][i];
		for(i=n;i<2*n;i++){
			red[i]=matrica[0][brojac];
			brojac++;
		}
		

	for( j=0;j<n;j++){
		
		/*trazenje indexa*/
	/*	for(i=2*n-1;i>=0;i--){
			if(matrica[0][j]==red[i]) {index=i; break;}
		}*/
	index=(n-1)+j+1;
		/*uzimanje n-1 brojeva ispred indeksa iz niza*/
		broj=0;
		for(k=index;k>index-m;k--){
			kolona[broj]=red[k];
			broj++;
		}
		for(a=0;a<m;a++){
			if(matrica[a][j]==kolona[a]){ cirkularna=1;}
			else{cirkularna=0;break;}
		}
	if(cirkularna==0) break;
	}
	
	k=0;
	/*	for(i=0;i<n;i++) printf("%d",kolona[i]);*/
	
	if(cirkularna==1){
		printf("Matrica je cirkularna");return 0;
	}
	
	/*ispitivanje teplicove matrice*/
	broj=0;
	for(i=0;i<n;i++){
	
		f=matrica[broj][i];

		while(++broj<m && ++i<n){
			if(f!=matrica[broj][i]){
				teplicova=0; printf("Matrica nije ni cirkularna ni Teplicova"); return 0;
			}
			
		}
		
	}
	broj=0;
	for(i=1;i<m;i++){
		f=matrica[i][broj];
			while(++i<m && ++broj<n){
			if(f!=matrica[i][broj]){
				teplicova=0; printf("Matrica nije ni cirkularna ni Teplicova"); return 0;
			}
		}}
	if(teplicova==1) printf("Matrica je Teplicova");
	return 0;
}
