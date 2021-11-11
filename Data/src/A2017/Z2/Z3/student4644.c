#include<stdio.h>

int main () {
    int n=0 , i , j , k , niz1[10]={} , niz2[10]={} , zvijezda;
    do {
        
        printf("Unesite broj tacaka: ");
        scanf("%d" , &n);
        
        if(n<=0 || n>10) 
        printf("Pogresan unos \n");
    }
    while (n<0||n>10);
    
    for(i=0 ; i<n ; i++) {
        printf("Unesite %d. tacku: " , i+1);
        scanf("%d %d", &niz2[i] , &niz1[i]);
        
        if(niz2[i]<0 || niz2[i]>=20 || niz1[i]<0 || niz1[i]>=20) {
            printf("Pogresan unos\n");
            i--;
        }
    }
    for(i=0 ; i<20 ; i++ ) {
        for(k=0 ; j<20 ; j++) {
            zvijezda=0;
            for(k=0 ; k<n ; k++) {
                if(i==niz1[k] && j==niz2[k]) {
                    printf("*");
                    zvijezda=1;
                    break;
                }
            }
        } if(zvijezda==0)
        printf(" ");
        
    }
    return 0;
}