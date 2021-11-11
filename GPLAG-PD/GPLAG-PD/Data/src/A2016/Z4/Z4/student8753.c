#include <stdio.h>

void dbr(char *p,char *k,float *x,float *y)
{
        char *q=p;
        int min;
        float a,b;
        
      *x=0;*y=0;
        
                while (q!=k)
                {
                        q++;min=0;
                        
                        if(*q=='-'){min=1;q++;}
                
                        *x=0;
                        while(*q>='0' && *q<='9')
                        {
                                *x=*x*10+(*q-'0');
                                q++;
                        }
                        if(*q=='.')
                        {
                                q++;a=0;
                                while(*q>='0' && *q<='9')
                                {
                                        a=a*10+(*q-'0');
                                        q++;
                                }
                                while(a>=1)
                                 a/=10;
                                *x=*x+a;
                        }
                        if(min==1) *x*=-1;
                        if(*q==',')q++;
                        min=0;
                        if(*q=='-'){min=1;q++;}
                        *y=0;
                        while(*q>='0' && *q<='9')
                        {
                                *y=*y*10+(*q-'0');
                                q++;
                        }
                        if(*q=='.')
                        {
                                q++;b=0;
                                while(*q>='0' && *q<='9')
                                {
                                        b=b*10+(*q-'0');
                                        q++;
                                }
                                while(b>=1)
                                 b/=10;
                                *y=*y+b;
                        }
                        if(min==1) *y*=-1;
                        
                }
                
        
}


char* obuhvat(char *s,float x1,float y1,float x2,float y2)
{
        char* q=s;
        char *p,*k,*i;
        float x,y;
        while(*q!='\0')
                { 
                        
                    if(*q=='(')
                        {
                          p=q;
                            while(*q!=')')q++;
                          k=q;
                        
                     dbr(p,k,&x,&y);
                        
                
                 if(x<x1 || x>x2 || y<y1 || y>y2)
                        {   
                       q++;
                     while(*q==',')q++;
                               i=q;
                                while(*i!='\0')
                                {
                                  *p++=*i++;
                                }
                                *p='\0';
                                q=q-(i-p);
                        }
                    }else q++;
                                
                }
                
            if(q!=s) q--;
                if(*q==',') *q='\0';
        return s;        
}




int main() {
        
        char s[] = "(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
        char* rez = obuhvat(s, -3, -3, 3, 3);
        printf("%s %s\n", rez, s);
        return 0;
}
