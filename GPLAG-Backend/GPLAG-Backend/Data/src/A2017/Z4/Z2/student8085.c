#include <stdio.h>


void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        
    }
    niz[i]='\0';
}

char LowerCase(char k)
{	
	if(k>='A' && k<='Z') k+=32;
	
	return k;
}




int DuzinaRijeci(char *poc)
{   
	int br=0;
	while(LowerCase(*poc)>='a' && LowerCase(*poc)<='z')
	{
		br++;
		poc++;
	}
	return br;
}


int DaLiJeRJ(char *tekst) {
	char *pok=tekst;
	int broj=0;   
	
	while(*pok!='\0') {

			if(LowerCase(*pok)>='a' && LowerCase(*pok)<='z')
 		    {
 		    broj++;
	 		pok+=DuzinaRijeci(pok);
 			}else pok++;
	}
	

return broj;

}

void ocisti() {
    char c;
    while((c = getchar()) != '\n');
}

int provjeri_duzine(char *s, int niz[],int vel) {
	
	int jeste=1;
	int br=0; 
	int i=0;
	char *pok=s;

  if(DaLiJeRJ(pok)!=vel) return 0;
 
 	while(*pok!='\0') 
 	{	
 		if(LowerCase(*pok)>='a' && LowerCase(*pok)<='z')
 		{
 			if(DuzinaRijeci(pok)!=niz[i]) jeste=0;
 			i++;br++;
 			pok+=DuzinaRijeci(pok);
 		}else pok++;
 		
 		
	}
	
return jeste;
}


int main() {



int a,b,i;
char tekst[100];
int niz[100];

printf("Uneiste string: ");
unesi(tekst,100);
ocisti();

printf("Unesite velicinu niza: ");
scanf("%d", &b);

printf("Uneiste niz brojeva: ");
for(i=0; i<b; i++) {
	scanf("%d", &niz[i]);
}

printf("%d", provjeri_duzine(tekst,niz,b));

return 0;
}
