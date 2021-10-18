#include <stdio.h>

int main() {
	int N, i, j;
	do{
	printf("Unesite broj N: ");
	scanf("%d", &N);
	if(N%4!=0 || N<8)
	printf("Neispravno N!");
	printf("\n");
	}
	while(N%4!=0 || N<8);
	for(i=0;i<N/2;i++){
		for(j=0;j<N/2;j++){
				if	(j==i){
				printf("\\");}
				else if(j==(N/2)-1-i){
				printf("/");}
				else{
				printf(" ");}	
		}
		for(j=N/2;j<N;j++){
			if(i==0 || i==(N/2)-1){
				if(j==N/2 || j==N-1){
				printf("+");}
				else {
				printf("-");}
		}
		else{
			if(j==N/2 || j==N-1){
				printf("|");}
			else{
				printf(" ");}
		}
	}
	printf("\n");
}
	for(i=N/2;i<N;i++){
		for(j=0;j<N/2;j++){
			if(j==0 || j==(N/2)-1){
				if(i==N/2 || i==(N-1)){
				printf("+");}
				else {
				printf("|");}
		}
		else{
			if(i==N/2 || i==(N-1)){
				printf("-");}
			else{
				printf(" ");}
		}
	}
		for(j=N/2;j<N;j++){
		if (j==((3*N)/4) || j==((3*N)/4)-1){
			if(i==((3*N)/4) || i==((3*N)/4)-1){
			printf("+");}
			else {
			printf("|");}
		}
	else {
			if(i==((3*N)/4) || i==((3*N)/4)-1 ){
				printf("-");}
			else{
				printf(" ");}
	}
}
		printf("\n");
}
	
	return 0;
}
