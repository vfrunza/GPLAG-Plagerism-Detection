#include <stdio.h>

int main() {
	int mata[100][100],matb[100][100],matc[100][100],i,j,m=1,n=1,k,niz1[10000]={0},niz2[10000]={0},niz3[10000]={0},min,temp,true=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || n<0 || n>100 || m>100);
	k=m*n;
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mata[i][j]);
			niz1[i*n+j]=mata[i][j];
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matb[i][j]);
			niz2[i*n+j]=matb[i][j];
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matc[i][j]);
			niz3[i*n+j]=matc[i][j];
		}
	}
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<k;j++){
			if(niz1[j]<niz1[min])
			min=j;
		}
		temp=niz1[i];
		niz1[i]=niz1[min];
		niz1[min]=temp;
	}
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<k;j++){
			if(niz2[j]<niz2[min])
			min=j;
		}
		temp=niz2[i];
		niz2[i]=niz2[min];
		niz2[min]=temp;
	}
	for(i=0;i<k;i++){
		min=i;
		for(j=i+1;j<k;j++){
			if(niz3[j]<niz3[min])
			min=j;
		}
		temp=niz3[i];
		niz3[i]=niz3[min];
		niz3[min]=temp;
	}
//	for(i=0;i<k;i++) printf("%d ",niz1[i]);

	for(i=0;i<k;i++){
		if(niz1[i]!=niz2[i] || niz1[i]!=niz3[i] ){
			true=1;
			break;
		}
	}
	if(true) printf("NE");
	else printf("DA");
	return 0;
}
