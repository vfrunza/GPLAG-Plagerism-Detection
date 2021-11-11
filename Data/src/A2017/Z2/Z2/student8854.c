#include <stdio.h>
#include <math.h>

int main() {
	int niz1[100]={0},n,niz2[1000]={0},i,b=0,c=0,d=0,temp2,brojac=0,niz3[1000]={0};
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
		if(n<=0 || n>100) printf("Neispravan unos");
		printf("Unesite clanove niza: ");
		for(i=0;i<n;i++){
			scanf("%d",&niz1[i]);
		}
	}while(n<=0 || n>100);

	for(i=n-1;i>=0;i--){
		do{
			niz2[b]=niz1[i]%10;
			niz1[i]/=10;
			b++;
			c++;
		}while(niz1[i]!=0);
	}

	for(i=0;i<c/2;i++){
		temp2=niz2[i];
		niz2[i]=niz2[c-i-1];
		niz2[c-i-1]=temp2;
	}
	
	for(i=0;i<c;i++){
		brojac++;
		if(niz2[i]!=niz2[i+1] || i==c-1){
			niz3[d]=niz2[i];
			d++;
			niz3[d]=brojac;
			d++;
			brojac=0;
		}
	}
	printf("Finalni niz glasi: \n");
	for(i=0;i<d;i++){
		printf("%d ",niz3[i]);
	}
	return 0;
}
