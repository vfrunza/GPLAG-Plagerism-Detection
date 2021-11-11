#include <stdio.h>

int main() {
	int niz[100],n,i,j,nxt;
	int br2=0,br3=0;
	int niz2[1000];
	do{
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	}while(n>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
		if(niz[i]<0){
		printf("Broj nije prirodan.");
			i--;
		}
	}
	nxt=0;
	for(i=n;i>0;i--){
		do{
			for(j=n+nxt;j>0;j--){
				niz[j]=niz[j-1];
			}
			niz[0]=niz[n+nxt]%10;
			niz[n+nxt]/=10;
			nxt++;
		}while(niz[n+nxt-1]>0);
		n--;
	}
	for(i=0;i<n+nxt;i++){
		niz2[br2]=niz[i];
		br3=1;
		while(niz[i]==niz[i+br3] && i+br3!=n+nxt){
			br3++;
		}
		i+=br3-1;
		br2++;
		niz2[br2]=br3;
		br2++;
	}
	printf("Finalni niz glasi: ");
	printf("\n");
	for(i=0;i<br2;i++){
		printf("%d ",niz2[i]);
	}
	return 0;
}