#include <stdio.h>

int main() {
	int m,n,i,j;
	int a[100][100],b[100][100],c[100][100],nizA[10000],nizB[10000],nizC[10000],k,l,min,temp;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
		
	}while(m<0 || m>100 || n<0 || n>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			
			scanf("%d",&a[i][j]);
		}
	}
		printf("Unesite clanove matrice B: ");
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		
			scanf("%d",&b[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			
			scanf("%d",&c[i][j]);
		}
	}
	
	
	l=m*n;
	
	i=0;
		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				nizA[i]=a[j][k];
				i++;
			}
		}
		
			i=0;
		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				nizB[i]=b[j][k];
				i++;
			}
		}
		
			i=0;
		for(j=0;j<m;j++){
			for(k=0;k<n;k++){
				nizC[i]=c[j][k];
				i++;
			}
		}
	for(i=0;i<l;i++){
		min=i;
		for(j=i+1;j<l;j++){
			if(nizA[j]<nizA[min])
			min=j;
		}
		temp=nizA[i];
		nizA[i]=nizA[min];
		nizA[min]=temp;
	}
		for(i=0;i<l;i++){
		min=i;
		for(j=i+1;j<l;j++){
			if(nizC[j]<nizC[min])
			min=j;
		}
		temp=nizC[i];
		nizC[i]=nizC[min];
		nizC[min]=temp;
	}
	
		for(i=0;i<l;i++){
		min=i;
		for(j=i+1;j<l;j++){
			if(nizB[j]<nizB[min])
			min=j;
		}
		temp=nizB[i];
		nizB[i]=nizB[min];
		nizB[min]=temp;
	}
	
	for(i=0;i<l;i++){
		if(nizA[i]!=nizB[i]){
			printf("NE\n"); return 0;
		}
	}
		for(i=0;i<l;i++){
		if(nizA[i]!=nizC[i]){
			printf("NE\n"); return 0;
		}
	}
	printf("DA\n");
	
	
	return 0;
}
