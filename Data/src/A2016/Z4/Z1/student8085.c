#include <stdio.h>

int duzina(char *p)
{
	int brojac=0;
	while(*p!='\0')
	{
		brojac++;
		p++;
	}
	
	return brojac;
}

char* izbaci_najcescu(char* s)
{
    char *p1=s,*p2,*pomocni1,*pomocni2,*pomocni11,*pomocni12;
    int isti,brojIstih;
    int brojIstihMax=0,duzinaMax=0,i;
    char *pokNaMax=s;
   
    while(*p1!='\0'){
        
    brojIstih=0;
    while((*p1<'A' || *p1>'z') && (*p1!='\0'))
    {
        p1++;
    }
    if(*p1=='\0') return s;
    
    p2=p1;
    
    while(*p2>='A' && *p2<='z') p2++;
    
    if(duzinaMax==0) duzinaMax=p2-p1;
    
    pomocni1=p2;
    
        while(*pomocni1!='\0')
        {
             while((*pomocni1<'A' || *pomocni1>'z') && *pomocni1!='\0')
            {
                pomocni1++;
            }
            pomocni2=pomocni1;
            
            while(*pomocni2>='A' && *pomocni2<='z') pomocni2++;
        
            if(p2-p1 == pomocni2-pomocni1)
            {
                pomocni11=p1;
                isti=1;
                while(pomocni11!=p2)
                {
                    if(*pomocni11>='A' && *pomocni11<='Z')
                    {
                        if(*pomocni11!=*pomocni1 && *pomocni11+32 != *pomocni1) isti=0;
                    }else
                    {
                        if(*pomocni11!=*pomocni1 && *pomocni11-32 != *pomocni1) isti=0;
                    }
                    pomocni11++;
                    pomocni1++;
                }
                
                if(isti)
                {
                    brojIstih++;
                }
                
            }
            
            pomocni1=pomocni2;
        }
        
        if(brojIstih>brojIstihMax)
        {
            pokNaMax=p1;
            duzinaMax=p2-p1;
            brojIstihMax=brojIstih;
        }
        
        p1=p2;
  
    }
    
  
    p1=pokNaMax; p2=pokNaMax+duzinaMax;
    pomocni1=p2;
    
    while(*pomocni1!='\0')
        {
             while((*pomocni1<'A' || *pomocni1>'z') && *pomocni1!='\0')
            {
                pomocni1++;
            }
            pomocni2=pomocni1;
            
            while(*pomocni2>='A' && *pomocni2<='z') pomocni2++;
        
            if(p2-p1 == pomocni2-pomocni1)
            {
                pomocni11=p1; pomocni12=pomocni1;
                isti=1;
                while(pomocni11!=p2)
                {
                    if(*pomocni11>='A' && *pomocni11<='Z')
                    {
                        if(*pomocni11!=*pomocni1 && *pomocni11+32 != *pomocni1) isti=0;
                    }else
                    {
                        if(*pomocni11!=*pomocni1 && *pomocni11-32 != *pomocni1) isti=0;
                    }
                    pomocni11++;
                    pomocni1++;
                }
                
                if(isti)
                {
                    for(i=pomocni12-s;i<=duzina(s)-(p2-p1);i++)
                    {
                        s[i]=s[i+p2-p1];
                    }
                    pomocni2=pomocni12;
                }
                
            }
            
            pomocni1=pomocni2;
        }
    for(i=pokNaMax-s;i<=duzina(s)-duzinaMax;i++)
        {
            s[i]=s[i+duzinaMax];
        }
   
    return s;
}

int main() {
	char s[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("%s",izbaci_najcescu(s));
	return 0;
}
