#include <stdio.h>

int main() {
	int n,i,j;
	do{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if(n<8 || n%4!=0){
		printf("Neispravno N!");}
	printf("\n");
	} while(n<8 || n%4!=0);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		if(((i==1 && (j==n/2+1 || j==n)) || (i==n/2 && (j==n/2+1 || j==n))) || ((i==n/2+1 && (j==n/2 || j==1)) || (i==n && (j==1 || j==n/2)))){
			printf("+");}
		else if(((i==1 && (j>n/2+1 && j<n)) || (i==n/2 && (j>n/2+1 && j<n))) || ((i==n/2+1 && (j>1 && j<n/2)) || (i==n && (j>1 && j<n/2)))){
			printf("-");}
		else if(((j==n/2+1 && (i>1 && i<n/2)) || (j==n && (i>1 && i<n/2))) || ((j==1 && (i>n/2+1 && i<n)) || (j==n/2 && (i>n/2+1 && i<n)))){
			printf("|");}
		else if(i==j && j<=n/2 && i<=n/2){
			printf("\\");}
		else if(i+j==n/2+1){
			printf("/");}
		else if((i+j==n+n/2+1 && (j==n/2+n/4 || j==n/2+n/4+1)) || (i==j && (j==n/2+n/4 || j==n/2+n/4+1))){
			printf("+");}
		else if(((i>n/2 && i<n/2+n/4) || (i<=n && i>n/2+n/4+1)) && (j==n/2+n/4 || j==n/2+n/4+1)){
			printf("|");}
		else if(((j>n/2 && j<n/2+n/4) || (j<=n && j>n/2+n/4+1)) && (i==n/2+n/4 || i==n/2+n/4+1)){
			printf("-");}
		else{
			printf(" ");}}
			printf("\n");}
		
	
		
		
	return 0;
}
