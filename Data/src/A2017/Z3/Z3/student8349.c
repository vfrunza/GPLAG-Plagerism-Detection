#include <stdio.h>
#include <math.h>
int izbaci_cifre (int *niz1,int velicina_niza1,int *niz2,int velicina_niza2)
{
    int i,j,k,m;
    for(i=0; i<velicina_niza2; i++) {
        for(j=0; j<velicina_niza2; j++) {
            if(niz2[j]<0 || niz2[j]>9)
                return 0;
            if(niz2[j]==niz2[i] && i!=j) return 0;
        }
    }
    for(k=0; k<velicina_niza1; k++) {
        int br=0;
      int clanovi_drugog_niza=fabs(niz1[k]);
        do {
            clanovi_drugog_niza=clanovi_drugog_niza/10;
            br++;
        } while (clanovi_drugog_niza!=0);
        br--;
        int clan=fabs(niz1[k]);
        int konacniniz=0;
        do {
            clanovi_drugog_niza=clan;
            clanovi_drugog_niza=clanovi_drugog_niza/pow(10,br);
            for (m=0; m<velicina_niza2; m++)
                if(clanovi_drugog_niza==niz2[m]) break;
            if(m==velicina_niza2) {
                konacniniz=konacniniz*10+clanovi_drugog_niza;
            }
            clan=clan-pow(10,br)*clanovi_drugog_niza;
            br--;
        } while(br>=0);
        if(niz1[k]<0)
            niz1[k]=-1*konacniniz;
        else
            niz1[k]=konacniniz;
    }
    return 1;
}
int main ()
{
    int niz1[100],niz2[100];
    int i,v,v1,rezultat;
    do{
        printf("Unesite velicinu nizova: ");
        scanf("%d %d",&v,&v1);
    } while((v<1 || v>100)&& (v1<1 ||v1>100));
    for(i=0;i<v;i++) {
        printf("Unesite %d. clan niza: ",i+1);
        scanf("%d",&niz1[i]);
    }
    printf("Unesite cifre niza: ");
    for(i=0;i<v1;i++) {
        scanf("%d",&niz2[i]);
    }
    rezultat=izbaci_cifre(niz1,v,niz2,v1);
    printf("%d",rezultat);
    return 0;
}