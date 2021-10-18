#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *pok_n, int vel1, int *pok_c, int vel2){
    int *pok1=pok_n;
    int *pok2=pok_c;
    int *pok3;
    int broj, novibroj=0, n=1, x, na_pok2_je, na_pok3_je, minus=0;
    if(vel1==0 || vel2==0) return 1;
    while(pok2<pok_c+vel2){
        if(*pok2<0 || *pok2>9) return 0;
        pok3=pok2+1;
        while(pok3<pok_c+vel2){
            na_pok2_je=*pok2;
            na_pok3_je=*pok3; //nesto nece nako da poredi. ispitati sto
            if(na_pok2_je==na_pok3_je) return 0;
           pok3++;
        }
        pok2++;
    }
    pok2=pok_c;
    while(pok1<pok_n+vel1){
            if(*pok1<0){ *pok1=fabs(*pok1); minus=1;}
            broj=*pok1;
                while(pok2<pok_c+vel2){
                    if(*pok1<0){ *pok1=fabs(*pok1); minus=1;}
                    broj=*pok1;
                    novibroj=0;
                    while(broj!=0){
                        na_pok2_je=*pok2;
                        if(broj%10==na_pok2_je){broj=broj/10;}
                        else {
                            novibroj=novibroj+(broj%10)*n;
                            n*=10;
                            broj=broj/10;
                        }
                    }
                if(minus==1) novibroj=novibroj*(-1);
                minus=0;
                pok2++;
                n=1;
                *pok1=novibroj;
            }
        pok1++;
        pok2=pok_c;
    }
    return 1;
    
    
}

int main() {
//	printf("Zadaća 3, Zadatak 3");
    int brojevi[] = {25, 235, 1235, 252, 22552255};
int cifre[] = {2, 3, 5};
int i;
izbaci_cifre(brojevi, 5, cifre, 3);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
	return 0;
}
