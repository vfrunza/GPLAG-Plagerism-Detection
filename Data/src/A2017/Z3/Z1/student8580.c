#include <stdio.h>

int *obrisi_iste(int niz[], int *velicina) {
/*u nizu ostaju elementi po jedan za svaku vrijednost koja se nalazi u nizu*/
    int *p=niz;
    int i,j,k;
    for(i=0;i<*velicina-1;i++) {
        for(j=i+1;j<*velicina;j++) {
            if(niz[j]==niz[i]) {
                for(k=j;k<*velicina-1;k++) {
                    niz[k]=niz[k+1];
                }
                j--;
                (*velicina)--;
            }
        }
    }
/*vraca pokazivac sa pocetka niza*/
    return p;
}

int dva_od_tri(int niz1[], int v1, int niz2[], int v2, int niz3[], int v3) {
    int ponavlja=0,pom=0;
/*novi nizovi koji nemaju elemente koji se ponavljaju*/
    int *nov1=obrisi_iste(niz1, &v1), *nov2=obrisi_iste(niz2, &v2), *nov3=obrisi_iste(niz3, &v3);
/*pokazivaci na pocetak novih nizova*/
    int *a=nov1, *b=nov2, *c=nov3;
    int i,j,k;
    i=0;
    while(i<v1) {
        b=nov2;
        pom=0;
        j=0;
        while(j<v2) {
        /*prolazi svaki element u drugom nizu i provjerava da li postoje isti element u prvom i drugom nizu*/
            if(*a==*b) {
                pom=1;
                c=nov3;
                k=0;
            /*ako postoji isti element u drugom nizu provjerava da li postoji u trecem*/
                while(k<v3) {
                    if(*a==*c) {
                        pom=0;
                    }
                    c++;
                    k++;
                }
                if(pom==1) {
                /*ako postoji u prvom i drugom, a ne u trecem, onda vrijedi dva od tri pravilo*/
                    ponavlja++;
                }
            }
            b++;
            j++;
        }
        c=nov3;
        pom=0;
        j=0;
        while(j<v3) {
        /*prolazi svaki element u trecem nizu i provjerava da li postoje isti element u prvom i trecem nizu*/
            if(*a==*c) {
                pom=1;
                b=nov2;
                k=0;
            /*ako postoji isti element u trecem nizu provjerava da li postoji u drugom*/
                while(k<v2) {
                    if(*a==*b) {
                        pom=0;
                    }
                    b++;
                    k++;
                }
                if(pom==1) {
                /*ako postoji u prvom i trecem, a ne u drugom, onda vrijedi dva od tri pravilo*/
                    ponavlja++;
                }
            }
            c++;
            j++;
        }
        a++;
        i++;
    }
    a=nov1;
    b=nov2;
    c=nov3;
    i=0;
    while(i<v2) {
        c=nov3;
        pom=0;
        j=0;
        while(j<v3) {
        /*prolazi svaki element u trecem nizu i provjerava da li postoje isti element u drugom i trecem nizu*/
            if(*b==*c) {
                pom=1;
                a=nov1;
                k=0;
            /*ako postoji isti element u trecem nizu provjerava da li postoji u prvom*/
                while(k<v1) {
                    if(*b==*a) {
                        pom=0;
                    }
                    a++;
                    k++;
                }
                if(pom==1) {
                /*ako postoji u drugom i trecem, a ne u prvom, onda vrijedi dva od tri pravilo*/
                    ponavlja++;
                }
            }
            c++;
            j++;
        }
        b++;
        i++;
    }
    return ponavlja;
}

int main() {
	int niz1[4]={1,2,3,4}, niz2[4]={2,3,4,5}, niz3[4]={3,4,5,6};
	int v1=4, v2=4, v3=4;
	printf("%d",dva_od_tri(niz1, v1, niz2, v2, niz3, v3));
	return 0;
}