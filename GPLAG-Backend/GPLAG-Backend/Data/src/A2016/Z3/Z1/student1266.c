#include <stdio.h>
int jelprost(int prost_br)
    {
    	int i,ind=1,rezultat;
    	for(i=2;i<prost_br;i++)
    	   {
    	   	if (prost_br%i==0)
    	   	   {
    	   	   	ind=0;
    	   	   	break;
    	   	   }
    	   }
    	if(ind==1)
    	  rezultat=1;
    	else
    	  rezultat=0;
    	  return rezultat;
    }
int daj_prost()
    {
    	static int prost_br=2;
    	while (jelprost(prost_br)==0)
    	      {
    	      	prost_br++;
    	      }
    	prost_br++;
    	return prost_br-1;
    }
int main() {
    int i,A,B,prost,suma=0;
    do{
        printf ("Unesite brojeve A i B: ");
        scanf("%d %d", &A, &B);
        if (A>=B)
            printf ("A nije manje od B.\n");
        else if(A<=1)
            printf("A nije prirodan broj.\n");
        else if (B<=1)
            printf("B nije prirodan broj.\n");
      } 
    while (A<=1 || B<=1 || A>=B);
    
    
    while ((prost=daj_prost())<=A)
          suma=0;
    for (i=A+1;i<B;i++)
        {
            if(prost>=B)
               break;
            suma+=prost;
            prost=daj_prost();
        }
    printf ("Suma prostih brojeva izmedju %d i %d je %d.\n", A,B,suma);    
     
	return 0;
}
