#include <stdio.h>
#include <stdlib.h>


int suma_cifara(int broj)
    {
        int suma=0;
        while(broj!=0){
            suma+=broj%10;
            broj/=10;
        }
        return abs(suma);
    }
void ubaci(int niz[], int br_el)
    {
        int i,j;
        for(i=0; i<br_el; i++){
            for(j=br_el; j>i+1; j--){
                niz[j]=niz[j-1];
            }
            niz[i+1]=suma_cifara(niz[i]);
            i++;
            br_el++;
        }
    }
int izbaci(int niz[], int br_el){
    int fibo[1000],i,j,k,t;
    fibo[0]=1;
    fibo[1]=1;
    for(t=2; t<1000; t++)
    {
        fibo[t]=fibo[t-1]+fibo[t-2];
    }
    for(i=0; i<br_el; i++){
        int nijeFibonaci = 0;
        for(j=0; j<1000; j++)
        {
            if(niz[i] == fibo[j])
            {
                nijeFibonaci = 1;
                break;
            }
        }
        if(nijeFibonaci == 1)
        {
            for(k=i; k<br_el-1; k++)
            {
                niz[k] = niz[k+1];
            }
            br_el--;
            i--;
        }
    }
    return br_el;
}
int main() {
    int niz[20],i;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++){
    scanf("%d",&niz[i]);
    }
    ubaci(niz, 10);
    int broj_el = izbaci(niz, 20);
    printf("Modificirani niz glasi:");
    for(i=0; i<broj_el-1; i++)
    {
        printf(" %d,",niz[i]);
    }
	printf(" %d.",niz[broj_el-1]);
	
	return 0;
}
