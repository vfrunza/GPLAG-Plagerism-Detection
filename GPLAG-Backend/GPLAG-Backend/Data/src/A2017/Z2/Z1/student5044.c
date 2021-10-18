#include <stdio.h>

int main() {
	
	int n, temp = 0;
	int vel1, vel2, vel3, vel4, vel5;
	int i, j;
	
	do{
		if(temp>0){
		
		printf("Neispravno!\n");
		
		}
		
		printf("Unesite broj N: ");
		scanf("%d ", &n);
		temp++;
		
	}while(n<8||n%4!=0);
	
	vel1 = (n/2) + 1;
	vel2 = (n/4) + (n/2) + 1;
	vel3 = (n/4) + (n/2);
	vel4 = (n/2);
	vel5 = (n/4);
	
	for(i=1; i<=n; i++){
		
		for(j=1; j<=n; j++){
			
			if(i<=vel4&&j<=vel4){
				
				if(i==j&&i<=vel5&&j<=vel5){
					
					printf("\\");
					
				}else if(i+j==vel1&&i<=vel5&&j>vel5){
						
						printf("/");
					}else if(i==j&&i>vel5&&j>vel5){
						
						printf("\\");
					}else if(i+j==vel1&&i>vel5&&j<=vel5){
						
						printf("/");
					}else{
						
						printf(" ");
					}
				}

			if(i<=vel4&&j>vel4){
				
				if((i==j||i==vel4)&&(j==vel1||j==n)){
					
					printf("+");
					
				}else if((i==1||i==vel4)&&(j!=vel1&&j!=n)){
						
						printf("-");
						
					}else if((i!=1&&i!=vel4)&&(j==vel1||j==n)){
							
							printf("|");
						}else{
							
							printf(" ");
						}
						
					if(j==n){
						
						printf("\n");
					}
				}
				
				if(i>vel4&&j<=vel4){
					
					if((i==vel1||i==n)&&(j==1||j==vel4)){
						
						printf("+");
				}else if((i==vel1||i==n)&&(j=!1||j!=vel4)){
					
					printf("-");
					
					
				}else if((i!=vel1&&i!=n)&&(j==1||j==vel4)){
					
					printf("|");
				}else{
					
					printf(" ");
				}
				
				if(j==n){
					
					printf("\n");
				}
				}
				
				if(i>vel4&&j>vel4){
					
					if(i==vel3||i==vel2){
						
						if(j==vel3||j==vel2){
							
							printf("+");
						}else{
							
							printf("-");
						}
					if(i!=vel3&&i!=vel2){
						
						if(j==vel3||j==vel2){
							
							printf("|");
						}else{
							
							printf(" ");
						}
					
					}
					if(j==n){
						
						printf("\n");
					}
				}
				
			}
		}
		}
		
	return 0;
}
	
				

		


