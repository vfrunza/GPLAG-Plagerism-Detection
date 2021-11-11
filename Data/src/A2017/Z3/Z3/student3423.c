#include <stdio.h>
#include <math.h>
#include<stdbool.h>

int izbaci(int broj,int duzina){

	int pomocni=0,c=0,b=0,k=0;
	

	while(broj>0)
	{
			c=broj%10;
			broj/=10;
			if(c!=duzina){
				pomocni=pomocni+pow(10,k)*c;
				k++;
			}
		
	}
	
	
	
	return pomocni;
	
	
}

bool provjera(int niz[], int duz){
	int i =0, j=0;
	for(i=0; i<duz; i++)
	{
		if(niz[i]>9 || niz[i]<0)
		return true;
		
	}
	
	for(i=0; i<duz; i++)
	{
		for(j=0; j<duz; j++)
		{
			if(niz[i]==niz[j] && i!=j)
			return true;
		}
		
	}
	
	return false;
}

bool  izbaci_cifre (int *niz1, int duz1, int niz2[], int duz2){
	
		if(provjera(niz2,duz2)==true)
			return false;
	
	int i, j=0;
	int cifra=0, broj=0, temp=0, brojac=0;
	int pokazivac=niz1;
	bool ispravno=false;
	bool negativan=false;
	
	
	for(i=0;i<duz1;i++){
		if(*niz1<0){
			negativan=true;
			*niz1*=-1;
		}
		
		ispravno=false;
		brojac=0;
		broj=*niz1;
		temp=*niz1;
		
		while(broj>0){
			
			ispravno=false;
			cifra=broj%10;
			broj/=10;
			
			for(j=0;j<duz2;j++){
				
				if(cifra==niz2[j]){
					
					ispravno=true;
					break;
					
				}
			
			}
			if(ispravno==true){
				
				*niz1=izbaci(*niz1,cifra);
				
			}
			
			brojac++;
		}
		
		
		if(negativan==true){
			
			*niz1*=-1;
			negativan=false;
			
		}
	
		niz1++;
	}
	return true;	
}




int main() {


	return 0;
}
