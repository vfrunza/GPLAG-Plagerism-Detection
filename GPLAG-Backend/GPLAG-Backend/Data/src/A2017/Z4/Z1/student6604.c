#include <stdio.h>
#include <math.h>
char* ubaci_broj (char* tekst, int broj)
{
	char * temp=tekst, char brojstr[100], *pocetak, *cuva, *spaja;
	int brojac=0, int x=broj, i, j=0;
	
	while(x!=0){
		brojac++;
		x=x/10;
	}
	
	for (i = brojac-1; i >= 0; i--) {
		brojstr[j]=(x/pow(10, i)+'0');
		j++;
	}
	brojstr[j]='\0';
	
	while (*tekst!=0) {
		razmak=0;
		while (*tekst!=' ') {
			tekst++;
			razmak=1;
		}
		cuva=tekst;
		
		if (razmak=1) {
			pocetak=++tekst;
			while (*tekst!=0) 
				tekst++;
			
			
			while (*brojstr!=0) {
				*tekst=*brojstr;
				tekst++;
				brojstr++;
			}
			*tekst='\0';
			kraj=tekst;
			tekst=cuva+brojac;
		}


		tekst++;
	}


	return temp;
}
int main()
{
	printf("Zadaća 4, Zadatak 1");
	return 0;
}
