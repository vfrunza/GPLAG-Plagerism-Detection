#include <stdio.h>

int main () {
    int niz [100],i,velicina1=0,n=0, subst=0, brcfr=0,konacni_niz[100], brpojavljivanja,brojac,velicina2=0, temp=0, j=0;
    int cifre[1000]={0}; 
    
    printf ("Unesite velicinu niza: ");
    scanf ("%d", &n);
    printf ("Unesite clanove niza: ");
    for (i=0; i<n; i++)
    scanf ("%d", &niz[i]);
    
    for (i=0; i<n; i++) {
        if (niz[i]==0) {
            cifre[velicina1]=0;
            velicina1++;
        }
        subst=niz[i]; 
        brcfr=0;
    while (subst!=0) {
        cifre[velicina1]=subst%10;
        velicina1++;
        brcfr++;
        subst/=10;
    }
    for (j=0; j<brcfr/2; j++) {
        temp=cifre[velicina1-brcfr+j];
        cifre[velicina1-brcfr+j]=cifre[velicina1-j-1];
        cifre[velicina1-j-1]=temp; }
    }
   
    for (i=0; i<velicina1; i++) {
        brpojavljivanja=1; 
        j=i+1;
        while (cifre[i]==cifre[j]) {
            brpojavljivanja++;
            j++;
            if (j>=velicina1) break; }
            konacni_niz[velicina2]=cifre[i];
            velicina2++;
            konacni_niz[velicina2]=brpojavljivanja; 
            velicina2++;
            i=j-1;
        }
        printf ("Finalni niz glasi:\n");
        for (i=0; i<velicina2; i++) {
            printf ("%d %d ", konacni_niz[i], konacni_niz[i+1]);
            i++;
        }
    return 0;
}
    
    
