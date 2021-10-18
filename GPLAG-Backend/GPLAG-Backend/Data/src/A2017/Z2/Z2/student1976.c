#include <stdio.h>

int main() {
    int A[100],B[1000],C[1000];
    int i,vel_niza,trenutni,pocetno,ponavljanja;
    float a;
    printf("Unesite velicinu niza: ");
    scanf("%d", &vel_niza);
    printf("Unesite clanove niza: ");
    for(i=0; i<vel_niza; i++)
    {
        scanf("%f", &a);
        if((a-(int)a)!=0) {i--; continue;}
        else A[i]=a;
    }
    int br=0,j;
    for(i=0; i<vel_niza; i++)
    {
        int br1=0;
	    while(A[i]!=0)
	    {
	        C[br1]=A[i]%10;
	        A[i]/=10;
	        br1++;
	   }
	   for(j=br1-1;j>=0;j--){
	       B[br]=C[j];
	       br++;
	   }
    }
    trenutni=B[0];
    printf("Finalni niz glasi: \n");
    for(i=0; i<br; i++)
    {
        ponavljanja = 0; 
        pocetno = i;
        while(i != br-1 && B[i] == B[i+1]){
            ponavljanja++;
            i++;
        }
        printf("%d %d ", B[i], ponavljanja+1); 
    }
	return 0;
}
