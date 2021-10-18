#include <stdio.h>

int main() 
{
double a[200][200],b[200][200];
int i,j,M,N,C,D,tmp=0;
	do
	
	{ 
	    printf ("Unesite sirinu i visinu matrice A: ");
	    scanf("%d %d",&M,&N);
	    if(M<1 || N<1 || M>100 || N>100)
	    {printf("Pogresan unos!\n");}
	}
	    while(M>100 || N>100 || N<1 || M<1);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++)
	{
	for(j=0;j<N;j++)
	{
	scanf("%lf",&a[i][j]);
	}
	
	}



   	do
	
	{ 
	    printf ("Unesite sirinu i visinu matrice B: ");
	    scanf("%d %d",&C,&D);
	    if(C<1 || D<1 || C>100 || D>100)
	    {printf("Pogresan unos!\n");}
	}
	    while(C>100 || D>100 || C<1 || D<1);
	
	printf("Unesite clanove matrice B:");
	for(i=0;i<C;i++)
	{
	for(j=0;j<D;j++)
	{
	scanf("%lf",&b[i][j]);
	}
	}

 
for(i=0;i<M-1;i++) {
	for(j=0;j<N-1-i;j++) {

        tmp=a[i][j];
        a[i][j]=a[j][M-i-1];
        a[j][M-i-1]=a[M-i-1][N-j-1];
        a[M-i-1][N-j-1]=a[N-j-1][i];
        a[N-j-1][i]= tmp;
	}
	
	
	
}
    

for(i=0;i<C-1;i++){
	for(j=0;j<D-1;j++){
		if(a[i][j]==b[i][j]){ printf(" DA\n"); break;}
		else{printf(" NE\n"); break;}
	}
}

		
	
	

	
	return 0;}
	
	
	
	
	
	
	
	
	
	
	
	
	
