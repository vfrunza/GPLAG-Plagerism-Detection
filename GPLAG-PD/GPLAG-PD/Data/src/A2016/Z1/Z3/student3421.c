#include <stdio.h>

int main() {
    
    int c=0, b=0,s=0,v=0,p=0, UBA;
    char slovo;
    float NPLB,PUD;
    printf("Unesite vozila: ");
    do {
    
        scanf("%c", &slovo);
        
        
        if('c'==slovo || 'C'==slovo) { c++; }
        else if ('b'==slovo || 'B'==slovo) {b++; }
        else if('s'==slovo || 'S'==slovo) {s++; }
        else if('v'==slovo || 'V'==slovo)  {v++; }   
        else if ('p'==slovo || 'P'==slovo) {p++;}
        else if('k'==slovo || 'K'==slovo) 
       { 
        break;
    }
    else
    {
        printf("Neispravan unos\n");
        continue;
    }

}
	while(slovo!='k' && slovo!='K');
	UBA=c+b+s+v+p;
	printf("Ukupno evidentirano %i vozila." ,UBA);
	
	if(b>=c && b>=s && b>=v && b>=p)
	{
	    NPLB=b;
	}
	if(c>=b && c>=s && c>=v && c>=p)
	{
	    NPLB=c;
	}
	if(s>=c && s>=b && s>=v && s>=p)
	{
	    NPLB=s;
	}
	if(v>=c && v>=b && v>=s && v>=p )
	{
	    NPLB=v;
	}
	if(p>=c && p>=b && p>=s && p>=v)
	{
	    NPLB=p;
	}
	if(UBA==0)  
	{PUD=0.0;
	    
	}
	else {
	    PUD=(NPLB/UBA)*100;
	}
	if(NPLB==b)
	{
	    printf("\nNajpopularnija boja je bijela (%.2f%%).", PUD);
	}
	else if
	(NPLB==c)
	{
	    printf("\nNajpopularnija boja je crna (%.2f%%).", PUD);
	}
	else if
	(NPLB==s)
	{
	    printf("\nNajpopularnija boja je siva (%.2f%%)." , PUD);
	}
	else if
	(NPLB==v)
	{
	    printf("\nNajpopularnija boja je crvena (%.2f%%)", PUD);
	}
	else if
	(NPLB==p)
	{
	    printf("\nNajpopuarnija boja je plava (%.2f%%).", PUD);
	}
	
	return 0;
}















