#include <stdio.h>

 /*funkcija koja sabira cifre elemenata niza*/

int zbir(int a){
	int sum=0, b;
	 if(a<0) a=a*(-1);
	  while(a>0){
	  	b=a%10;
	  	a=a/10;
	  	sum+=b;
	  }
	 return sum; 
}

 /*funkcija koja ubaciva nakon svakog elementa sumu njegovih cifara*/

void ubaci(int *pok, int a){
	int *j, b, c, temp;
        c=a;
	    for(j=pok+2*a-1;j>pok;j--){
		    if(j==pok+a-1){
			  temp=*(pok+2*a-2);
		      *(pok+2*a-2)=*(pok+a-1);
		      *(pok+a-1)=temp;
		      a--;
		    }
	    }
	
        for(b=0;b<c;b++){
              
               /*poziv funkcije zbir*/
                      	
        	  *(pok+2*b+1)=zbir(*(pok+2*b));  
        }
}

 /*funkcija koja izbacuje elemente koji pripadaju Fibonacijevom nizu*/

int izbaci(int *p, int a){
	int *i, *k, temp, j;
	int prvi, drugi, treci;
	    for(i=p;i<p+a;i++){
		    prvi=0;
		    drugi=1;
	        for(j=0;j<10000;j++){	
		        treci=prvi+drugi;
			    if(*i==treci){
				    for(k=i;k<p+a-1;k++){
					   temp=*k;
					   *k=*(k+1);
					   *(k+1)=temp;
				    }
		            a--;
		            i--;
		            break;
		        }
	            prvi=drugi;
	            drugi=treci;
	        }
        }
       
    /*funkcija vraca velicinu niza nakon izbacivanja elemenata*/   
        
    return a;  
}


int main() {
	int niz1[20]={0}, i, a, *j;
	int *p;
	    printf("Unesite niz od 10 brojeva: ");
	
	/*unos clanova niza*/
	
	    for(i=0;i<10;i++){
		    scanf("%d", &niz1[i]);
	    }
	
	/*pozivamo funkcije ubaci i izbaci*/
	
        p=&niz1[0];
        ubaci(p, 10);
	    a=izbaci(p, 20);
	
	/*ispis niza*/
	    
	    if(a==0){
	    	printf("0");
	        return 0;
	    }
	    
	    /*ispis ako niz ima jedan element*/
	    
        if(a==1){                                 
            printf("Modificirani niz glasi: ");
            printf("%d.", *p);
            return 0;
        }
        
        /*ispis ako niz ima vise od jednog elementa*/
        
        else {
            printf("Modificirani niz glasi: ");
	        for(j=p;j<p+a;j++){
		        if(j==p)printf("%d", *j);
		        else if(j==p+a-1)printf(", %d.", *j);
		        else printf(", %d", *j);
	    
	        }	
	        return 0;
        }
}
