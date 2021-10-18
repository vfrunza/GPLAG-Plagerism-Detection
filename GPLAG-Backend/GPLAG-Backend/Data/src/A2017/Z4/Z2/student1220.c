#include <stdio.h>

#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int *niz, int velicina)
{
	int nije_slovo1=1;
	int broj_rijeci=0;
	int brojac_za_i=0;
	char* pocetak=s;
	int duzina_rijeci[100]={0};
	int i=0;
	

	while(*s!='\0')
	{
		{
		
		if (!(*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
		nije_slovo1=1;
		
		else if(nije_slovo1==1) {
		nije_slovo1=0;
		broj_rijeci++;
		}
		
	}
		
		s++;
	}
	


	s=pocetak;
	
	
	
	i=0;
	
	
	while(*s!='\0')
	{
		if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			duzina_rijeci[i]++;
			brojac_za_i=0;
			s++;
		}
	
		else {
			brojac_za_i++;
			if(brojac_za_i==1) {
				i++;
			}
			s++;
			
		}

	}

    
	for(i=0;i<velicina;i++) {
	if(duzina_rijeci[i]!=niz[i]) return 0;
} 
     
     
	
	return 1;

	
}

int main()
{
    char s[100];
    int niz[100];
    int i,y;
    int brojac=0;
 
    printf("Unesite neki tekst: ");
    unesi(s,100);
    
    printf("Unesite neki niz cijelih brojeva: ");
    for(i=0;i<100;i++)
    {
    	scanf("%d", &niz[i]);
    	if(niz[i]==-1)
    	break;
    	
    	brojac++;
    }
    
    y=provjeri_duzine(s, niz, brojac);
    
    printf("\n");
    printf("%d", y);
    
    
    return 0;
}



