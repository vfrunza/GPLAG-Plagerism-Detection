#include <stdio.h>



int main() {
	int n,i,j,k,l;
	do{
	printf("Unesite broj N djeljiv sa 4, veci ili jednak 8: ");
	scanf("%d", &n);
	}while(n%4!=0||n<8);
	for(i=0;i<n/2;++i){
		if(i<n/4){
			if(i==0){
		for(j=0;j<n;++j){
			if(i==j){
				printf("\\");
			}
			else if(j==n/2){
				printf("/");
			}
			else
				printf(" ");
			 if(j==n/2+1){
				printf("+");
			}
			else if(j==n-1){
				printf("+");
			}
			else
				printf("-");
		}
			
		}
		else{
			
		}
	}
	else{
		
	}
	
}
for(i=0;i<)
	printf("Zadaća 2, Zadatak 1");
	return 0;
}
