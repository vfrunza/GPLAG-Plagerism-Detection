#include <stdio.h>
#include <stdlib.h>
#define DUZINA 20

void ubaci_u_niz (int niz[], int n, int index, int clan) {
    int i;
    
    for(i=n; i>index; i--) {
        niz[i] = niz[i-1];
    }  
    niz[index] = clan;
}

int zbrojcifri (int a) {
    int  cifra=0;
    
    a = abs(a);
   
    while (a>0) {
        cifra += a%10;
        a = a/10;
    } 
        
    return cifra;
}
    
void ubaci (int niz[], int n) {
    int i;
    for (i=0; i<(2*n); i+=2) {
        ubaci_u_niz(niz, n+i/2, i+1, zbrojcifri(niz[i]) );
    }
}

int Fibonacci (int clan) {
    int a=1, suma=1, temp=1;

        while (clan>=suma) {
            if(clan==suma) 
                return 1;
        
            suma += a;
            a = temp;
            temp = suma;
        }
    return 0;
}

int izbaci (int niz[], int n) {
int i, j, vel=n, treba_li_izbaciti;

    for(i=0; i<vel; i++) {
        
        treba_li_izbaciti = Fibonacci(niz[i]);
        
        if(treba_li_izbaciti == 1 && i == (vel-1)) {
            vel--;
            return vel;
        }    
        
        if(treba_li_izbaciti) {
            for(j=i; j<vel-1; j++) {
                niz[j]=niz[j+1];
            }    
                i--;
                vel--;
        }
    }
    return vel;
}

int main() {
	
	int i, niz[DUZINA], vel_izbaci;

	
	printf("Unesite niz od 10 brojeva: ");
	
	for (i=0; i<10; i++){
	    scanf("%d", &niz[i]);
	}
	
/*	ubaci_u_niz(niz, 10, 3, 33);
	ubaci_u_niz(niz, 11, 3, 66);
	ubaci_u_niz(niz, 12, 3, 99);
	ubaci_u_niz(niz, 13, 13, 100);
	ubaci_u_niz(niz, 14, 0, 101);
	for(i=0; i<15; i++) {
	    printf("%d ", niz[i]);
	    return 0;
	} */
	
	
	ubaci(niz,10);
	
	vel_izbaci = izbaci(niz,20);
	
	printf("Modificirani niz glasi:");
	
	for(i=0; i<(vel_izbaci); i++) {
	    if(i==vel_izbaci-1) {
	        printf(" %d.", niz[i]);
	        return 0;
	    }
	    printf(" %d,", niz[i]);
	}
	
	
	
	return 0;
}
