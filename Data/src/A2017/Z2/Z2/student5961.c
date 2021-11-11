#include <stdio.h>

int main() {
	int niz[100],vel,vel2=0,i=0,niz2[100],niz3[100],vel3=0,j=0,br1=0;
	int pom,k=1,suma=0,br=0;
	
	
	
		
	do{
	printf ("Unesite velicinu niza: ");
	scanf("%d",&vel);
	}while(vel<=0 || vel >100);
	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		scanf("%d,",&niz[i]);
		if(niz[i]<=0) i--;
	}
	
	for(i=0;i<vel;i++){
		pom=niz[i];
		k=1;
		suma=0;
		br=0;
		while(pom!=0){
			br++;
			pom/=10;
		}
		while(br!=1){
			k*=10;
			br--;
		}
		while(niz[i]!=0){
			suma+=(niz[i]%10)*k;
			k/=10;
			niz[i]/=10;
			
		}
		niz[i]=suma;
	}
	for(i=0;i<vel;i++){
	while(niz[i]!=0){
		niz2[vel2]=niz[i]%10;
		vel2++;
		niz[i]/=10;
	}
}

	vel3=0; 
	for(i=0;i<vel2;i++){
		niz3[vel3]=niz2[i];
		j=i;
		while(j!=vel2 && niz2[i]==niz2[j]) { br1++; j++;}
		niz3[vel3+1]=br1;
		vel3+=2;
		br1=0;
		i=j-1;
	}
 	printf("Finalni niz glasi:\n");
	for(i=0;i<vel3;i++){
		if(i!=vel3-1) printf("%d ",niz3[i]);
		else printf("%d",niz3[i]);
	}
	
	return 0;
}
