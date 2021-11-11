#include <stdio.h>

int main() {
	int niz1[100], niz2[100], i, brojac=0, k=0, tmp, n, ponavljanje=0, niz3[1000], j, brojac_treceg=0, p=0;
	
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	}while(n>100);
	
		printf("Unesite clanove niza: ");
	for(i=0; i<n; i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]<0){
			i--;
			continue;
		}
	}
	
	for(i=n-1; i>=0; i--){
		if(niz1[i]==0){
			niz2[k++]=niz1[i]%10;
			brojac++;
		}
		while(niz1[i]!=0){
			niz2[k++]=niz1[i]%10;
			brojac++;
			niz1[i]/=10;
		}
	}
	
	for(i=0; i<brojac/2; i++){
		tmp=niz2[i];
		niz2[i]=niz2[brojac-i-1]; /*Greskaaaaa*/
		niz2[brojac-i-1]=tmp;
	}
	
	for(i=0; i<brojac; i++){
		for(j=i; j<brojac; j++){
			while(niz2[i]==niz2[j]){
				ponavljanje++;
				if(j==brojac-1){
					j++;
					break;
				}else j++;
			}
			break;
		}
		niz3[p++]=niz2[i];
	    niz3[p++]=ponavljanje;
	    brojac_treceg+=2;
	    ponavljanje=0;
	    i=j-1;
	}
	printf("Finalni niz glasi: \n");
	for(i=0; i<brojac_treceg; i++){
		printf("%d ", niz3[i]);
	}
	
	
	
	return 0;
}
