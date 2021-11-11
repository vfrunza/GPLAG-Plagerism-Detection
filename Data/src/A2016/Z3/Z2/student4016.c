#include <stdio.h>
#include <stdlib.h>
int izbroji(int n){
	int zbroj=0,temp,m=n;
	while(m!=0){
		temp=m%10;
		zbroj+=temp;
		m/=10;
	}
	return abs(zbroj);
}

void ubaci(int niz[], int velicina){
	int i,j;
	for(i=0;i<velicina;){
		for(j=velicina-1;j>=i;j--)
		niz[j+1]=niz[j];
		niz[i+1]=izbroji(niz[i]);
		velicina++;
		i+=2;
	}
}


int izbaci(int niz[], int velicina){
	int i=0,j=0,k=0,temp=niz[0], red[46]={1,1}, pamti=0;
	for(i=2;i<46;i++)
	red[i]= red[i-1]+ red[i-2];
	
	for(j=0;j<velicina;j++){
		if(pamti==1){j--;pamti=0;}
		for(i=1;i<46;i++){
			if(niz[j]==red[i]){
				
				for(k=j;k<velicina-1;k++) 
				niz[k]=niz[k+1];
				velicina--;
				if(j==0)pamti=1;
				else j--;
			}
		}
	}
	for(i=0;i<46;i++)
	if(velicina==1 && niz[0]==red[i])velicina=0;
	return velicina;
}

int main() {
	//printf("Zadaća 3, Zadatak 2");
	int niz[20]={0};
	int velicina=20, i;
	printf("Unesite niz od 10 brojeva: ");
	scanf("%d %d %d %d %d %d %d %d %d %d",&niz[0],&niz[1],&niz[2],&niz[3],&niz[4],&niz[5],&niz[6],&niz[7],&niz[8],&niz[9]);
	ubaci(niz,velicina/2);
	velicina=izbaci(niz,velicina);
	printf("Modificirani niz glasi:");
	for(i=0; i<velicina;i++){
	if(i+1<velicina)printf(" %d,",niz[i]);
	else printf(" %d.",niz[i]);}
	return 0;
}
