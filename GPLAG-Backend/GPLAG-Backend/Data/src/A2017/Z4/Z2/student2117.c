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
int provjeri_duzine(char* s[], int niz[],int n)
{     
    int ispitivac = 0,brojacslova,brojac = 0,i;
        
    while (*s != '\0')
    {
        brojacslova = 0;
         
        for( i = 0 ;; i++)
        {   
            if( (*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
            {
            brojacslova++;
            s++;
            }
            else break;
        }
        
        if ( brojacslova == niz[brojac] ) ispitivac = 1;
        if ( brojacslova != 0 ) brojac++;
        s++;
    }
    if ( ispitivac == 1 ) return 1; else return 0; 
   

}

int main() {
   char string[100];
	   int i,dn,niz[1000];
	   printf("Unesi string: ");
	   unesi(string,100);
       printf("Unesi duzinu niza: ");
       scanf("%d",&dn);
       printf("Unesi niz: ");
       
       for(i=0; i < dn; i++)
       {
       	scanf("%d",&niz[i]);
       }
       
       printf("%d",provjeri_duzine(string,niz,dn));
	return 0;
}
