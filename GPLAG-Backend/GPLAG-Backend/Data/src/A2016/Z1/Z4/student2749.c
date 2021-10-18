#include <stdio.h>

int main() {
	int n,i;
	char a = '*';
	while(1){
		printf("Unesite broj n: ");
		scanf("%d",&n);
		if(n > 50 || n <= 0){
			printf("Pogresan unos\n");	
		}else break;
	}
	if(n == 1){
		printf("%c%c%c",a,a,a);
	}else{
		printf("%c %*c %*c\n",a,2*n-3,a,2*n-3,a);
		for(i = 2; i < n; i++){
			printf("%*c%*c%*c%*c\n",i,a,2*n-2*i,a,2*i-2,a,2*n-2*i,a);		
		}
		printf("%*c%*c",n,a,2*n-2,a);
	}
	return 0;
}
