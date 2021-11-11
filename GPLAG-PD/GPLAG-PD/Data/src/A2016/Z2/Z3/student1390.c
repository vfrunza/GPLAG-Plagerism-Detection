#include <stdio.h>

int main() {
	int n,i,j,k,x,niz1[10],niz2[10];
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	while(n>10 || n<=0){
	printf("Pogresan unos \n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=10 && n>0)break;
	}
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d", &niz1[i], &niz2[i]);
		while(niz1[i]<0 || niz1[i]>19 || niz2[i]<0 || niz2[i]>19){printf("Pogresan unos \n");
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d%d", &niz1[i], &niz2[i]);
		continue;}
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			x=0;
			for(k=0; k<n; k++){
		    if(i==niz2[k] && j==niz1[k]){x=1;
		    break;}
			}
			if(x==1)printf("*");
			else if(x==0)printf(" ");
		} 
		printf("\n");
	}

	return 0;
}
