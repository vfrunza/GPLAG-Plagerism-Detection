#include <stdio.h>

int main(){
		int n, i, j;
		printf("Unesite broj N: \n");
		do{
			scanf("%d", &n);
			if(n%4==0 && n>=8)
					break;
			printf("Greska\n");
		}while (1);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i==j && i<n/2)
		      		{
		      			printf("\\");
		      		}
		    else if(i+j==(n/2)-1){
		    				printf("/");
		    }
				printf("\n");
			}
		    return 0;
			}
}
		   /*else if(i==0 && (j==n/2 || j==n-1))
		   					printf("+");
		    
		    else if((i==(n/2)-1) && (j==n/2 || j==n-1))
		   printf("+");
		    else if(i==n/2 && (j==0 || (j==n/2-1)))
		   printf("+");
		    else if(i==n-1 && (j==0 || (j==n/2-1)))
		    printf("+");
		   else if(i==0 && (j>n/2)&&(j<n-1))
		   printf("-");
		    else if((i==n/2-1) && (j>n/2)&&(j<n-1))
		   printf("-");
		    else if(i==n/2 && (j>0)&&(j<n/2-1))
		   printf("-");
		    else if(i==n-1 && (j>0)&&(j<n/2-1))
		   printf("-");
		   else if(j==n-1 && (i>0)&& (i<n/2-1))
		   printf("|");
		    else if(j==n/2 && (i>0)&& (i<n/2-1))
		   printf("|");
		    else if(j==0 && (i>n/2)&& (i<n-1))
		   printf("|");
		    else if((j==n/2-1) && (i>n/2)&& (i<n-1))
		   printf("|");
		   else if((i ==n - 1 -  n/ 4 || i == n - n/4)&&(j==n-1 -n/4 || j==n-n/4))
		   printf("+");
				else if((j==n-1 -n/4 || j==n-n/4)&&(i>n/2-1)&&(i<n-1-n/4)){
				printf("|");	
				}
				else if((j==n-1 -n/4 || j==n-n/4)&&(i>n-n/4))
				printf("|");	
				else if((i==n-1-n/4 || i==n-n/4)&&(j>n-n/4))
				printf("-");
				else if((i==n-1-n/4 || i== n-n/4)&&(j<n-1-n/4)&&(j>n/2-1))
				printf("-");
				
		   else
		   printf(" ");
			}
			printf("\n");
		}
		
		return 0;
}*/

























