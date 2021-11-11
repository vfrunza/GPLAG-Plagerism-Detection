#include <stdio.h>

int main() {
	int N,i,j,k,B,C;
	do{	printf("Unesite broj N: ");
		scanf("%d",&N);
		if( N==4 || N%4!=0 || N==0 )
		printf("Neispravno N!");
		printf("\n");}
        while(N<8 || N%4!=0);
B=(N/2)-1;
C=N/2-1;
for(i=0;i<N/2;i++)
{
for(j=0;j<(N/2);j++){
	if(i==j)
	printf("\\");
	else if(B==j){
	printf("/");
	B=B-1;}
		else printf(" ");
	}	
if(i==0 || i==C){
	printf("+");
	for(k=1;k<=C-1;k++)
	{printf("-");}
printf("+");}
else{printf("|");
	for(k=1;k<=C-1;k++) printf(" ");
	printf("|");
	
}
	printf("\n");
}
for(i=0;i<N/2;i++)
{for(j=0;j<N;j++)
{
	return 0;
}
