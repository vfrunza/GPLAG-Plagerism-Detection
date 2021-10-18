#include <stdio.h>
#include <math.h>

int main() {
	int n,i,x,j=0,br=0,k,m=0;
	int niz[100];
	int niz1[1000];
	int finalni[1000];
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n <= 0 || n > 100);
	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++){
		scanf("%d",&x);
		if(x >= 0) niz[i]=x;
		else i--;
	}
	for(i = 0; i < n; i++){
		x = niz[i];
		if(x!=0){
			while(x > 0){
				br++;
				x=x/10;
			}
			x = niz[i];
			while(br > 0){
				niz1[j] = x/pow(10,br-1);
				x = x - (niz1[j] * pow(10,br-1));
				br--;
				j++;
			}
		}
		else{
			niz1[j] = x;
			j++;
		}
		
	}
	for(i = 0; i < j; i++){
		x = niz1[i];
		br = 0;
		for(k=i;k<j;k++){
			if(x!=niz1[k]) break;
			br++;
		}
		finalni[m] = x;
		m++;
		finalni[m] = br;
		m++;
		i = i + br - 1;
		
	}
	printf("Finalni niz glasi:\n");
	for(i = 0; i < m; i++) printf("%d ",finalni[i]);
	return 0;
}
