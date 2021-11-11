#include <stdio.h>

int main() {
	
	int a[100][100],b[100][100],c[100][100];
	
	int m,n;
	int i,j,k,s,temp;
	int brojac[100];
	
	
	do{
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	} while(m>100 && n>100);
	
	printf("Unesite clanove matrice A: ");
	
	for(i=0; i<m; i++) {
	    for(j=0; j<n; j++) {
	    	scanf("%d",&a[i][j]);
	    }
	    
	}
		
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			temp=a[i][j];
			for(k=0;k<m;k++){
				for(s=0;s<n;s++){
					if(temp==a[k][s]) brojac[i]++; 
				}
			}
		} printf("%d ",brojac[i]);
	}
	
/*	printf("Unesite clanove matrice B: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&c[i][j]);
		}
	}
	
	*/
	
	
	return 0;
}
