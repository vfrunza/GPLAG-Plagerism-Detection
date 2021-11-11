#include <stdio.h>

int main() {
	
	int nizA[100],i,n,nizB[1000],brojac1=0,j,c,brojac_pon=0,temp;
	int brojaci[1001]={0},nizC[1000],niz[1000],broj=0;
	 
	do{
	    printf("Unesite velicinu niza: \n");
	    scanf("%d",&n);
	    printf("Unesite clanove niza: ");
	    for(i=n-1; i>=0; i--)
	        scanf("%d",&nizA[i]);
	        
	    
	    
	}while(n<=0 || n>100 && nizA[i]<=0);
	
	for(i=0; i<n; i++){
	do{     
            c = nizA[i] % 10;
            brojac1++;
             nizB[brojac1-1] = c; 
             nizA[i] = nizA[i] / 10;
		   
	    }while(nizA[i] != 0);
	   
	}

	for(j=brojac1-1; j>=0; j--){
	    	
	    	broj++;
	   	}
	
   for(i=0; i<brojac1; i++){
   	 for(j=i+1; j<1001; j++){
   	 if(nizB[i] == nizB[j]) brojaci[j]++;
   	 else if(nizB[i] != nizB[j]) brojaci[j]++; 
   	 else if(i == (brojac1-1)) brojaci[j]++;
   	 else if(niz[i] == 0) brojaci[j]++;
   	 break;
   	 }
   }
   	 
   
	for(j=brojac1-1; j>=0; j--){
		printf("%d %d ",nizB[j],brojaci[j]);
	}
	    
	 
      
      
  

	
	
     
	
	
	
	
	
	return 0;
}
