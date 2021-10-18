#include <stdio.h>
#define MAXEL 100
#define MAXEL2 1000

int main() {
	int niz[MAXEL]={0}, n=0, i, t, niz2p[MAXEL2]={0}, b=0, niz2[MAXEL2]={0}, m, j, nizk[MAXEL]={0}, k;
	double unos;
	do{
		printf("Unesite velicinu niza: "); 
		scanf("%lf", &unos);
		if(unos-(int)unos<0.00001){
			n=(int)unos;
			break;
		}
	} while(n<1 || n>100);
	
	printf("Unesite clanove niza: ");
	j=0;
	for(i=0; i<n; i++){
		scanf("%lf", &unos);
		if(unos-(int)unos>0) i--;
		else niz[i]=(int)unos;
	}
	
	t=0;
	for(i=0; i<n; i++){
		m=b;
		while(t==0){
			niz2p[b]=niz[i]%10;
			niz[i]/=10;
			b++;
			if(niz[i]==0) break;
		}
		for(j=0; j<b-m; j++){
			niz2[b-j-1]=niz2p[m+j];
		}
	}
	
	k=0;
	
	for(i=0; i<b; i++){
		m=0;
		for(j=0; j<b-i; j++){
			if(niz2[i]==niz2[i+j]) m++;
			else break;
		}
		nizk[k]=niz2[i];
		nizk[k+1]=m;
		i=i+m-1;
		k+=2;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<k; i++){
		printf("%d ", nizk[i]);
	}
	
	return 0;
}
