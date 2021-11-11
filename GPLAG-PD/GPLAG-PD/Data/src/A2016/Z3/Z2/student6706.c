#include <stdio.h>
int izbaci (int* niz, int n){
	int i,j,x,y,z;
	for(i=0;i<n;i++){
		x=1; y=1;
		for(x=1; x<niz[i]+1;)
		if(niz[i]==1 || niz[i]==x+y){
			for(j=i;j<n-1;j++)
			niz[j]=niz[j+1];
			n--; i--; break;
		}
		else{
			z=x+y;
			x=y;
			y=z;
		}
	}
	return n;
}
void ubaci(int* niz,int n){
	int i,y,x,a[100],sum=0;
	for(i=0;i<n;i++){
		y=niz[i];
		sum=0;
		while(y!=0){
		x=y%10;
		sum=sum+x;
		y=y/10;
		}
		a[2*i]=niz[i];
        a[2*i+1]=sum;
	}
        for(i=0;i<2*n;i++) niz[i]=a[i];
}
int main() {
	int niz[100],i,n=0;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) scanf("%d",&niz[i]);
	ubaci(niz,10);
	n=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++){
		if(i==n-1) printf("%d.",niz[i]);
		else 
		printf("%d, ",niz[i]);
	}
	return 0;
}
