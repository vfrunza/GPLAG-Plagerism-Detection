#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre_iz_broja(int br,int cifre[],int br_c){
    int t=1,i,rezultat=0,postoji_u_ciframa,posljednja_cifra,negativan_broj=0;
    
    if(br<0){
        br*=-1;
        negativan_broj=1;
    }
    
    while(br>0){
        postoji_u_ciframa=0;
        posljednja_cifra=br%10;
        for(i=0;i<br_c;i++){
            if(posljednja_cifra==cifre[i]){
                postoji_u_ciframa=1;
                break;
            }
        } if(postoji_u_ciframa==0){
            rezultat+=posljednja_cifra*t;
            t=t*10;
        } br=br/10;
    } if(negativan_broj==0) return rezultat;
    if(negativan_broj==1) return -1*rezultat;
}

int izbaci_cifre(int niz[], int bel, int cifre[], int br_cif){
    int i,m=0,j;
    
    for(i=0;i<br_cif;i++){
        if(cifre[i]>9 || cifre[i]<0)
            return 0;
        
        
    for(j=i+1;j<br_cif;j++){
        if(cifre[i]==cifre[j]){
            return 0;
        }
    }
    
    while(m<bel){
        niz[m]=izbaci_cifre_iz_broja(niz[m],cifre,br_cif);
        m++;
    }
  } return 1;
}

int main () {
    int brojevi[]={123,456};
    int cifre1[]={1, 2, 3, 1};
    int cifre2[]={1, 2, 10, 4};
    int cifre3[]={1, 2, 3, -4};
    int i,rezultat;
    rezultat=izbaci_cifre(brojevi, 2, cifre1, 4);
    printf("%d",rezultat);
    rezultat=izbaci_cifre(brojevi, 2, cifre2, 4);
    printf("%d",rezultat);
    rezultat=izbaci_cifre(brojevi, 2, cifre3, 4);
    printf("%d",rezultat);
    cifre3[3]=4;
    rezultat=izbaci_cifre(brojevi, 2, cifre3, 4);
    printf("%d",rezultat);
    printf("%d %d",brojevi[0],brojevi[1]);
}












