#include <stdio.h>
#define MAX 100

int main() {
	
	int n=0, i=0, j=0;
	int niz[MAX]={0};
	int a;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	
	
	printf("Unesite clanove niza: ");
		for(i=0; i<n; i++) {
			scanf("%d,", &niz[i]);
			if(niz[i]<0 || niz[i]>100000) {
				printf("Ponovite unos!\n");
	i--;
		}
		}
		
	int pomniz[1000], k=0, br=0, brojac=0, vel2=0, niz2[1000]={0}, pom2[1000];
    for (i=0; i<n; i++) { //i < n
        a = niz[i];
        do {
            pomniz[k++]=a%10;
            a/=10;
        } while(a != 0);
    }
        
        for(j=k-1; j>=0; j--) {  //j >= 0
        	pom2[br++]=pomniz[j];
        	k=0;
        }

        for(i=1; i<=br; i++) {
            printf ("%d, ", pom2[i - 1]);
        	brojac=0;
        	k=i;
        	while(pom2[i]==pom2[k] && k<br && pom2[i]==pom2[i+1]) {
        		brojac++;
        		k++;
        		i++;
        	}
        }
    printf("\n------------\n%d %d", pomniz[i], br);
    
return 0;
}

