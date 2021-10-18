#include <stdio.h>


/*funkcija koja kada je pozovemo vraca svaki put sljedeci prost broj*/


int daj_prost (){
	static int i=1;
	int j, a;
	    do{ 
		    i++;
		    for(j=2;j<i;j++)
		    if(i%j==0) break;
	   
	   	   }while(i!=j);
    
        if(j==i) a=i;
    return a;
}

	

int main() {
	int A,  B,  i;
    int sum=0,  x;

	/* unos cijelih brojeva A i B*/
	
	    do{
		     printf("Unesite brojeve A i B: ");
	         scanf("%d %d",  &A,  &B);
	         if(A<=0) printf("A nije prirodan broj.\n");
	         else if (A>=B) printf("A nije manje od B.\n");
	         else if(B<=0) printf("B nije prirodan broj.\n");
	    
	       }while(A>=B || A<=0 || B<=0);
	
	/* racunanje sume prostih brojeva izmedju A i B*/
	
	    for(i=0;i<B;i++){
		    x=daj_prost();
		    if(A<x && B>x) sum+=x;
		}
	   
	    printf("Suma prostih brojeva izmedju %d i %d je %d.",  A,  B,  sum);
	return 0;
}
