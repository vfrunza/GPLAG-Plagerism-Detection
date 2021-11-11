#include <stdio.h>
#include <stdlib.h>
int zbir (int a){
	int x=0;
	while (a>0){
		x=x+a%10;
		a=a/10;
	}
	return x;
}

void ubaci(int niz[],int duzina){
	int *q,*p;
	int i=2*duzina;
	int y;
	for (i=duzina-1;i>=0;i--){
		p=niz+i*2;
		q=niz+i;
		*p=*q;
	}
	for (i=0;i<2*duzina;i+=2){
		p=niz+i;
		q=p+1;
		y=abs(*p);
		*q=zbir(y);
	}
}

int izbaci(int niz[],int duzina){
	int fbn[1000]={0};
	int max,x=2,i,j,k,vel;
	max=niz[0];
	for(i=0;i<duzina;i++){
		if(max<niz[i])
		max=niz[i];
		fbn[0]=1;
		fbn[1]=1;
	}
	for(i=2;i<1000;i++){
		fbn[i]=fbn[i-1]+fbn[i-2];
		if(fbn[i]>max)
		break;
		else x++;
	} 
	vel=duzina;
	for (i=0;i<vel;i++){
		for(j=0;j<x;j++){
			if(niz[i]==fbn[j]){
				for(k=i;k<vel-1;k++){
					niz[k]=niz[k+1];
					vel--;
					i--;
					break;
				}
			}
		}
	}
	return vel;
}


int main() {

int niz[20],duzina=10,i,izbacii;
printf ("Unesite niz od 10 brojeva: ");
for (i=0;i<duzina;i++){
	scanf("%d", &niz[i]);
}
ubaci(niz,duzina);
duzina*=2;
izbacii=izbaci(niz,duzina);
printf("Modificirani niz glasi: ");
for(i=0;i<izbacii-1;i++){
	printf("%d,",niz[i]);
}
printf("%d.",niz[i]);
	return 0;
}
