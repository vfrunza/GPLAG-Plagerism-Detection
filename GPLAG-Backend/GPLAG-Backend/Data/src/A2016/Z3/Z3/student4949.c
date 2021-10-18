#include <stdio.h>

int main() {
	int a[200][200]={0};
	int m,n,p,br=0,treba,k,j,i,e,s,treba1;
	printf("Unesite brojeve M i N: ");
	do{
		scanf("%d %d",&m,&n);
		if(m<=0 || m>200 || n<=0 || n>200) {
			printf("Brojevi nisu u trazenom opsegu.\n"); 
			printf("Unesite brojeve M i N: ");
		}
	}while(m<=0 || m>200 || n<=0 || n>200);
	
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m-1;i++){
		for(p=i+1;p<m;p++){
			br=0;
			for(j=0;j<n;j++){ 
				if(a[i][j]==a[p][j]) br++;
			}
				if(br==n) {
					for(s=p;s<m-1;s++){
						for(k=0;k<n;k++){
							treba=a[s][k];
							a[s][k]=a[s+1][k];
							a[s+1][k]=treba;
						}
					}
				m--;
				p--;
				} 
				
		}
		
	}
	br=0;
	for(i=0;i<n-1;i++){
		for(e=i+1;e<n;e++){
			br=0;
			for(j=0;j<m;j++){ 
				if(a[j][i]==a[j][e]) br++;
			}
				if(br==m) {
				for(s=0;s<m;s++){	
					for(k=e;k<n-1;k++){
						treba1=a[s][k];
						a[s][k]=a[s][k+1];
						a[s][k+1]=treba1;
					}
				} 
				n--;
				e--;
				}
		}
	}
	
	
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
			for(j=0;j<n;j++){ printf("%5d", a[i][j]);
				
			}
		printf("\n");
	}
	
	
	return 0;
}
