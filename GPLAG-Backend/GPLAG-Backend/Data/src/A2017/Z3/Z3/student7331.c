#include <stdio.h>
#include<math.h>

int izbaci_cifre(int* niz1,int d1,int* niz2,int d2)
{
	int i,j,k,l;
	for(l=0;l<d2;l++)
	{
	for(k=0;k<d2;k++)
	{
	    if(niz2[k]<0 || niz2[k]>9) return 0;
	    if(niz2[k]==niz2[l] && l!=k) return 0;
	}
	}
	for(i=0;i<d1;i++)
	{
	    int brojac=0;
	    int cifre=fabs(niz1[i]);
	    
	    do{
	       cifre=cifre/10;
	       brojac++;
	       }while(cifre!=0);
	       
        brojac--;
        int cifra=fabs(niz1[i]);
        int novi=0;
        do
        {   cifre=cifra;
            cifre=cifre/pow(10,brojac);
            
            for (j=0;j<d2;j++)
            if(cifre==niz2[j]) break;
            if(j==d2)
            {
                novi=novi*10+cifre;
            }
            cifra=cifra-pow(10,brojac)*cifre; 
            brojac--;
        }while(brojac>=0);
       
        if(niz1[i]<0) niz1[i]=-1*novi;
         else niz1[i]=novi;
	} 
	return 1;
     
}
 int main()
 {
     return 0;
 }