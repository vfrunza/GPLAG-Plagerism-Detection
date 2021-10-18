#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void zaokruzi1(float *niz,int vel)
{
	int i;
	for(i=0;i<vel;i++)
	{
		niz[i]=(round(niz[i]*10))/10;                  //koristena je pomocna funkcija round iz bibliotele stdlib.h koja pomace pri zaokruzivanju decimalnih brojeva
		
		}
	
}
int suma_cifara(float broj)
{
	int broj1=broj*10;
	int cifra=broj1%10;
	int suma=0;                                        //funkcija racuna sumu cifara
	while(broj1!=0)
	{
		cifra=broj1%10;
		if(cifra<0) cifra=-cifra;
		suma=suma+cifra;
		broj1=broj1/10;
		
	}
	
return suma;	
}
void zamijeni(float *p1,float *p2)
{                                                        //funkcija mjenja vrijednosti 2 varijable
	float temp=*p1;
	*p1=*p2;
	*p2=temp;
	
}
void preslozi(float *niz,int vel,int k)
{
	int i,j,m,brojac=0;
	zaokruzi1(niz,vel);
	for(i=0;i<vel;i++)
	{
		if(suma_cifara(niz[i])<k)
		{
		for(j=i+1;j<vel;j++)	
		{
		if(suma_cifara(niz[j])>=k)	{                       //funkcija preslaze elemente niza
			
		for(m=j;m>brojac;m--)
		{
			
		zamijeni(&niz[m],&niz[m-1]);
			
			
		}
		
		brojac++;	
		}	
			
		}	
			
			
			
			
			
		
		}
		
		
		
		
		
	}
	
}
int main()
{ int i;
	double niz[]={15.8 ,78.1, 13.1 ,15.7, 9.2 };
	zaokruzi1(niz,5);
	for(i=0;i<5;i++)
	{
		printf("%g ",niz[i]);
		
	}
    
	return 0;
}



