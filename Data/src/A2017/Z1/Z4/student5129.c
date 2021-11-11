//#include <iostream>
//#include <cmath>
#include <stdio.h>

//using namespace std;

int main()
{
    int red, kolona, sirina, i, j, k;
    
    do
    {
        /*
        cout << "Unesite broj redova: " << endl;
        cin >> red;*/
        printf("Unesite broj redova: ");
        scanf("%d", &red);
        
    }while(red <= 0 || red > 10);
    
    do
    {
        /*
        cout << "Unesite broj kolona: " << endl;
        cin >> kolona;*/
        printf("Unesite broj kolona: ");
        scanf("%d", &kolona);
        
    }while(kolona <= 0 || kolona > 10);
    
    do
    {
        /*
        cout << "Unesite sirinu kolone: " << endl;
        cin >> sirina;*/
        printf("Unesite sirinu jedne kolone: ");
        scanf("%d", &sirina);
        
    }while(sirina <= 0 || sirina > 10);
    
    for(i = 0; i <= red; i++)
    {
        //cout << "+";
        printf("+");
        for(j = 1; j <= kolona; j++)
        {
            for(k = 1; k <= sirina; k++)
            {
                //cout << "-";
                printf("-");
            }
            //cout << "+";
            printf("+");
        }
        //cout << "\n";
        printf("\n");
        
        if(i < red)
        {
            for(k = 0; k < kolona * (sirina + 1) + 1; k++)
            {
                if(k == 0 || k % (sirina + 1) == 0) printf("|"); //cout << "|";
                else printf(" "); //cout << " ";
            }
            //cout << "\n";
            printf("\n");
        }
    }
    
	
	
	return 0;
}