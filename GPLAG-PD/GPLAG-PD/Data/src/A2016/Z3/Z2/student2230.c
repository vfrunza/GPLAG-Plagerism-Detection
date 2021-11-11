#include <stdio.h>
#include <math.h>

void ubaci(int* niz, int vel){
	int i,j,c;
	c=vel;
	for(i=0;i<2*vel;i++){
	double suma=0;
	int cifra;
	int n;
	n=niz[i];
	while(n!=0){
		if(n<0){
			cifra=(n%10)*(-1);
			suma=suma+cifra;
			n=n/10;
		}
		else{
		cifra=n%10;
		suma=suma+cifra;
		n=n/10;
		}
		
	}
	for(j=c;j>i+1;j--){
		niz[j]=niz[j-1]; }
		niz[j]=suma;
		c++;
		i++;
		//suma=0;
	
	}}
int izbaci (int* niz,int vel){
	double x=sqrt(5);
	double Phi=(1+x)/2.;
	double phi=(1-x)/2.;
	int fibonaci;
	
	int k;
	int i,j;
	for(i=0;i<vel;i++){
		for(k=1;k<100;k++){
			fibonaci=(pow(Phi,k)-pow(phi,k))/x;
		
		//	if(k==34) fibonaci--;
			if(niz[i]==fibonaci){
				for(j=i;j<vel-1;j++){
					niz[j]=niz[j+1];
				}
				vel--;
				i--;
				break;
			}
		}
	}	
	return vel;
}

int main() {
	int niz[1000],i;
	
	for(int i=0;i<1000;i++) niz[i]=0;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	ubaci(niz,10);
	int v=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<v;i++){
		if(i==v-1) printf("%d.",niz[i]);
		else{
		printf("%d, ",niz[i]);}
	}
	return 0;
}



























