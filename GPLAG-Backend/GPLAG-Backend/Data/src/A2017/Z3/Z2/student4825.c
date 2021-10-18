#include <stdio.h>
#include <math.h>
void zaokruzi1(float *realni, int velicina)
{
    int i;
    for(i=0;i<velicina;i++) {
        realni[i]=roundf(realni[i]*10)/10;
    }
    
}

void preslozi(float *realni,int  velicina, int k)
{
zaokruzi1(realni,velicina);
int i,suma,j;   
float zamijeni;
int br=0;
int  cifra;






    
for(i=0;i<velicina;i++) {
suma=0;    
 cifra=(realni[i]*10); 
 if(cifra<0) {
     cifra=cifra*(-1);
 }
 
 
    do {
    
        suma=suma+(cifra%10);
        cifra=cifra/10;
        
    }while(cifra!=0);
    
   if(k>0 && k<=suma){
    j=i;       
   while(j>br) {
   	
        zamijeni=realni[j];
    realni[j]=realni[j-1];
    realni[j-1]=zamijeni;
    j--;
    }
    br++;
    
    
    
    
    
    
    
    
       }
   } 
}








int main() {
			


	
	return 0;
}


