#include <stdio.h>

int main() {
	int n,m,i,j,mat[100][100]={0},c=0,t=0,check,a,b;
	do{
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	if(m>100 || m<=0 || n>100 || n<=0) printf("Pogresan unos!\n");
	}
	while(m<=0 || m>100 || n<=0 || n>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		scanf("%d",&mat[i][j]);	
		}
	}
	for(i=0;i<m;i++)
	{ for(j=0;j<n;j++){
		check=mat[i][j];
		a=i;
		b=j;
		while(a<m && b<n){
			if(mat[a][b]!=check)
			t++;
			a++;
			b++;
		}
	}
	}
	for(i=0;i<m-1;i++)
	{ for(j=0;j<n;j++){
		a=(i+1)%m;
		b=(j+1)%n;
		if(mat[i][j]!=mat[a][b]) c++;
			}
		
	}
	if(!t && c)
	printf("Matrica je Teplicova");
	else if(!c) printf("Matrica je cirkularna");
	else printf("Matrica nije ni cirkularna ni Teplicova");
	return 0;
}
