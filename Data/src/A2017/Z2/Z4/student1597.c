#include <stdio.h>
#define BROJ_EL 300
int main() {
	int m,n,i,j,k,temp;
	int a[BROJ_EL][BROJ_EL],b[BROJ_EL][BROJ_EL],c[BROJ_EL][BROJ_EL],niz_a[BROJ_EL],niz_c[BROJ_EL],niz_b[BROJ_EL];
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || n<0 || m>100 || n>100);
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j< n; j++) {
			scanf("%d",&b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d",&c[i][j]);
		}
		
	}
	k=0;
	for (i = 0; i <m; i++) {
		for (j = 0; j <n; j++) {
		niz_a[k++]=a[i][j];	
		}
	}
	k=0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			niz_b[k++]=b[i][j];
		}
	}
	k=0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			niz_c[k++]=c[i][j];
		}
	}
	for (i = 0; i <k-1; i++) {
		for (j = 0; j <k-i-1 ; j++) {
			if(niz_a[j]>niz_a[j+1]){
				temp=niz_a[j];
				niz_a[j]=niz_a[j+1];
				niz_a[j+1]=temp;
				
			}
				if(niz_b[j]>niz_b[j+1]){
				temp=niz_b[j];
				niz_b[j]=niz_b[j+1];
				niz_b[j+1]=temp;
			}
				if(niz_c[j]>niz_c[j+1])
				{
				temp=niz_c[j];
				niz_c[j]=niz_c[j+1];
				niz_c[j+1]=temp;
			}
			
		}
	}
	for (i = 0; i < k; i++) {
		if(niz_a[i]!=niz_b[i] || niz_a[i]!=niz_c[i]){
		printf("NE");
		return 0;
	}
		
	}
	
	
	
	printf("DA");
	return 0;
}
