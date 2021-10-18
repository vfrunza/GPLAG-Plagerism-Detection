#include <stdio.h>

int dva_od_tri1(int *niz, int n, int m)
{

    int i,j;

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {

            if(niz[i]==niz[j])
                printf("%d", i);
        }


    }
    return i;
}

int dva_od_tri2(int *niz, int n, int l)
{

    int i, k;

    for(i=0; i<n; i++) {
        for(k=0; k<l; k++) {

            if(niz[i]==niz[k])
                printf("%d", k);
        }
    }

    return k;
}

int dva_od_tri3(int *niz, int m, int l)
{

    int j,k;

    for(j=0; j<m; j++) {
        for(k=0; k<l; k++) {

            if(niz[j]==niz[k])
                printf("%d", j);
        }

    }

    return j;
}


int main()
{

    int i,j,k,n,m,l,niz[100];

    do {
        printf("Unesite duzinu prvog niza: ");

        scanf("%d",&n);


    } while(n<1 || n>100);

        for(i=0; i<n; i++) {
            scanf("%d", &niz[i]);
        }
    do {
        printf("Unesite duzinu drugog niza: ");

        scanf("%d",&m);


    } while(m<1 || m>100);

        for(j=0; j<m; j++) {
            scanf("%d", &niz[j]);
        }
    do {
        printf("Unesite duzinu treceg niza: ");

        scanf("%d",&l);


    } while(l<1 || l>100);

        for(k=0; k<l; k++) {
            scanf("%d", &niz[k]);
        }

    if(niz[i]== niz[j]){
        
        printf("%d", dva_od_tri1(n,m,i));
    }
    else if(niz[i]==niz[k]){
        
        printf("%d", dva_od_tri2(n,l,k));
    }
    else if(niz[j]==niz[k]){
        
        printf("%d", dva_od_tri3(m,l,j));
    }



    return 0;
}
