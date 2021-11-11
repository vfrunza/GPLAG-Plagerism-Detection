#include <stdio.h>

int main()
{
    int k=0,n=0, red, kolona;
    
    while(k==0)
    {
        printf("\nUnesite broj n: ");
        scanf("%d", &n);
        if(n<=0 || n > 50)
        { 
            printf("Pogresan unos");
    
        }
        else if(n == 1)
        {
            printf("***");
            return 0;;
        }
        else
        {
            k++;
        }
    }
    for(red=1; red<=n; red++)
    {
        for(kolona = 1; kolona <= 4*n-3; kolona++)
        {
            if(kolona == red || kolona == (2*n-1)-(red-1) || kolona == (2*n-1)+(red-1) || kolona == (4*n-3)-(red-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
            printf("\n");
    }
	return 0;
}
