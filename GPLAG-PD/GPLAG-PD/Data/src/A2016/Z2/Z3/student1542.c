#include <stdio.h>

int main() {
	int n,i,j,z,A[10],B[10];
	char m[20][20];
		for(;;){
			printf("Unesite broj tacaka: ");
			scanf("%d", &n);
			if(n>10 || n<=0){
			printf("Pogresan unos\n"); continue;
			} 	
			else break;
			}
		
			for(z=0;z<n;z++){
			printf("Unesite %d. tacku: ",z+1);
			scanf("%d",&A[z]);
			scanf("%d", &B[z]);
			if(A[z]<0 || A[z]>19 || B[z]<0 || B[z]>19 ){
				printf("Pogresan unos\n"); 
				z--; continue;
			}
			}	
				for(i=0;i<20;i++)
					for(j=0;j<20;j++)
						m[i][j]=' ';
					
				for(z=0;z<n;z++){
					for(i=0;i<20;i++){
					for(j=0;j<20;j++){
					if(i==B[z] && j==A[z])
					m[i][j]='*';
					}
				}
				}	
					for(i=0;i<20;i++){
					for(j=0;j<20;j++){
						printf("%c", m[i][j]);
					}
					printf("\n");
					}
				
			
		return 0;
}
