#include <stdio.h>

int main()
{
    int niz1[100];
    int niz2[1000];
    int niz3[1000];
    int pomocni[11];
    int brcif;
    int velicina;
    int i,j;
    int brojac;
    int velicinapomocnog=0;
    int velicina3=0;
    int k;

    do {
        printf("Unesite velicinu niza: ");
        scanf("%d", &velicina);
    } while(velicina<1 || velicina>100);
    printf("Unesite clanove niza: ");
    for(i=0; i<velicina; i++) {
        scanf("%d", &niz1[i]);
    }

    for(i=0; i<velicina; i++) {
        j=0;
        if(niz1[i]==0){
            pomocni[j]=0;
            j=1;
        }
        while(niz1[i]!=0) {
            pomocni[j]=niz1[i]%10;
            niz1[i]/=10;
            j++;
        }

        brcif=j;
        for(j=brcif-1; j>=0; j--) {
            niz2[velicinapomocnog]=pomocni[j];
            velicinapomocnog++;
        }
    }
    k=0;
    for(i=0; i<velicinapomocnog; i++) {
        brojac=1;
        j=i;
        
            while(j<velicinapomocnog-1 && niz2[j]==niz2[j+1]) {
                j++;
                brojac++;
            }
        
        niz3[2*k]=niz2[i];
        niz3[2*k+1]=brojac;
        i+=brojac-1;
        velicina3+=2;
        k++;
    }
    printf("Finalni niz glasi: \n");
    for(i=0; i<velicina3; i++) {
        printf("%d ", niz3[i]);
    }






    return 0;
}
