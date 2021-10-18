#include <stdio.h>
int brojcifara(int broj)
{
    int clan=broj;
    int s=0;

    if(broj<0) clan=-broj;
    do {

        clan=clan/10;
        s++;
    } while(clan%10!=0 || clan/10!=0);

    if(broj>0) return s+1;
    else return s+2;
}
char* ubaci_broj (char* s, int broj)
{
    int cifra,clan=broj;
    int b=0;
    char* d=s;
    char *kraj;
    int p=0;
    int brojrijeci=0;
    int i=0;
    int a=0;
    int duz=brojcifara(broj);
    int duzina;
   
    a=0;
    while (*s != '\0') {
        p=0;
        i=0;
        b=0;
        a=0;
        duzina=duz;
        clan=broj;
        brojrijeci=0;
        while (*(s+i) != '\0') {
       if(*(s+i)!=' '){ if(a==0){
             a=1; brojrijeci++;
        } } else a=0;
        i++;
    }
        
        if (*s == ' ' &&  s!=d && *(s-1)!=' ' && brojrijeci!=0) {
            kraj = s;
            while (*kraj != '\0'){ kraj++;}
            if(*(s+1)==' ') {duzina--; b=1;}
            while (kraj > s) {
                *(kraj+duzina) = *kraj;
                kraj--;
                p=1;
            }
            *s=' ';
            *(s+duzina)=' ';
           if(b==0) s=s+duzina-1; else s=s+duzina;
        do {
			cifra=clan%10;
			clan=clan/10;
			if(cifra<0) cifra=-cifra;
		    *(s)=cifra+'0';
		    s--;
		} while(clan%10!=0 || clan/10!=0);
		if(broj<0) *s='-';
        }
        
        if(p==1){ if(b==0) s=s+duzina+1; else s=s+duzina+2;}
        else s++;
        
        
    }
        return d;
    
}
    int main()
    {
       char s[77] = "O    g";
printf("\"%s\"", ubaci_broj(s, 320));

        return 0;
    }
