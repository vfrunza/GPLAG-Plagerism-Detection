#include <stdio.h>

int main() {
	int niz1[100],niz2[1000]={0},niz3[10000]={0},i,n,k=0,j=0,br=1;
	printf("Unesite velicinu niza: ");
	do {
	scanf("%d", &n);
	} while(n<0 || n>100);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++) {
	    scanf("%d", &niz1[i]);
		if(niz1[i]<0) i--;
	}
	
	for(i=n-1; i>=0; i--) {
		while(niz1[i]!=0) {
			niz2[k]=(niz1[i]%10);
			niz1[i]/=10;
			k++;
		}
	}
	
	for(i=k-1; i>0; i--) {
		br=1;
		niz3[j]=niz2[i];
		j++;
		if(niz2[i]==niz2[i-1]) {
		while(niz2[i]==niz2[i-1]) {
			br++;
			
		i--;
		}
		niz3[j]=br;
		j++;
		}
		
		else {
		niz3[j]=br;
		j++;
		}
	}
	
	if(niz2[0]!=niz2[1]) {
	niz3[j]=niz2[0];
	j++;
	niz3[j]=1;
	j++;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<j; i++) {
		printf("%d ", niz3[i]);
	}
	

	
	return 0;
}
