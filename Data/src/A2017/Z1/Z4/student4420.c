#include <stdio.h>

int main() {
	int i,j,r,k,sk,d,s;
	
	do{
		printf("Unesite broj redova: ");
		scanf("%d",&r);} while(r<1 || r>10);
	do{
		printf("Unesite broj kolona: ");
		scanf("%d",&k);} while(k<1 || k>10);
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sk);} while(sk<1 || sk>10);

	d=(r*2)+1; s=(sk*k)+k+1;
	
	for(i=0; i<d;i++){
		for(j=0;j<s;j++){
			if(i%2==0 && j%(sk+1)==0){
				printf("+");}
			else if(i%2==0 && j%(sk+1)!=0){
				printf("-");}
			else if(i%2!=0 && j%(sk+1)==0){
				printf("|");}
			else{
				printf(" ");}}
				printf("\n");}
	return 0;}