#include <stdio.h>
int main() {
	int n,niz[100],niz1[1000]={0},i,j=0,broj,brojac=1,temp,br_cifara=0;;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<=0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}for(i=0;i<n;i++){
		temp=niz[i];
		niz[i]=0;
		do{
			niz[i]=niz[i]*10+temp%10;
			temp/=10;
			br_cifara++;
		}while(temp>0);
		while(br_cifara>0){
				broj=niz[i]%10;
				if(j!=0){
					if(broj==niz1[j-1]) brojac++;
				else{
					niz1[j]=brojac;
					j++;
					niz1[j]=broj;
					j++;
					brojac=1;
				}}else {
					niz1[j]=broj;
				    j++;
				}
				niz[i]/=10;
				br_cifara--;
			}
	}
	niz1[j]=brojac;
	j++;
	printf("Finalni niz glasi:\n");
	for(i=0;i<j;i++) printf("%d ",niz1[i]);
	return 0;
}
