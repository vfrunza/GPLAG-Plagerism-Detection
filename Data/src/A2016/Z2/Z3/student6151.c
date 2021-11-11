#include <stdio.h>
#include<stdlib.h>

int main() {
	
	int p,n,i,j,k;
	int nizi[10], nizj[10];
	
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	}
	while (n<=0 || n>10);
	
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &nizi[i], &nizj[i]);
		if(nizi[i]<0 || nizj[i]<0 || nizi[i]>=20 || nizj[i]>=20) {printf("Pogresan unos\n");
		i--;}
	}
	
	for(i=0;i<20;i++){  
		for(j=0; j<20; j++){
			p=1;
			for(k=0;k<n;k++){
				if(j==nizi[k] && i==nizj[k]){
				printf("*");
				
				p++;
				break;}
			}
			if(p==1){
					printf(" "); 
		}}
		printf("\n");  
	} 
	
	return 0;
}
