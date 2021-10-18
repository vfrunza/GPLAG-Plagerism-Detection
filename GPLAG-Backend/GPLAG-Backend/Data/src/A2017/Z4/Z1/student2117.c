#include <stdio.h>
void unesi(char niz[], int velicina){
    char znak = getchar ();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!='\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
niz[i]='\0';
    }
char* ubaci_broj(char* tekst[], int broj)
{   
   while(*tekst != '\0')
    {
        if((*tekst >= 'A' &&  *tekst <= 'Z') || (*tekst >= 'a' || *tekst <='z'))
        {
			tekst++;
		}
		if(*tekst == ' ') 
		{
		    *tekst = broj;
		}
		tekst++;
    }
    return tekst;
}

int main() {
  char*tekst[100];
    int i;
    printf("Unesi string: ");
    unesi(tekst,100);
    printf("Unesi broj koji zelis ubaciti: ");
    scanf("%d", &i);
    
    
  
    printf("%c",ubaci_broj(tekst,i));
	return 0;
}
