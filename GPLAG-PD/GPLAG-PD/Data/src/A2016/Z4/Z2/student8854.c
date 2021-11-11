#include <stdio.h>

char* kodiraj(char* tekst, char* tablica)
{
    char* tmp=tekst;
    char* tmp1=tablica;
    int novi=1;
    int znakova=0;
    int i;
    int nizbrojaca[128]={{0}};
    int x=0;
    int max;
    
    /*Registrovanje broja ponavljanja karaktera u niz*/
    while(*tmp!='\0')
    {
        while(*tmp1!='\0')
        {
            if(*tmp1==*tmp)
            {
                novi=0;
                nizbrojaca[*tmp1]++;
                break;
            } else
            novi=1;
            tmp1++;
        }
        tmp1=tablica;
        if(novi==1) 
        {
            
            nizbrojaca[*tmp]++;
            znakova++;
        }
        tmp++;
    }
    
x=0;  
tmp1=tablica;

/*Sortiranje broja ponavljanja karaktera*/
for(x=0;x<=94;x++)
{
max=32;
for(i=32;i<=126;i++)
{
   if(nizbrojaca[i]>nizbrojaca[max])
   {

   max=i;
   }
}
  



*tmp1=max;
tmp1++;
*tmp1='\0';
nizbrojaca[max]=-1;
    
}


tmp=tekst;
tmp1=tablica;

/*Kodiranje*/
while(*tmp!='\0')
{
    tmp1=tablica;
    while(*tmp1!=*tmp)
    {
     tmp1++;   
    }
*tmp=126-(tmp1-tablica);
tmp++;

}

return tekst;
}
        
char* dekodiraj (char* tekst,char* tablica)
{
char* tmp=tekst;

while(*tmp!='\0')
{
    
*tmp=*(tablica+126-*tmp);
tmp++;

} 
return tekst;
}
                   
        
        
        
        
int main() {

char t[]="abcdefghijklmnopqrstuvwxyz";
char tab[100]="";
kodiraj(t,tab);
printf("'%s'", tab);

            
return 0;
}
