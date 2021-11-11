#include <stdio.h>

int main() {
//	printf("Zadaća 2, Zadatak 2");
    int n, i, niz1[100], niz2[1000], temp, br, a, cifra, j, brpon;
    do{
    	printf("Unesite velicinu niza: ");
        scanf("%d", &n);} while(n>=100 || n<=0); // || ako neki od uslova nije ispunjen idi opet, && ako jedan od uslova nije isp idi opet( kod do while)
    for(i=0; i<1000; i++){     //UVIJEK NA NULE DA N EBI BILO NEINC VR KAD GA POVECAVALA ZBOG PONAVLJANJA, I BORJACE ISTO
        niz2[i]=0;
    }
    
    printf("Unesite clanove niza: ");
    for(i=0; i<n; i++){
    	scanf("%d", &niz1[i]);
   // 	if(niz1[i]<0) i--;
    }
    br=0;
    for(i=n-1; i>=0; i--){
        a=niz1[i];
        while(a!=0){
            cifra=a%10;
            niz2[br]=cifra;
            br++;
            a=a/10;
        }
    }
    
  //  for(i=0; i<=br; i++){
     //   temp=niz2[i];
     //   niz2[i]=niz2[n-2];
     //   niz2[n-2]=temp;
   // }
    
 //   for(i=0; i<=br-1; i++){
 //       printf("%d, ", niz2[i]);
  //  }
  //  printf("br je %d", br);
    for(i=0; i<br/2; i++){
        temp=niz2[i];
        niz2[i]=niz2[br-i-1];
        niz2[br-i-1]=temp;
    }
    
  //  for(i=0; i<br; i++){
  //      printf("\n%d, ", niz2[i]);
  //  }
    brpon=0;
    for(i=0; i<br; i++){
        if(i==0) brpon=0; //beze da ne bi trazio za prvi predhodnika
        else if(niz2[i]==niz2[i-1]){ brpon++; 
        
             for (j=i; j<br-1; j++) {
             niz2[j] = niz2[j+1]; }
             br--;
             i--;
             }
         //izbacila tog sto se ponavlja
        else if(niz2[i]!=niz2[i-1]){ 
            
             for (j=br; j>=i; j--) {
             niz2[j] = niz2[j-1]; }
             niz2[i]=brpon+1;
             br++;
             i++;
            
            //UBACITI BROJ PON PREDHODNIKA ISPRED TOG; 
            brpon=0;}
        if(i==br-1){ 
            
            niz2[i+1]=brpon+1;
         //   br++;
        }
    }
    
    printf("Finalni niz glasi: \n");
    for(i=0; i<=br; i++){
        if(i==br) printf("%d", niz2[i]);
        else printf("%d ", niz2[i]);
    }
    
	return 0;
}
