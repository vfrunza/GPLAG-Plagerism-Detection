#include <stdio.h>
#include <stdlib.h>

void ubaci (int *niz, int br_el_niz);
int izbaci (int *niz, int br_el_niz);

int main() {
    int niz[30],i,el_niz;
    printf("Unesite niz od 10 brojeva: ");
    
    for(i=0; i<10; i++)
        scanf("%d", &niz[i]);
        
    ubaci(niz, 10);
   el_niz = izbaci(niz, 20);
    
    printf("Modificirani niz glasi:");
    
    if(el_niz == 0)
        printf("Prazan niz.");
        
    else    
        for(i=0; i<el_niz; i++){
            if (i!=el_niz-1)
                printf(" %d,", niz[i]);
            
            else
                printf(" %d.", niz[i]);
        }
        
    return 0;
     
}

void ubaci (int *niz, int br_el_niz){
    int *p = niz, niz2[10]={0}, *q = niz2, temp;
    
    //kreiranje identičnog niza
    while(p < niz + br_el_niz){
        *q = *p;
        q++;
        p++;
    }
    
    q = niz2;
    p = niz;  //vraćanje na početak niza
    
    //ubacivanje novih članova
    while(q < niz2 + br_el_niz){
        *p = *q;
        
        temp = *p;
        *(p+1) = 0;
        
            while(abs(temp) > 0){
                *(p+1) += abs(temp%10);
                temp /= 10;
            }
            
     p += 2;
     q++;
    }
}

int izbaci (int *niz, int br_el_niz){
     int *p = niz, *q;
     int Fibonaci[46] = {0}, i; //46 član je max broj niza kojeg tip int može primiti
    
    Fibonaci[0] = Fibonaci [1] = 1;
    
    for (i=2; i<46; i++)
        Fibonaci [i] = Fibonaci [i-2] + Fibonaci [i-1];
        
    while(p < niz + br_el_niz){
        for(i=0; i<46; i++)
            if (*p == Fibonaci[i]){
                q=p;
                
                while(q < niz + br_el_niz-1){
                    *q = *(q+1);
                    q++;
                }
                
            br_el_niz--;
            p--;
            i = 46;
            }
            
        p++;
    }
    return br_el_niz;
}