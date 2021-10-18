#include <stdio.h>
#include <stdlib.h>

void ubaci(int *pClan, int duz){
    
    int i, j, a, b, suma = 0, n = duz;
   
    for (i = 0; i < 2*duz; i += 2){
        
        a = *(pClan + i); 
    
        while(abs(a) > 0){
        
            b = a%10;
            suma += b;
            a = (a - b)/10;
        }
        
        /*Pomjeri sve elemente desno kako bi napravili prostora za novi*/
        for (j = n; j > i; j--){
            
            *(pClan + j) = *(pClan + j - 1);
            
        }
        
        *(pClan + i + 1) = abs(suma); /*ubaci sumu cifara ispred trenutnog broja*/
        
        n++; /*Uvecava se broj mjesta svaki put kad unesemo novi*/
        suma = 0; /*Reset sume*/
    }

}

int izbaci(int *pClan, int duz){
    
    int n = duz, a, b, broj, i, j;
    
    for (i = 0; i < n; i++){
        
        a = 0; b = 1;
        
        do{
            
            broj = a + b;
            
            if (*(pClan + i) == broj ){
                
                for (j = i; j < n - 1; j++)
                    *(pClan + j) = *(pClan + j + 1);
                
                i--;
                n--;
                break;
            }
            
            a = b;
            b = broj;
            
        } while (broj <= *(pClan + i)); /*Ako je trnutni fib broj veci od naseg, nas nije fib broj*/
    }
    
    return n;
    
}

int main() {
	
	int i, niz[200], d = 10; /*Samo za nas main slucaj, pocetna duzina je 10*/
	
	printf("Unesite niz od 10 brojeva: ");
	
	for (i = 0; i < d; i++)
	    scanf("%d", &niz[i]);
	    
    ubaci(&niz[0], d);
    d = izbaci(&niz[0], 2*d);
    
    printf("Modificirani niz glasi:");
    
    for (i = 0; i < d; i++){
        printf(" %d", niz[i]);
        
        if (i < d - 1)
            printf(",");
        if(i == d - 1)
            printf(".");
        
    }
	
	return 0;
}
