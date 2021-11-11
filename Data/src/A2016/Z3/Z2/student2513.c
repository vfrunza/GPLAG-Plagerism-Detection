#include <stdio.h>
#include <stdlib.h>

/*Funkcija koja izracunava sumu cifara proslijedjenog broja*/
int suma (int n){
    int s=0;
    n=abs(n);
    while(n!=0){
        s=s+n%10;
        n=n/10;
    }
    return s;
}

/*Funkcija provjerava da li je njoj proslijedjeni broj fibonacijev*/
int fibonaci(int n){
    int a=1,b=1;
    while(a<n && b<n){
        a=a+b;
        b=a+b;
    }
    if(n==a || n==b) 
        return 1;
    else 
        return 0;
    
}

/*Funkcija koja izbacuje iz niza brojeva one brojeve koji su fibonacijevi */
int izbaci(int* niz, int vel){
    int i, j;
    for(i=0;i<vel;i++){
        if(fibonaci(niz[i])==1){
            for(j=i;j<vel-1;j++){
                niz[j]=niz[j+1];
            }
        i--;
        vel--;
        }
    }
    return vel;
}

/*Ubacivanje elemenata u niz jednakih sumi cifara odgovarajucih im prethodnih elementa*/
void ubaci(int* niz, int vel){
    int i,j;
    for(i=0; i<vel; i++){
        for(j=vel-1; j>i; j--){
            niz[j+1]=niz[j];
        }
            niz[i+1]=suma(niz[i]);
            vel++;
            i++;
    }

}

int main() {
    int niz[20],i,vel;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0;i<10;i++)
    scanf("%d",&niz[i]);
    ubaci(niz,10);
    vel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++){
        if(i==vel-1)
            printf("%d.",niz[i]);
        else
            printf("%d, ",niz[i]);
    }
    
	
	return 0;
}
