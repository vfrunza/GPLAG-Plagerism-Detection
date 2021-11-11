#include <stdio.h>
#include<math.h>
int main() {
	int ma[200][200];
	int i,j,x;
	int H=1;
	int r,s;
	int n,m;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
		if(m<=0 || n<=0 || m>200 || n>200)
		printf("Brojevi nisu u trazenom opsegu.\n");
	} 
	while(m<=0 || n<=0 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			scanf("%d",&ma[i][j]);
		
	}

	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			H=1;
			for(x=0; x<m; x++){
				if(ma[x][i]!=ma[x][j]) H=0;
			}
			if(H==1){
				for(r=0; r<m; r++) 
					for(s=j; s<n-1; s++)
						ma[r][s]=ma[r][s+1];
				n--;
				j--;
			}
		}
	}
	
		for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			
			H=1;
			
			for(x=0;x<n;x++){
				if(ma[i][x]!=ma[j][x]) 
				H=0;
			}
			if(H==1){
				for(r=j;r<m-1;r++)
					for(s=0;s<n;s++)
						ma[r][s]=ma[r+1][s];
						m--;
						j--;
				}
		}
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%5d",ma[i][j]);
		}
		printf("\n");
	}
	for(;;) 
	break;
	
	return 0;
}
