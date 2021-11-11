#include <stdio.h>

int main() {
	int broj_tacaka,brojac,n,m;
	char niz[20][20];
	
	
	
	printf("Unesite broj tacaka: ");
	scanf("%d", &broj_tacaka);
	while(broj_tacaka<1 || broj_tacaka>10)
{	printf("Pogresan unos\n");
	    
	    printf("Unesite broj tacaka: ");
	    scanf("%d", &broj_tacaka);
    
}
      for(n=0; n<20; n++)
      {
          for(m=0; m<20; m++)
      
      {
          niz[n][m]=' '; 
      }}
  
   for(brojac=0; brojac<broj_tacaka; brojac++)
   {
      	printf("Unesite %d. tacku: ", brojac+1);
       	scanf("%d",&n);
    	scanf("%d", &m);
        while(n<0 || m<0 || n>19 || m>19)
        {
        	
        printf("Pogresan unos\n"); 
        printf("Unesite %d. tacku: ", brojac+1);
        scanf("%d",&n);
        scanf("%d", &m);}
        niz[n][m]='*';
       }
        

        
        for(n=0; n<20; n++)
        {
           for(m=0; m<20; m++){
              printf("%c", niz[m][n]);
              
           }
            printf("\n");
          }
		return 0;
}
