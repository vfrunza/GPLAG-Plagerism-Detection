#include <stdio.h>
void ubaci(int niz[],int n){
	int i=0;
	for(i=n-1; i>=0; i--){
		niz[i*2]=niz[i];
	}
	for(i=0;i<n*2;i++){
		int suma=0,a=niz[i];
		if(a<0)a*=-1;
		while(a>0){
			suma+=a%10;
			a/=10;
		}
		niz[i+1]=suma;
		i++;
	}
}
int JelFibonacijev(int ni){
	int niz[2]={1,2};
	int tr=0;
	while(1){
		if(ni==niz[0] || ni== niz[1]){tr=1; return tr;}
		else {
			niz[0]=niz[0]+niz[1];
			niz[1]=niz[0]+niz[1];
		}
		if(ni<niz[0]){tr=0; return tr;}
	}
}
	

int izbaci(int niz[], int n){
	int i,j,tr;
	for(i=0; i<n; i++){
		tr=JelFibonacijev(niz[i]);
		if(tr==1){
			for(j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			i--;
			n--;
		}
	}
	return n;
}

int main() {
	int niz[20],i,n=0;
	for(i=0; i<20;i++){
		niz[i]=0;
	} 
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	n=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++){
		if(i!=n-1){
			printf("%d, ",niz[i]);
		}
		else printf("%d.",niz[i]);
	}
	return 0;
}