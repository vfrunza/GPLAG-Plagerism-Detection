#include <stdio.h>

int main() {
	
	int i,j,n,k=0,temp,brojac,niz[100],niza[100]={0},nizb[100]={0},nizc[1000]={0};
	
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	
	} while (n>100 || n<=0);
	
		printf("Unesite clanove niza: ");
		
		for(i=0;i<n;i++){
		scanf("%d", &niz[i]);
		if(niz[i]<0) 
		i--;
		}
		
	//OKRECEMO POCETNI NIZ  
	
	for(i=0;i<n/2;i++){
		temp=niz[i];
		niz[i]=niz[n-i-1];
		niz[n-i-1]=temp;
	}
	
	//KOPIRAMO U POMOCNI
	
	for(i=0;i<n;i++){
		niza[i]=niz[i];
		
	}
	
	//DIJELIMO CLANOVE POMOCNOG NIZA NA CIFRE
	
	for(i=0;i<n;i++){
		temp=niza[i];
		if(temp==0){
			nizb[k]=temp;
			k++;
			continue;
		}
		while (temp!=0) {
			nizb[k]=temp%10;
			temp=temp/10;
			k++;
		}
	}
	
	for(i=0;i<k/2;i++){
		temp=nizb[i];
		nizb[i]=nizb[k-i-1];
		nizb[k-i-1]=temp;
	}
	
	//PRAVIMO NOVI NIZ 
	
	j=0;
	
	for(i=0;i<k;i++){
		brojac=0;
		temp=nizb[i];
		while (nizb[i]==temp && i<k) {
			brojac++;
			i++;
		}
		i--;
		nizc[j]=nizb[i];
		nizc[j+1]=brojac;
		j=j+2;
	}
	
	printf("Finalni niz glasi: \n");
	
	for(i=0;i<j;i++){
		printf("%d ",nizc[i]);
	}
	
		
	return 0;
}
	

