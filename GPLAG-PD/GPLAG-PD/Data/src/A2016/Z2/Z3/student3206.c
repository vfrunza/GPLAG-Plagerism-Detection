#include <stdio.h>

int main() {
	int n,i,j,a[20],b[20],k,d=0;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<1 || n>10)
	printf("Pogresan unos\n");
	}
	while(n<1 || n>10);
	for(k=0;k<n;k++)
		do{
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d",&a[k],&b[k]);
		if(a[k]<0 || a[k]>19 || b[k]<0 || b[k]>19)
		printf("Pogresan unos\n");
		}
		while(a[k]<0 || a[k]>19 || b[k]<0 || b[k]>19);
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				for(k=0;k<n;k++)
				if(i==b[k] && j==a[k]){
				printf("*");
				d++;
				break;
				}
				if(d!=1)
				printf(" ");
				d=0;
			}
			printf("\n");
		}
	return 0;
}
