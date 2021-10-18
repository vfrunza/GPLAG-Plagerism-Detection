#include <stdio.h>


void ubaci(int ubaciNiz[], int size) {
    
   
    int i,grudva,sljedeci,prethodni,noviBroj=0;
    int pomocniNiz[20];
    
	for(i=0; i<size; i++) {
      pomocniNiz[i*2] = ubaciNiz[i]; 
      
      grudva = ubaciNiz[i];
      if(grudva<0){
      	grudva *= -1;
      }
     	while(grudva>0) {
                    prethodni = grudva % 10;
                    grudva = grudva/10;
                    sljedeci = grudva % 10;
                    grudva = grudva/10;
                    noviBroj = noviBroj + prethodni + sljedeci;
	     	}
	     	 pomocniNiz[i*2+1] = noviBroj;
	     	 noviBroj = 0;
	 }
	 	for(i=0; i<size*2; i++) {
     		 ubaciNiz[i] = pomocniNiz[i];
}
}

int izbaci(int izbaciNiz[], int size) {

	int i,j,k,broj1=1,broj2=0,Fibonacci;
    
  for(i=0; i<size; i++){
      for(j=0; j<42; j++){
          Fibonacci=broj1+broj2;
          broj1=broj2;
          broj2=Fibonacci;
        
          if(izbaciNiz[i] == Fibonacci)
          {
           for(k=i; k<size-1; k++){
             izbaciNiz[k] = izbaciNiz[k+1];
           }
           size--;
           i--;
           break;
          }
      }
      broj1=1;
      broj2=0;
     } 
    return size;	
  }
 


int main() {
	
	int size=10, i, nizCijelih[20];

	printf("Unesite niz od 10 brojeva: ");          
	for(i=0; i<10; i++) {
		 scanf("%d",&nizCijelih[i]);
	}
	
	ubaci(nizCijelih,size);
	int n = izbaci(nizCijelih,size*2);
	
	if(n==0){
		printf("Prazan niz.");
		return 0;
	}
	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++) {
	
		if(i==n-1){
			printf("%d.", nizCijelih[n-1]);
			return 0;
		}
		printf("%d, ", nizCijelih[i]);
	}
	return 0;
}

