#include <stdio.h>

int main() {
	int i,j,n;
	do{
			printf("Unesite broj n: ");
	        scanf("%d",&n);
	         if(n>50 || n<=0)
            printf("Pogresan unos\n");
	 
			} while(n>50 || n<=0 );
			
			if(n==1) printf("***");
			else
			{

			
			 for(i=0;i<n;i++)

    {
        for(j=0;j<((n*4)-3);j++)

       {    
             
             if(i==j) printf("*");
             else if(i==2*n-2-j) printf("*");
             else if(i==j-2*n+2) printf("*");
             else if(i==4*n-4-j) printf("*");

             
           else
           printf(" ");
       }
       printf("\n");
      
    }
			}

	return 0;
}
