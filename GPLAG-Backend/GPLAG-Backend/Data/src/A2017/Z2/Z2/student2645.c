#include <stdio.h>

int main() {
	int vel=0;
	int i,j=0,pom,k=0,l=0,m;
	int niz[100];
	int pomocni_niz[10];
	int pomocni_niz2[100];
	int finalni_niz[1000];
	int brojac=1;
	
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d",&vel);
	}while(vel>100 || vel<=0);
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		scanf("%d",&niz[i]);
	}
	
	for(i=0;i<vel;i++){
		pom=niz[i];
		j=0;
		if(pom==0) pomocni_niz2[k++]=0;
		while(pom!=0){
			pomocni_niz[j]=pom%10;
			pom/=10;
			j++;
		}
		
		for(m=j-1;m>=0;m--){
			pomocni_niz2[k++]=pomocni_niz[m];
		}
	}
	
	for(i=0;i<k;i++){
		pom=pomocni_niz2[i];
		brojac=1;
		for(j=i+1;j<k;j++){
			if(pom==pomocni_niz2[j])brojac++;
			else break;
		}
		finalni_niz[l]=pom;
		l++;
		finalni_niz[l]=brojac;
		l++;
		i=i+brojac-1;
	}
	
	printf("Finalni niz glasi: \n");
	for(i=0;i<l;i++){
		printf("%d ",finalni_niz[i]);
	}
	

	return 0;
}
