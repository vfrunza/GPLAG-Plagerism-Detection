#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define cons 100
#define conss 1000

int main() {

	int niz[cons],niz2[cons],niz3[cons]={0},niz4[conss]={0};
	int a,br=0,poz=0,br3=0;
	int i,k=0,br2=0,x;
		for(i=0;i<100;i++){
		niz3[i]=99;
		}
	printf("Unesite velicinu niza: ");
	scanf("%d",&a);
	printf("Unesite clanove niza: ");
	for(i=0;i<a;i++){
		scanf("%d",&niz[i]);
		do{/* racuna pojedine cifre u obrnutm redoslijedu*/
			niz2[br+1]=niz[i]%10;
			niz[i]/=10;
			br++;
		}while(niz[i]!=0);
	/*daje jednom nizu cifre u pravom redoslijedu */
		for(k=0;k<br;k++){
		x=(br-k);
			niz3[k+br2]=niz2[x];
		}
		br2+=br;
		br=0;
	}
	br3=0;
	br=0;
	i=0;
	niz4[0]=niz3[0];
while(i<br2){
while(niz4[poz]==niz3[br]){
		niz4[poz+1]++;
		br++;
		br3++;
	}
	poz+=2;
	niz4[poz]=niz3[br];
	i+=br3;
	br3=0;
}
	printf("Finalni niz glasi:\n");
for(i=0;i<=poz-1;i++){
	printf("%d ",niz4[i]);
}
	return 0;
}