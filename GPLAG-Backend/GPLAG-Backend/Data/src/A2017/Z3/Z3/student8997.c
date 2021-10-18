#include <stdio.h>
#include<math.h>

int izbaci_cifre(int *niz_brojeva,int velicina1, int *niz_cifara, int velicina2)
{
int i,j;
int cifra;
int clan1,clan2,brojac=0;




	for(i=0;i<velicina2;i++) {
			
	for(j=0;j<=i;j++) {
				if((niz_cifara[j]==niz_cifara[i] && i!=j) || niz_cifara[j]<0 || niz_cifara[j]>9) return 0;
	}
	}
	

 
 for(i=0;i<velicina1;i++) {
	brojac=0;
	clan2=0;
	clan1=fabs(niz_brojeva[i]);
	
		while(clan1!=0){
			clan1/=10;
			brojac++;
			
		}
		
		brojac--;
		
	
	
	
	
	clan1=fabs(niz_brojeva[i]); 
	do{
		cifra=clan1/(pow(10,brojac));
			
		for(j=0;j<velicina2;j++){
			if(cifra==niz_cifara[j]) break;
		}
		
	
		
		
		if(j==velicina2)
			clan2=(clan2*10)+cifra;
			
			clan1=clan1-(cifra*pow(10,brojac));
			brojac--;
		
		
	}while(brojac>=0);
	
	
	if(niz_brojeva[i]<0) niz_brojeva[i]=clan2*-1;
	else niz_brojeva[i]=clan2;
 }

	return 1;


}




int main() {
int brojevi[] = {25, 235, 1235, 252, 22552255};
int cifre[] = {2, 3, 5};
int i;
izbaci_cifre(brojevi, 5, cifre, 3);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
	
	return 0;
}









