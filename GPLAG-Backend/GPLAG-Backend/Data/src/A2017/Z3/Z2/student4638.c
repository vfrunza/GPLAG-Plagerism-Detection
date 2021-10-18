#include <stdio.h>
#include <math.h>

void zaokruzi1 (float *niz,int velicina_niza)
{
    float *p=niz;
    while (p<velicina_niza+niz) {
        *p=*p*10;
        *p=round(*p);
        *p++/=10;
    }
}

int saberiCifre(float clanNiza) {
    int sum = 0;
    if(clanNiza < 0) clanNiza = clanNiza * (-1);
    int noviClanNiza = clanNiza * 10;
    while(noviClanNiza != 0) {
        sum += noviClanNiza % 10;
        noviClanNiza = noviClanNiza / 10;
    }
    
    return sum;
}

void sastaviNizove(float prviNiz[], float drugiNiz[], int velicinaPrvogNiza, int velicinaDrugogNiza, int velicinaNiza) {
    float noviNiz[1000];
    int i, j = 0;
    
    for(i = 0; i < velicinaPrvogNiza; i++) {
        noviNiz[i] = prviNiz[i];
    }
    
    for(i = velicinaPrvogNiza; i <= velicinaDrugogNiza + 1; i++) {
        noviNiz[i] = drugiNiz[j];
        j++;
    }
    
    for(i=0; i<velicinaNiza; i++) {
       printf("%g ",noviNiz[i]);
    }
    
}

void preslozi (float niz[],int velicina_niza,int k)
{
    int i = 0;
    float nizVeceIliJednako[1000],nizManje[1000];
    int velicinaPrvogNiza = 0, velicinaDrugogNiza = 0;
    
    while(i < velicina_niza){
        int sum = saberiCifre(niz[i]);
        
        if(sum >= k){
            nizVeceIliJednako[velicinaPrvogNiza] = niz[i];
            velicinaPrvogNiza++;
        } else {
            nizManje[velicinaDrugogNiza] = niz[i];
            velicinaDrugogNiza++;
        }
        
        i++;
    }
    
    sastaviNizove(nizVeceIliJednako, nizManje, velicinaPrvogNiza, velicinaDrugogNiza, velicina_niza);

}


int main()
{
    int velicina_niza,k,i;
    float niz[100];
    printf("Unesite prirodan broj k: ");
    scanf("%d",&k);
    do {
        printf("Unesite velicinu niza: ");
        scanf("%d",&velicina_niza);
    } while(velicina_niza<1 || velicina_niza>100);
    for(i=0; i<velicina_niza; i++) {
        for(i=0; i<velicina_niza; i++) {
            printf("Unesite %d. clan niza:\n ",i+1);
            scanf("%f",&niz[i]);
        }
        zaokruzi1(niz,velicina_niza);
        
        for(i=0; i<velicina_niza; i++) {
            printf("%g ",niz[i]);
        }
        
        printf("\n");
        
        preslozi(niz,velicina_niza,k);
}
        return 0;
}

