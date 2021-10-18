#include <stdio.h>

int dva_od_tri (int niz1[],int vel1,int niz2[],int vel2, int niz3[], int vel3) {
    int i,j,k,brojac=0,brojac1=0,brojac2=0,brojac3=0;
    for (i=0;i<vel1;i++) {
        for(j=i+1;j<vel1;j++) {
            if (niz1[i]==niz1[j]) brojac1++;
        }
    }
    if (brojac1!=0) {
        for (j=0;j<vel2;j++){
            if (niz1[0]==niz2[j]) brojac2++;
        }
        for (k=0;k<vel3;k++) {
            if (niz1[0]==niz3[k]) brojac3++;
        }
        if ((brojac3!=0 && brojac2==0) || (brojac3==0 && brojac2!=0)) brojac++;
    }
    brojac2=0;
    brojac1=0;
    brojac3=0;
    for (i=0;i<vel1;i++) {
     for (j=0;j<vel2;j++) {
         if (niz1[i]==niz2[j]) brojac1++;
     }
     for (k=0;k<vel3;k++) {
         if (niz1[i]==niz3[k]) brojac2++;
     }
     if ((brojac1!=0 && brojac2==0) || (brojac1==0 && brojac2!=0)) brojac++;
     brojac1=0;
     brojac2=0;
     }
     for(i=0;i<vel1;i++) {
         for(j=0;j<vel2;j++) {
              if (niz1[i]==niz2[j]) brojac1++;
         }
     }
     if (brojac1==0) {
         for(j=0;j<vel2;j++) {
             for(k=0;k<vel3;k++) {
                 if (niz2[j]==niz3[k]) brojac2++;
             }
             if (brojac2!=0) brojac++;
             brojac2=0;
         }
     }
     brojac1=0;
     for (j=0;j<vel2;j++) {
         for (k=0;k<vel3;k++) {
             if (niz2[j]==niz3[k]) brojac1++;
         }
     }
     if (brojac1==0) {
         
          for(i=0;i<vel1;i++) {
             for(j=0;j<vel2;j++) {
                 if (niz1[i]==niz2[j]) brojac2++; 
             }
             if (brojac2 !=0) brojac++;
             brojac2=0;
         }
     }
     brojac1=0;
     
     
          return brojac;
}
           
int main () {
    int niz1[1000],niz2[1000],niz3[1000],vel1,vel2,vel3,i;
    printf("\nUnesite velicinu niza 1: ");
    scanf("%d",&vel1);
    printf("\nUnesite clanove niza 1: ");
    for(i=0;i<vel1;i++) {
        scanf("%d ",&niz1[i]);
    }

     printf("\nUnesite velicinu niza 2: ");
    scanf("%d",&vel2);
    printf("Unesite clanove niza 2: ");
    for(i=0;i<vel2;i++) {
        scanf("%d ",&niz2[i]);
    }
    
     printf("\nUnesite velicinu niza 3: ");
    scanf("%d",&vel3);
    printf("\nUnesite clanove niza 3: ");
    for(i=0;i<vel3;i++) {
        scanf("%d ",&niz3[i]);
    }
    
    printf("\nClan koji se ponavlja u dva od tri niza je: %d ", dva_od_tri(niz1,vel1,niz2,vel2,niz3,vel3));

    return 0;
}