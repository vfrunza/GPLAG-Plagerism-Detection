#include <stdio.h>
#include <math.h>


void zaokruzi1 (float niz[],int n){

	int i;
	for(i=0;i<n;i++){
		niz[i]=round(niz[i]*10)/10;
	}
}
void preslozi (float niz[],int n,int k){
	int i,niz_cifara[30],niz_ostataka[30],suma_ostataka[30],j=0,l=0;
	float niz_vecih[30],niz_manjih[30];
	for (i=0;i<30;i++){
		suma_ostataka[i]=0;
	}
	zaokruzi1(niz,n);
	for(i=0;i<n;i++){
		niz_cifara[i]=fabs(niz[i]*10);
		do{
			niz_ostataka[i]=niz_cifara[i]%10;
			suma_ostataka[i]=suma_ostataka[i]+niz_ostataka[i];
			niz_cifara[i]=niz_cifara[i]/10;	
			}while(niz_cifara[i]!=0);
	if (suma_ostataka[i]>k){
			niz_vecih[j]=niz[i];
			j++;
		}
	else if (suma_ostataka[i]<k){
			niz_manjih[l]=niz[i];
			l++;
		}
	}
	for (i=0;i<j;i++){
		niz[i]=niz_vecih[i];
	}
	for(i=j;i<j+l;i++){
		niz[i]=niz_manjih[i];
	}
}

int main() {
	float niz[30];
	int i,k,n=0;
	printf("Unesite velicinu niza:");
	scanf("%d",&n);
	printf("Unesite clanove niza:");
	for (i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	printf("Unesite jedan prirodan broj:");
	scanf("%d",&k);
	preslozi(niz,n,k);
	for (i=1;i<n;i++){
	printf("%f,",niz[i-1]);
	}
	printf("%g",niz[i]);
	return 0;
}
