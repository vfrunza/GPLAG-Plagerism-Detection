#include <stdio.h>

int main() {
	
	int i,n,par;
	par=1;
	
	printf("Unesite n: ");
	scanf("%d",&n);
	
	for(i=n;i<n*n;i++){
		if(i%2==0){
			par=1;
			printf("%d ",i);
		}else{
			par=0;
		}
	}
	return 0;
}
