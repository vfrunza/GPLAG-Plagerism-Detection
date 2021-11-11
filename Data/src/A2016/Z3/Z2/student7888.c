#include <stdio.h>
#include <math.h>
#include <stdlib.h>
                                       /* Funkcija za proširivanje niza */
    void ubaci(int *niz, int vel)   {
        
        int *p,*q,i,suma,a,b;
        p=q=niz;
                                      /* Dodjeljivanje vrijednosti upisanog člana niza na mjesto u nizu koje je indeksirano kao mjesto upisanog člana puta dva */
        for(i=vel-1; i>=0; i--) {
        *(q+(2*i))=*(p+i);
        
        }
        p=niz;
        
                                     /* Suma cifara prethodnog člana koja se dodjeljuje svakom drugom članu */
        for(i=0; i<2*vel; i++){
            suma=0;
            a=*(p+i);
            a=abs(a);
            while(a!=0){
                b=a%10;
                a/=10;
                suma+=b;
            }
            *(p+i+1)=suma;
            i++;
        }
    }
                                    /* Funkcija za fibonacijev niz */
    int fibniz(int n){
        int x,y,z;
        
                                    /* Ako je broj u funkciji manji od nule i jednak jedan on i nije član tog niza */
        if(n<0)return 0;
        if(n==1)return 1;
        x=1;
        y=1;
        while(1){
                                    /* Pošto fibonacijev niz predstavljaju članovi koji su suma prethodnih brojeva to predstavimo preko sume za varijablu z */
            z=x+y;
            if(n==z)return 1;
            else if(z>n)return 0;
            x=y;
            y=z;
        }
    }
                                    /* Funkcija za izbacivanje članova iz proširenog niza koji su članovi fibonacijevog niza */
    int izbaci(int *niz, int vel)   {
        
        int i,a,j,*p;
        p=niz;
        for(i=0; i<vel; i++)    {
                                    
                                    /* Varijabla a postaje vrijednost funkcije nad članom niza, te ukoliko je on prost vršimo izbacivanje tog člana iz niza */
            a=fibniz(*(p+i));
          
            if(a==1)    {
                for(j=i; j<vel-1; j++)  {
                    *(p+j)=*(p+j+1);
                }
                
                vel--;
                i--;
                
            }
        }
        
        return vel;
    }
    
    int main()  {
                                            /* Unos niza od 10 brojeva */
        int niz[20],i,vel=10,a;
            printf("Unesite niz od 10 brojeva:");
        for(i=0; i<vel; i++)    {
            scanf("%d", &niz[i]);
        }
        
                                            /* Poziv dvije funkcije */
         ubaci(niz,vel);
         a=izbaci(niz,2*vel);    
        
        
                                            /* Niz nakon poziva dvije funkcije */
        printf(" Modificirani niz glasi: ");
             for(i=0; i<a-1; i++)  {
                  printf("%d, ", niz[i]);
            
                 }
                  printf("%d.", niz[i]);
        
        return 0;
        
    }