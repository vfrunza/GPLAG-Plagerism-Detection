#include <stdio.h>
#define vBR 100

int main() {

int BR[vBR], Cif[100], pom[100], niz[1000], hist[1000];
int m=0, k, i, j, z, n;

printf("Unesite velicinu niza: ");
scanf("%d", &z);

printf("Unesite clanove niza: ");
for(i=0;i<z;i++){
    scanf("%d", &BR[i]);
}

for(i=0;i<z;i++){
    k=0;
    do{
        pom[k]=BR[i]%10;
        BR[i]=BR[i]/10;
        k++;
    }while(BR[i]>0);
 
 /*sad za cifre*/
    for(j=k-1;j>=0;j--){
        Cif[m]=pom[j];
        m++;
    }
}

j=0;

for(i=0;i<m;i++){
    n=1;
    while(i!=m-1 && Cif[i]==Cif[i+n]) {
        n++;
        if(i+n==m-1)
        {
            n++;
            break;
        }
    }
    niz[j]=Cif[i];
    hist[j]=n;
    i=i+n-1;
    j++;
}
 
printf("Finalni niz glasi:\n");
for(i=0;i<j;i++){
    printf("%d %d ",niz[i],hist[i]);
}
printf("\n");
return 0;
}
