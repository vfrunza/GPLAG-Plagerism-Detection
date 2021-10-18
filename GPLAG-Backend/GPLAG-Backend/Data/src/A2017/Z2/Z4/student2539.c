#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100];
	int pomA[20000],pomB[20000],pomC[20000];
	int i,j,k,l,velA=0,velB=0,velC=0,m,n,x,br;
	int ubaci,uslov1=1,uslov2=1,imaB=0,imaC=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m>=0 && m<=100 && n>=0 && n<=100) break;
	}while(1==1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) scanf("%d",&A[i][j]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) scanf("%d",&B[i][j]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++) scanf("%d",&C[i][j]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			x=A[i][j];
			ubaci=1;
			br=0;
			for(k=0;k<velA;k+=2){
				if(x==pomA[k]) ubaci=0;
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++) if(x==A[k][l]) br++;
			}
			if(ubaci){
				pomA[velA++]=x;
				pomA[velA++]=br;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			x=B[i][j];
			ubaci=1;
			br=0;
			for(k=0;k<velB;k+=2){
				if(x==pomB[k]) ubaci=0;
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++) if(x==B[k][l]) br++;
			}
			if(ubaci){
				pomB[velB++]=x;
				pomB[velB++]=br;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			x=C[i][j];
			ubaci=1;
			br=0;
			for(k=0;k<velC;k+=2){
				if(x==pomC[k]) ubaci=0;
			}
			for(k=0;k<m;k++){
				for(l=0;l<n;l++) if(x==C[k][l]) br++;
			}
			if(ubaci){
				pomC[velC++]=x;
				pomC[velC++]=br;
			}
		}
	}
	for(i=0;i<velB;i+=2){
		uslov1=1;
		imaB=0;
		for(j=0;j<velA;j+=2){
			if(pomB[i]==pomA[j]){
				imaB=1;
				if(pomB[i+1]!=pomA[j+1]){
					uslov1=0;
					break;
				}
			}
		}
		if(imaB==0) uslov1=0;
		if(uslov1==0) break;
	}
	for(i=0;i<velC;i+=2){
		uslov2 = 1;
		imaC=0;
		for(j=0;j<velA;j+=2){
			if(pomC[i]==pomA[j]){
				imaC=1;
				if(pomC[i+1]!=pomA[j+1]){
					uslov2=0;
					break;
				}
			}
		}
		if(imaC==0) uslov2=0;
		if(uslov2==0) break;
	}
	if(uslov1==0 || uslov2==0) printf("NE");
	else printf("DA");
	return 0;
}