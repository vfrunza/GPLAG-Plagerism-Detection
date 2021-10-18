#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int velicina)
{
	int i;
	for(i=0; i<velicina; i++) {
		niz[i]=round(niz[i]*10)/10;
	}

}

void preslozi(float niz[],int velicina,int k)
{
	int i,j;
	int temp,cifra;
	int suma=0;
	zaokruzi1(niz,velicina);
	for(i=0; i<velicina; i++) {
		temp=(int)(niz[i]*10);
		temp=0;
		do {

			cifra=temp%10;
			temp=temp%10;
			suma +=cifra;
		} while(temp!=0);

		
			if(suma>k) {
			int privremena=niz[k];
			niz[k]=niz[k+1];
			niz[k+1]=privremena;
			
		}
		
		}
		}

int main() {

    
	return 0;
}
