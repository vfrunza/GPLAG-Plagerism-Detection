#include <stdio.h>

int main() {
	int matA[100][100],matB[100][100],matC[100][100];
	int i,j,M,N,k,l,y,x,niza[10000],nizb[10000],nizc[10000];
	int a=0,b=0,c=0,max,temp,istinitost=0;
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	}while(M>100||N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matA[i][j]);
			niza[a]=matA[i][j];
			a++;
		}
	}
	for(i=0;i<a;i++){
		max=i;
		for(j=i+1;j<a;j++) {
			if(niza[j]>niza[max]) max=j;
		}
		temp=niza[i];
		niza[i]=niza[max];
		niza[max]=temp;
	}
	printf("Unesite clanove matrice B: ");
	for(k=0;k<M;k++){
		for(l=0;l<N;l++){
			scanf("%d",&matB[k][l]);
			nizb[b]=matB[k][l];
			b++;
		}
	}
	for(i=0;i<a;i++){
		max=i;
		for(j=i+1;j<a;j++) {
			if(nizb[j]>nizb[max]) max=j;
		}
		temp=nizb[i];
		nizb[i]=nizb[max];
		nizb[max]=temp;
	}
	printf("Unesite clanove matrice C: ");
	for(x=0;x<M;x++){
		for(y=0;y<N;y++){
			scanf("%d",&matC[x][y]);
			nizc[c]=matC[x][y];
			c++;
		}
	}
	for(i=0;i<a;i++){
		max=i;
		for(j=i+1;j<a;j++) {
			if(nizc[j]>nizc[max]) max=j;
		}
		temp=nizc[i];
		nizc[i]=nizc[max];
		nizc[max]=temp;
	}

		for(i=0;i<a;i++){
			if((niza[i]!=nizb[i]) || (nizc[i]!=niza[i])){
				istinitost=1;
				break;
			}
		}
		if(istinitost==0) {printf("DA"); }
		else if(istinitost==1) printf("NE");
	
	/*if (c==b){
		for(i=0;i<c;i++){
			if(nizc[i]!=nizb[i]){
				istinitost1=1;
				break;
				
			}
		}
	}
		
	if(istinitost1==0){
		if(a==c){
			for(i=0;i<c;i++){
				if(nizc[i]!=niza[i]){
					istinitost2=1;
					break;
				}
			}
			
		}
		else printf("NE");	
		}
	if(istinitost1==0 && istinitost2==0){
			printf("DA");
		}*/

	return 0;
}
