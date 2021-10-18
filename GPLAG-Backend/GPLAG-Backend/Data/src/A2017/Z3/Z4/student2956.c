#include <stdio.h>

int max(int matrica[100][100],int visina,int sirina)
{
	int i,j,k,point=0;
	int postoji;
	int brojaci[100*100*2]={0};
	int max,max_pon;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			postoji=0;
			for(k=0;k<point;k=k+2){
				if(brojaci[k]==matrica[i][j]){
					brojaci[k+1]++;
					postoji=1;
					break;
				}
			}
			if(postoji==0){
				brojaci[point]=matrica[i][j];
				brojaci[point+1]++;
				point=point+2;
			}
		}
	}
	
	if(point==0) printf("Matrica je prazna");
	max=brojaci[0];
	max_pon=brojaci[1];
	
	for(i=1;i<point;i=i+2){
		if(brojaci[i]==max_pon){
			if(brojaci[i-1]<max) max=brojaci[i-1];
		}
		else if(brojaci[i]>max_pon){
			max_pon=brojaci[i];
			max=brojaci[i-1];
		}
	}
	return max;
}



int izbaci_kolone(int matrica[100][100],int visina,int sirina,int N)
{
	int i,j;
	int k;
	int r;
	
	for(i=0;i<visina;i++){
		for(j=0;j<sirina;j++){
			if(matrica[i][j]==N){
				for(k=0;k<visina;k++){
					for(r=j;r<sirina;r++) matrica[k][r]=matrica[k][r+1];
				}
				sirina--;
				j--;
			}
		}
	}
	return sirina;
}



int main()
{
	int i,j,prolaz=1;
	int matrica[100][100];
	int sirina,visina;
	
	printf("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&sirina,&visina);
	
	for(i=0;i<visina;i++){
		printf("Unesite elemente %d. reda: ",i+1);
		for(j=0;j<sirina;j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	while(sirina!=0){
		sirina=izbaci_kolone(matrica,visina,sirina,max(matrica,visina,sirina));
		if(sirina==0) printf("\nNakon %d. prolaza matrica je prazna!",prolaz);
		else{
			printf("\nNakon %d. prolaza matrica glasi: \n",prolaz++);
			for(i=0;i<visina;i++){
				for(j=0;j<sirina;j++){
					printf("%5d",matrica[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}