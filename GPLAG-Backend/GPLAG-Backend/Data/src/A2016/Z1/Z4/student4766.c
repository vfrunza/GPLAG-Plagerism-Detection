#include <stdio.h>
#include <math.h>


int main() {
	int n,i,j, x,num, working;
	working =1;
	x=1;
	
	while(working){
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if( n > 50 || n < 1 ){
		printf("Pogresan unos\n");
	}else{
		working =0;
	}
	}
	num = (4*n) -3;
	if(n==1){
		printf("***");
	}else{
	for (i=1; i <=n; i++){
		
		for (j=1; j<= num; j++){
			if(j==x || j== num/2+2 -x || j == num/2 +x  || j== num+1-x )
			printf("*");
			else
			printf(" ");
			
		}
		printf("\n");
		x+=1;
	}
	}
	
	return 0;
}
