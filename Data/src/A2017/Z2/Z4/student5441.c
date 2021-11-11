#include <stdio.h>

int main() {
	
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int i,j,k,p,tmp,miniA,miniB,miniC,minjA,minjB,minjC,M,N,Jbg;
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &M,&N);
	} 
		while(M<0 || N<0 || M>100 || N>100);
		printf("Unesite clanove matrice A: ");
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		scanf("%d",&A[i][j]);
		
		printf("Unesite clanove matrice B: ");
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		scanf("%d",&B[i][j]);
		
		printf("Unesite clanove matrice C: ");
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		scanf("%d",&C[i][j]);
		
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
		{
			miniA = i;
			minjA = j;
			miniB = i;
			minjB = j;
			miniC = i;
			minjC =j;
			Jbg=j;
			for(k=i;k<M;k++)
			for(p=Jbg;p<N;p++){
				if(A[k][p] < A[miniA][minjA])
				{miniA=k; minjA=p;}
				
				if(B[k][p] < B[miniB][minjB])
				{miniB=k; minjB=p;}
				
				if(C[k][p] < C[miniC][minjC])
				{miniC=k; minjC=p;}
			Jbg=0;}
			
			tmp=A[miniA][minjA];
			A[miniA][minjA]=A[i][j];
			A[i][j]= tmp;
			
			tmp=B[miniB][minjB];
			B[miniB][minjB]=B[i][j];
			B[i][j]= tmp;
			
			tmp=C[miniC][minjC];
			C[miniC][minjC]=C[i][j];
			C[i][j]= tmp;
		}
	}
	
		for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		if(A[i][j] != B[i][j] || A[i][j]!= C[i][j])
		{printf("NE"); return 0;}
		
		printf("DA");
		
	return 0;
}
