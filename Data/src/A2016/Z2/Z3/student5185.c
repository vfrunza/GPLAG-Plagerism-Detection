#include <stdio.h>
#define minTacka 0
#define maxTacka 19
#define maxBrojTacaka 10

int main() {
    int n, uslov, i, j, nizX[maxBrojTacaka], nizY[maxBrojTacaka], x, y, counter, temp, o; 
    counter = 0;
    uslov = 0;
    o = 0;
    temp = 0;
    
    while (uslov != 1)
    {
        printf("Unesite broj tacaka: ");
        scanf("%i", &n);
       
    
        if (n <= maxBrojTacaka && n > 0)
        {
            for (i = 0; i < n; i++) /*Takes in the data*/
            {
                printf("Unesite %d. tacku: ", i+1);
                scanf("%d %d", &x, &y);
             
                if ((x >= minTacka && x <= maxTacka) && (y >= minTacka && y <= maxTacka))
                {
                    nizX[i] = y;
                    nizY[i] = x;
                }
                else /*Error if code doesn't belong to the range*/
                {
                    printf("Pogresan unos\n");
                    i--;
                }
            }
            
            for (j = 0; j < 20; j++) /*Sorts the X array*/
            {
                for (i = 0; i < n; i++)
                {
                    if (nizX[i] == j)
                    {
                        temp = nizX[counter];
                        nizX[counter] = nizX[i];
                        nizX[i] = temp;
            
                        temp = nizY[counter];
                        nizY[counter] = nizY[i];
                        nizY[i] = temp;
                        
                        counter++;   
                    }
                }
            }
            
            
            for (j = 0; j < n; j++) /*Sorts the Y*/
            {
                for (i = 0; i < n-1; i++)
                {
                    if (nizX[i] == nizX[i+1])
                    {
                        if (nizY[i] > nizY[i+1])
                        {
                            temp = nizY[i];
                            nizY[i] = nizY[i+1];
                            nizY[i+1] = temp;
                        }
                    }
                }
            }
            
            for (i = 0; i < n-1; i++)
            {
                if (nizX[i] == nizX[i+1] && nizY[i] == nizY[i+1])
                {
                    for (j = i; j < n-i; j++)
                    {
                        
                        nizX[j] = nizX[j+1];
                        nizY[j] = nizY[j+1];
                    }
                    n--;
                    i--;
                }
               
            }
            
            
                    
            /*Kod za ispis*/
            
            counter = 0;
            for (i = 0; i < 20; i++)
            {
                for (j = 0; j < 20; j++)
                    {
                        if (counter < n)
                        {
                        if (i == nizX[counter] && j == nizY[counter])
                        {
                            printf("*");
                            counter++;
                        }
                        else
                        {
                            printf(" ");
                        }
                        }
                        if (counter >= n)
                        {
                            o = 1;
                            break;
                        }
                    }
            /*
            for (i = 0; i < n; i++)
             {
                 printf("%i %i", nizX[i], nizY[i]);    
             }*/         
                    printf("\n");
                    if (o == 1)
                    {
                        break;
                    }
                }
           
           
           uslov = 1; 
        }
        else /*If the user enters a value different from the spec range*/
        {
            printf("Pogresan unos\n");
        }
    }
     

    
    
	return 0;
}
