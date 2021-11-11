#include <stdio.h>

void izbaci(char* s, int duz)
{
    while(*(s+duz))
    {
        *s=*(s+duz);
        s++;
    }
    *s=*(s+duz);
}

char* obuhvat(char* s, float x1, float y1, float x2, float y2)
{
    char *p=s, *q;
    int bilatacka, bioprvi, biopoc=0, pozitivan, decinula, vani=0, duz, izbacenjedan=0;
    float xkor, ykor, decimala=0;
    
    //Provjera stringa
    
    if(*p=='\0') return s;
    while(*p!='\0')
    {
        if(biopoc && *p!=',') return '\0';
        if(biopoc) p++;
        biopoc=1;
        if(*p!='(') return '\0';
        p++;
        bilatacka=0;
        bioprvi=0;
        if(*p==',') return '\0';
        while(*p!=',')
        {
            if(*p=='\0') return '\0';
            if((*p<'0' || *p>'9') && *p!='.')
            {
                if(*p!='-') return '\0';
                if(*p=='-' && bioprvi) return '\0';
            }
            if(*p=='.' && bilatacka) return '\0';
            if(*p=='.' && !bioprvi) return '\0';
            if(*p=='.') bilatacka=1;
            bioprvi=1;
            p++;
        }
        bilatacka=0;
        bioprvi=0;
        p++;
        if(*p==')') return '\0';
        while(*p!=')')
        {
            if(*p=='\0') return '\0';
            if((*p<'0' || *p>'9') && *p!='.')
            {
                if(*p!='-') return '\0';
                if(*p=='-' && bioprvi) return '\0';
            }
            if(bilatacka && *p=='.') return '\0';
            if(*p=='.' && !bioprvi) return '\0';
            if(*p=='.') bilatacka=1;
            bioprvi=1;
            p++;
        }
        p++;
    }
    
    biopoc=-1;
    p=s;
    
    //Trazenje tacaka van pravougaonika
    
    while(*p=='(')
    {
        duz=0;
        vani=0;
        
        //Ordedjivanje pocetka dijela stringa koji predstavlja trenutne koordinate
        
        biopoc++;
        if(!biopoc) q=p; else q=p-1;
        
        xkor=0;
        ykor=0;
        
        //Odredjivanje koordinata X tacke
        
        decimala=0;
        decinula=0;
        p++;
        duz++;
        
        pozitivan=1;
        if(*p=='-')
        {
            pozitivan=0;
            p++;
            duz++;
        }
        bioprvi=0;
        bilatacka=0;
        while(*p!='.' && *p!=',')
        {
            if(!bioprvi)
            {
                bioprvi=1;
                if(pozitivan) xkor=*p-'0'; else xkor=0-(*p-'0');
                p++;
                duz++;
            }
            else
            {
                xkor*=10;
                if(pozitivan) xkor+=*p-'0'; else xkor-=*p-'0';
                p++;
                duz++;
            }
        }
        if(*p=='.') bilatacka=1;
        p++;
        duz++;
        if(*p==',') decinula=1;
        if(bilatacka) bioprvi=0; else bioprvi=1;
        while(*p!=',' && bilatacka)
        {
            if(!bioprvi)
            {
                bioprvi=10;
                decimala=*p-'0';
                p++;
                duz++;
            }
            else
            {
                bioprvi*=10;
                decimala*=10;
                decimala+=*p-'0';
                p++;
                duz++;
            }
        }
        if(!decinula)
        {
            if(pozitivan) xkor+=(decimala/bioprvi); else xkor-=(decimala/bioprvi);
        }
        
        //Odredjivanje koordinata Y tacke
        
        decimala=0;
        decinula=0;
        if(bilatacka){p++; duz++;}
        pozitivan=1;
        if(*p=='-')
        {
            pozitivan=0;
            p++;
            duz++;
        }
        bioprvi=0;
        bilatacka=0;
        while(*p!='.' && *p!=')')
        {
            if(!bioprvi)
            {
                bioprvi=1;
                if(pozitivan) ykor=*p-'0'; else ykor=0-(*p-'0');
                p++;
                duz++;
            }
            else
            {
                ykor*=10;
                if(pozitivan) ykor+=*p-'0'; else ykor-=*p-'0';
                p++;
                duz++;
            }
        }
        if(*p=='.') bilatacka=1;
        p++;
        duz++;
        if(*p==')') decinula=1;
        if(bilatacka) bioprvi=0; else bioprvi=1;
        while(*p!=')' && bilatacka)
        {
            if(!bioprvi)
            {
                bioprvi=10;
                decimala=*p-'0';
                p++;
                duz++;
            }
            else
            {
                bioprvi*=10;
                decimala*=10;
                decimala+=*p-'0';
                p++;
                duz++;
            }
        }
        if(!decinula)
        {
            if(pozitivan) ykor+=(decimala/bioprvi); else ykor-=(decimala/bioprvi);
        }
        if(*p!='\0'){p++; duz++;}
        if(bilatacka && *p!='\0'){p++; duz++;}
        
        //Provjera jeli tacka u pravougaoniku
        if(xkor<x1 || xkor>x2 || ykor<y1 || ykor>y2) vani=1;
    
        //Izbacivanje iz stringa
        
        if(vani) 
        {
            if(!biopoc) biopoc=-1;
            izbacenjedan=1;
            izbaci(q, duz);
            p-=duz;
        }
    }
    if(*(p-1)==')' && *(p-2)==')') *(p-1)='\0';
    return s;
}

int main() {
    char a[100]="(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
	printf("%s", obuhvat(a, -3, -3, 3, 3));
	return 0;
}
