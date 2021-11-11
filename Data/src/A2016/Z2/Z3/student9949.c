#include <stdio.h>
int main () {
	int n, i, j, x[20], y[20];
	char mat[20][20];
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>10 || n<=0){
		printf("Pogresan unos\n");
	}} while(n<=0 || n>10);
	
	 for(i=0; i<20; i++){
    	for(j=0; j<20; j++){
    		mat[i][j]=' ';}}
	
	for(i=0; i<n; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x[i], &y[i]);
	if(x[i]<0 || x[i]>19 || y[i]<0 || y[i]>19){
	   	printf("Pogresan unos\n");
	    i--;
	} else { mat[y[i]][x[i]]='*'; }} 
   
    for(i=0; i<20; i++){
    	for(j=0; j<20; j++){
    		printf("%c", mat[i][j]);
    	} printf("\n");}
	   return 0;
}

