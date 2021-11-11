#include <stdio.h>

void unesi(char niz[], int velicina)
{
    char znak=getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak != '\n')
    {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

double to_dec(char a)
{
    return a-'0';
}

char* obuhvat (char niz[], double x1, double y1, double x2, double y2)
{
    char *p= niz, *pok, *prva;
    double eps=0.0001;
    int negativan=0;
    int ima_tacka=0;
    double x=0, y=0;
    int decimala=10;
    while(*p != '\0')
    {
        if(*p=='(')
        {
            prva=p;
            pok=p;
            p++;
            decimala=10;
            negativan=0;
            ima_tacka=0;
            while(*p!=',')
            {
                if(*p=='-')
                {
                    negativan=1;
                    p++;
                }
                if(*p=='.')
                {
                    ima_tacka=1;
                    p++;
                    if(*p== ',' || *p==')')
                    break;
                }
                if(ima_tacka==0)
                {
                    x*=10;
                    x+=to_dec(*p);
                }
                else
                {
                    x+=to_dec(*p)/decimala;
                    decimala*=10;
                }
                p++;
            }
            p++;
            if(negativan)
            x=-x;
            
            negativan=0;
            decimala=10;
            ima_tacka=0;
            while(*p!=')')
            {
                if(*p=='-')
                {
                    negativan=1;
                    p++;
                }
                if(*p=='.')
                {
                    ima_tacka=1;
                    p++;
                    if(*p == ',' || *p==')')
                    break;
                }
                if(ima_tacka==0)
                {
                    y*=10;
                    y+=to_dec(*p);
                }
                else
                {
                    y+=to_dec(*p)/decimala;
                    decimala*=10;
                }
                p++;
            }
            if(negativan)
            y=-y;
            
            if(x+eps<x1 || x-eps>x2 || y+eps<y1 || y-eps>y2)
            {
                p++;
                while(*p != '\0')
                {
                    *pok++=*p++;
                }
                *pok='\0';
                p=prva;
            }
            }
            x=0;
            y=0;
            p++;
        }
        p=niz;
        while(*p!='\0')
        {
            if(*p=='(')
            {
                while(*p!=')')
                p++;
            }
            if(*p==',' && p== niz)
            {
                pok=p;
                prva=p;
                while(*p==',')
                p++;
                while(*p!='\0')
                {
                    *pok++ = *p++;
                }
                *pok='\0';
                p=prva;
            }
            else if(*p== ',' && p!= niz)
            {
                prva=p;
                pok=p;
                while(*p == ',')
                p++;
                if(*p=='\0')
                {
                    *pok='\0';
                    break;
                }
                else
                {
                    if(pok!=p)
                    pok++;
                    if(*pok==',')
                    {
                        while(*p!='\0')
                        *pok++ = *p++;
                        *pok='\0';
                        p=prva;
                    }
                }
            }
            p++;
        }
        return niz;
    }
int main()
{
    char niz[100];
    int i=0;
    unesi(niz, 100);
    obuhvat(niz,-3,-3,3,3);
    
    i=0;
    while(niz[i]!='\0')
    {
        printf("%c", niz[i]);
        i++;
    }
    return 0;
}