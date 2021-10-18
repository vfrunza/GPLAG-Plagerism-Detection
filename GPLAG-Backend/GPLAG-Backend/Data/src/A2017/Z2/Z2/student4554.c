#include <stdio.h>

int main() {
	int niz[100],niz1[100]={0},niz2[1000]={0};
	int i,j,n,temp,k=0,brojac=0;
   
	do {
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	} while(n>100 || n<=0);

	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
		if(niz[i]<0) 
		   i--;
	}
	
	//okretanje pocetnog niza
	for(i=0; i<n/2; i++) {   
		temp=niz[i];
		niz[i]=niz[n-i-1];
		niz[n-i-1]=temp;
	}
	
	for(i=0; i<n; i++) {   
		temp=niz[i];
		if(temp==0) { 
			niz1[k]=temp;
			k++; 
			continue;
		}					//razdvajanje clanova na cifre
		while(temp!=0) {    
			niz1[k]=temp%10;
			temp=temp/10;
			k++;
		}
	}
	
	//okretanje niza cifara
	for(i=0;i<k/2;i++) {
		temp=niz1[i];
		niz1[i]=niz1[k-i-1];
		niz1[k-i-1]=temp;
	}
	
	//prolazak kroz niz i brojanje
	j=0;
	for(i=0; i<k; i++) {
		brojac=0;
		temp=niz1[i];
		while(niz1[i]==temp && i<k) {
			brojac++;
			i++;
	    }
	i--;
	niz2[j]=niz1[i];
	niz2[j+1]=brojac;
	j=j+2;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<j; i++) {
	    printf("%d ",niz2[i]);
	}
	return 0;
}
