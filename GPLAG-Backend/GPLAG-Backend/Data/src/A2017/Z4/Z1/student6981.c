#include <stdio.h>


void unesi(char niz[], int velicina)
{
	
	char znak = getchar();
	if(znak == '\n') znak = getchar();
	
	int i=0;
	
	while(i<velicina-1 && znak != '\n')
	{
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	
	niz[i]='\0';
	
}

char* zamijeni1(char *s, char c) {
	
        int duzina = 1;
        char* prvi=s;
        char* kraj = s; 
        
        
        while (*kraj != '\0') kraj++;

        while (kraj != s+1) {
            *kraj= *(kraj-1) ;
            kraj--;
        }
        *kraj = c;
        s=prvi;s++;
        return s;

}

char* ubaci_broj (char *s,int broj){
	
	int cifra=9;
	char* pocetni=s; 	

	while(*s!='\0')                     
	{
		if(*s!= ' ' && *(s+1)==' ')
		{
		s++;

      
        
        
		if(*(s+1)!=' ')s=zamijeni1(s,' ');
		}
		
		s++;
			
	}
	
	return pocetni;
}

int main() {
    char tekst[100];
    printf("Unesite tekst: ");
   
    unesi(tekst, 100);
   
    printf("Nakon zamjene: %s", ubaci_broj(tekst,5));
    return 0;
}