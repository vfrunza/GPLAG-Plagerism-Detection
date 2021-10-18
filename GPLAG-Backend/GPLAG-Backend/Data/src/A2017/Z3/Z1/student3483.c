#include <stdio.h>
#define t 100000


int dva_od_tri(int niz1[],int vel_prvog,int niz2[], int vel_drugog, int niz3[], int vel_treceg){
	int pom_vel=0,pom_niz[t]={0},kopija_pom[t]={0};
	int i=0,j=0,l=0,brojac=0,temp=0,flag=0;
	
	/*kopiramo elemente iz niza1 u pom_niz s tim da ne kopiramo elemente koji se ponavljaju,
	   tako i za niz2 i niz3*/
	for(i=0;i<vel_prvog;i++){
		flag=1;
		for(l=0;l<i;l++){
			if(niz1[i]==niz1[l]) flag=0;
		}
		if(flag) pom_niz[pom_vel++]=niz1[i];
	}
	
	for(i=0;i<vel_drugog;i++){
		flag=1;
	    for(l=0;l<i;l++){
	    	if(niz2[i]==niz2[l]) flag=0;
	    }
	    if(flag) pom_niz[pom_vel++]=niz2[i];
	}
	for(i=0;i<vel_treceg;i++){
		flag=1;
		for(l=0;l<i;l++){
			if(niz3[i]==niz3[l]) flag=0;
		}
		if(flag) pom_niz[pom_vel++]=niz3[i];
	}
	/*kopiramo sve clanove nizova u jedan niz*/
	for(i=0;i<pom_vel;i++){
		kopija_pom[i]=pom_niz[i];
	}
	
	for(i=0;i<pom_vel-1;i++){
		brojac=0;
		for(j=i;j<pom_vel;j++){
			if(pom_niz[i]==pom_niz[j]) brojac++;
		}
		/*u slucaju da se ponavljaju*/
		if(brojac==2){
			flag=1;
			for(l=0;l<i;l++){
				if(pom_niz[i]==kopija_pom[l]) flag=0;
			}
			if(flag) temp++;
		}
	}
	
	return temp;
}

int main() {
	int n1[6]={2,2,2,2,2,1};
	int n2[6]={2,2,2,2,2,1};
	int n3[6]={2,2,2,2,2,2};
	
	printf("%d", dva_od_tri(n1,6,n2,6,n3,6));
	return 0;
}
