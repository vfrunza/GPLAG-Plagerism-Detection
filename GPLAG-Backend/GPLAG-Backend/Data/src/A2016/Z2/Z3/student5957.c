#include <stdio.h>
#define BR 20

int main() {
	int i=0,j=0,A=0,B=0,n=0,k=0,t=0,mat[20][20],m;
	char C='*';
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			mat[i][j]=0;
		}
	}
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>10 || n<1){
	do{
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
        	scanf("%d",&n);
		}while(n>10 || n<1);}
	
	for(i=0;i<n;i++){
	printf("Unesite %d. tacku: ",i+1);
	scanf("%d %d",&A,&B);
		if(A>19 || A<0 || B>19 || B<0)
		do{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
        	scanf("%d %d",&A,&B);
		}while(A>19 || A<0 || B>19 || B<0);
		for(j=0;j<BR;j++){
			for(m=0;m<BR;m++){
			 if(mat[m][j]!=C && m==A && j==B)
		         {
		         	k++;
		         	mat[A][B]=C;
		         	break;
		         }
				
			}
	//	printf("%c",mat[A][B]);
	}}
	for(i=0;i<BR;i++){
		for(j=0;j<BR;j++){
			if(mat[j][i]==C){
	//	printf("%c",mat[j][i]);
		printf("*");
			t++;	
			}
		
		else{
		printf(" ");}
	}
	if(t==k)
	return 0;
	
		printf("\n");
	}
	
	return 0;
}
