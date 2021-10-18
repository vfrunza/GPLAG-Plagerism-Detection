#include <stdio.h>
#include <math.h>
int main() {
	int niz[100],temp[1000],niz2[1000],i,j,brojac=0,k=0,n;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}
	for(i=0;i<n;i++){
		int temp1=niz[i],brojac=0;
		do{
			temp1=temp1/10;
			brojac++;
		}
		while(temp1>0);
		for(j=brojac;j>0;j--){
			temp[k]=niz[i]/(pow(10,j-1));
			niz[i]=niz[i]%((int)pow(10,j-1));
			k++;
		}
	}
	j=0;
	for(i=0;i<k;i++){
		brojac=0;
		niz2[j]=temp[i];
		j++;
		do{
			brojac++;
			if(i+brojac>=k) break;
		}
		while(temp[i]==temp[i+brojac]&&i<k);
		niz2[j]=brojac;
		i=i+brojac-1;
		j++;
	}
	printf("Finalni niz glasi:\n");
	for(i=0;i<j;i++){
		printf("%d ",niz2[i]);
	}
	return 0;
}
