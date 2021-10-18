#include <stdio.h>

int main() {
	int n,i,j,m,a[10],b[10];
	char mat[20][20];
	for(i=0; i<20;i++)
		for(j=0; j<20; j++)
			mat[i][j] = ' ';
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	do {
	if(n<=0 || n>10){
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
			scanf("%d",&n);
		 }
	}while(n<=0 || n>10);

	for(m=0;m<n;m++){
	printf("Unesite %d. tacku: ",m+1);
	scanf("%d",&a[m]);
	scanf("%d",&b[m]); 
	do{
		if((a[m]<0 || a[m]>19) || ( b[m]<0 || b[m]>19)){
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",m+1);
			scanf("%d",&a[m]);
			scanf("%d",&b[m]);
		}
			
	}while((a[m]<0 || a[m]>19) || (b[m]<0 || b[m]>19));
	}
	
	for(m=0;m<n;m++){
		for(i=0;i<20;i++){
			for(j=0;j<20;j++){
				if((j==a[m]) && (i==b[m]))
					mat[i][j]='*';
			}
		}
	}
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
