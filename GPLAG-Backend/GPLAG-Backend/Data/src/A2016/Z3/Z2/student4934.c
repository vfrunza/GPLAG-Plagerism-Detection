#include <stdio.h>
#include <math.h>
#include <stdlib.h>

    void ubaci(int *niz, int velicina)   {
        
        int *o;
        int *s;
        int i;
        int zbir;
        int x;
        int y;
        o=s=niz;
        /*postavljamo pokazivac na zadnje mjesto trenutnog niza*/ 
        for(i=velicina-1; i>=0; i--){
        *(s+(2*i))=*(o+i);
        
        }
        o=niz;
        /*racunamo sumu pomocu apsolutne vrijednosti*/
        for(i=0; i<2*velicina; i++){
            zbir=0;
            x=*(o+i);
            x=abs(x);
            do {
                y=x%10;
                x=x/10;
                zbir=zbir+y;
                /*u sljedeci clan upisujemo sumu*/
            } while (x!=0);
            *(o+1+i)=zbir;
            i++;
        }
    }
    /*trazimo Fibonacijev niz*/
    int Fibonacijev_niz(int m){
        int a;
        int b;
        int c;
        if(m<0)return 0;
        if(m==1)return 1;
        a=1;
        b=1;
        while(1){
            c=a+b;
            if(m==c)return 1;
            else if(c>m)return 0;
            a=b;
            b=c;
        }
    }
    /*izbacujemo brojeve Fibonacijevog niza iz ovog niza*/
    int izbaci(int *niz, int velicina)   {
        
        int i;
        int x;
        int j;
        int *o;
        o=niz;
        for(i=0; i<velicina; i++)    {
            x=Fibonacijev_niz(*(o+i));
          
            if(x==1){
                for(j=i; j<velicina-1; j++)  {
                    *(o+j)=*(o+j+1);
                }
                
                velicina--;
                i--;
            }
        }
        
        return velicina;
    }
    
    int main()  {
        
        int niz[20],i,velicina=10,x;
        printf("Unesite niz od 10 brojeva:");
        for(i=0; i<velicina; i++)    {
            scanf("%d", &niz[i]);
        }
        /*niz koji izbacujmo sadrzi i cifru koju
        unesemo i zbir cifara koje unesemo zato je 
        duzina niza je duplo veca od pocetnog niza*/
        ubaci(niz,velicina);
        x=izbaci(niz,2*velicina);    
        
        printf(" Modificirani niz glasi: ");
        for(i=0; i<x-1; i++)  {
            printf("%d, ", niz[i]);
            
        }
            printf("%d.", niz[i]);
        
        return 0;
        
    }
