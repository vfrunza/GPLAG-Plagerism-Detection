#include <stdio.h>
char *ubaci_broj(char* tekst, int broj)
{
    int adr=tekst,djelioc=1,br=broj,neg=0;
    while(br>10)
    {
        djelioc=djelioc*10;
        br=br/10;
    }
    if(broj<0)
    {
        neg=1;
        broj=broj*(-1);
    }
    br=broj;
    while(*tekst!='\0')
    {
        if(*tekst==' ')
        {
            
            
            
            
            
        }
    }
    
    
    
}

int main() {
	
	return 0;
}
