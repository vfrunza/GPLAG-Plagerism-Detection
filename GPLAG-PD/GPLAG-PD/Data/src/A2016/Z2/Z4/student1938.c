#include <stdio.h>

int main() {
	int m,n,i,j,k=0,t=1,c=1;
	double matrica[101][101]={0.};
	do{
		printf("Unesite M i N: ");
		scanf("%i %i",&m,&n);
		if(m>100 || m<1 || n>100 ||n<1)printf("Pogresan unos!\n");
	}
	while(m>100 || m<1 || n>100 ||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&matrica[i][j]);
		}
	}
	//				printf("j= %i i= %i k=%i \n",j,k,i);
	for(k=0;k<m-1;k++)
	{
		j=0;
			for(i=k;i<m;i++)
			{
				//printf("j= %i i= %i k=%i \n",j,i,k);
				//printf("%i %i\n",matrica[i][j],matrica[k][0]);
				if(matrica[i][j]!=matrica[k][0]){t=0;}
				//if(t==0){printf("Jbg nije: ");}
				j++;
				if(j>n-1)break;
			}}
			for(k=1;k<n;k++){
			i=0;
			for(j=k;j<n;j++)
			{
				//printf("j= %i i= %i k=%i \n",j,i,k);
				//printf("%i %i\n",matrica[i][j],matrica[0][k]);
				if(matrica[i][j]!=matrica[0][k]){t=0;}
				i++;
				if(i>m-1)break;
				
			}
	}
	if(t==0){printf("Matrica nije ni cirkularna ni Teplicova"); return 0;}
	else
	{
		for(i=1;i<m;i++)
		{
			if(matrica[i][0]!=matrica[i-1][n-1]){c=0;}
		}
		
	}
	if(c==1)printf("Matrica je cirkularna");
	else printf("Matrica je Teplicova");
	
	return 0;
}
