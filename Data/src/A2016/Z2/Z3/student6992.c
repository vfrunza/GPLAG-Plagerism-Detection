#include <stdio.h>

int main() {
	int n, j, i, k, niza[10], nizb[10], temp1, temp2, min;
	while(1){
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n>0 && n<=10)
			break;
		else
			printf("Pogresan unos\n");
	}
	for(i=0;i<n;i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &niza[i], &nizb[i]);
		if(niza[i]<0 || niza[i]>19 || nizb[i]<0 || nizb[i]>19){
			printf("Pogresan unos\n");
			i--;
		}
	}
	for(i=0;i<n;i++) {
		min=i;
		for(j=i+1;j<n;j++) {
			if(nizb[j]<nizb[min] || (nizb[min]==nizb[j] && niza[min]>niza[j]))
			min=j;
		}
		temp1=niza[i];
		niza[i]=niza[min];
		niza[min]=temp1;
		temp2=nizb[i];
		nizb[i]=nizb[min];
		nizb[min]=temp2;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(niza[i]==niza[j] && nizb[i]==nizb[j]){
				for(k=0;k<n-1;k++){
					niza[k]=niza[k+1];
					nizb[k]=nizb[k+1];
				}
				n--;
				i--;
				break;
			}
		}
	min=0;
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(j==niza[min] && i==nizb[min]){
				printf("*");
				min++;
				if(min==n)
					min=0;
			}
			else 
				printf(" ");
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
