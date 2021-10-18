#include <stdio.h>
#define BROJ_EL 100
#define BROJ_ELC 1000
int main() {
 
     int A[BROJ_EL],B[BROJ_ELC],velicina,clan,povecaj=0;
     int i,j,brojac,cifra=0,broj=0,m=0,br2=0;
     printf("Unesite velicinu niza: ");
     scanf("%d", &velicina);
     printf("Unesite clanove niza: ");
                                                     /*rastavljanje unesenih clanova na cifre*/
       
        for(i=0; i<velicina; i++) {
            scanf("%d", &clan);
            brojac=0;
            cifra=clan;
            while(cifra/10!=0)  {
                brojac++;
                cifra=cifra/10;
            }
                                                    /* +1 iz razloga sto je brojac na pocetku postavljen na nulu*/
            broj=brojac+1;
            
        while(clan/10!=0) {
            A[m+brojac]=clan%10;
            clan=clan/10;
            brojac--;
        }
        A[m+brojac]=clan;
        m=m+broj;
        }
                                                     /*Jos jedna petlja da protrcim kroz niz...ugh*/
        
        for(i=0; i<m; i++) {
            povecaj=0;
            for(j=i; j<m; j++) {
                if(A[j]==A[i]) 
                    povecaj++;
                else break;
            }                                           /*stvaranje konacnog niza*/
            
            B[br2]=A[i];
            B[++br2]=povecaj;
            br2++;
            i=i+povecaj-1;
        }
                                                                /*ispis*/
        printf("Finalni niz glasi:");
        printf("\n");
        for(i=0; i<br2; i++) {
             printf("%d ", B[i]);
             
        }
        
        
	return 0;
} 
